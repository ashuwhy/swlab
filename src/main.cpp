#include "directory_scanner.hpp"
#include "html_generator.hpp"
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include "httplib.h"

namespace fs = std::filesystem;

// Function to generate an HTML page for the given directory path
std::string generateDirectoryPage(const std::string& path) {
    std::stringstream ss;
    ss << "<html><head><title>File Browser</title>"
       << "<style>"
       << "body { font-family: Arial, sans-serif; padding: 20px; }"
       << "a { text-decoration: none; color: #0366d6; }"
       << "ul { list-style: none; padding: 0; }"
       << "li { margin: 5px 0; }"
       << "</style>"
       << "</head><body>";

    ss << "<h1>Browsing: " << path << "</h1><ul>";

    // Add a 'back' link if not at the root.
    fs::path currentPath(path);
    if (currentPath.has_parent_path() && currentPath != fs::path(".")) {
        fs::path parentPath = currentPath.parent_path();
        if (parentPath.string().empty())
            parentPath = ".";
        ss << "<li><a href=\"/browse?path=" << parentPath.string() << "\">&larr; Back</a></li>";
    }

    // List all directory entries.
    for (const auto& entry : fs::directory_iterator(path)) {
        std::string entryName = entry.path().filename().string();
        std::string entryPath = entry.path().string();
        if (entry.is_directory()) {
            ss << "<li>[DIR] <a href=\"/browse?path=" << entryPath << "\">" << entryName << "</a></li>";
        } else {
            // For files, link to a download endpoint so users can view or download them.
            ss << "<li>[FILE] <a href=\"/file?path=" << entryPath << "\" target=\"_blank\">" << entryName << "</a></li>";
        }
    }

    ss << "</ul></body></html>";
    return ss.str();
}

void startServer() {
    httplib::Server server;

    // Root endpoint redirects to /browse
    server.Get("/", [](const httplib::Request& req, httplib::Response& res) {
        res.set_redirect("/browse");
    });

    // Endpoint to display directory listings.
    server.Get("/browse", [](const httplib::Request& req, httplib::Response& res) {
        std::string path = req.has_param("path") ? req.get_param_value("path") : ".";
        try {
            std::string html = generateDirectoryPage(path);
            res.set_content(html, "text/html");
        } catch (const std::exception& ex) {
            res.status = 500;
            res.set_content("Error: " + std::string(ex.what()), "text/plain");
        }
    });

    // Endpoint to serve file content.
    server.Get("/file", [](const httplib::Request& req, httplib::Response& res) {
        std::string path = req.has_param("path") ? req.get_param_value("path") : "";
        if (path.empty()) {
            res.status = 400;
            res.set_content("Missing file path", "text/plain");
            return;
        }
        std::ifstream ifs(path, std::ios::binary);
        if (!ifs) {
            res.status = 404;
            res.set_content("File not found", "text/plain");
            return;
        }

        std::stringstream buffer;
        buffer << ifs.rdbuf();
        res.set_content(buffer.str(), "application/octet-stream");
    });

    std::cout << "File browser server running at http://localhost:8080" << std::endl;
    server.listen("0.0.0.0", 8080);
}

void generateStaticSite(const std::string& inputPath, const std::string& outputPath) {
    std::cout << "Scanning directory: " << inputPath << std::endl;
    std::cout << "Output directory: " << outputPath << std::endl;
    
    HtmlGenerator::generateSite(inputPath, outputPath);
}

int main(int argc, char* argv[]) {
    try {
        if (argc > 1 && std::string(argv[1]) == "--server") {
            startServer();
        } else {
            std::string inputPath = ".";
            std::string outputPath = "docs";
            
            // Parse command line arguments
            for (int i = 1; i < argc; i++) {
                std::string arg = argv[i];
                if (arg == "-o" && i + 1 < argc) {
                    outputPath = argv[++i];
                } else {
                    inputPath = arg;
                }
            }
            
            generateStaticSite(inputPath, outputPath);
        }
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
