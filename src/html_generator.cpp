#include "html_generator.hpp"
#include <fstream>
#include <sstream>
#include <filesystem>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <algorithm>

namespace fs = std::filesystem;

// Forward declaration for the internal recursive function.
namespace {
    void generateSiteRecursive(const std::string &inputPath,
                               const std::string &outputPath,
                               const std::string &globalOutputDir);
}

void HtmlGenerator::generateSite(const std::string& inputPath, const std::string& outputPath) {
    // Determine the global output directory name (e.g. "docs")
    std::string globalOutputDir = fs::path(outputPath).filename().string();
    generateSiteRecursive(inputPath, outputPath, globalOutputDir);
}

namespace {
    void generateSiteRecursive(const std::string &inputPath,
                               const std::string &outputPath,
                               const std::string &globalOutputDir) {
        // Create output folder for the current directory.
        fs::create_directories(outputPath);
        
        // Copy CSS file (only if not already present)
        if (!fs::exists(outputPath + "/style.css"))
            fs::copy_file("templates/style.css", outputPath + "/style.css", 
                          fs::copy_options::overwrite_existing);
        
        // Scan the current directory.
        auto entries = DirectoryScanner::scanDirectory(inputPath);
        
        // Generate HTML page for current directory.
        std::string html = HtmlGenerator::generateDirectoryPage(inputPath, entries);
        
        // Write index.html for the current directory.
        std::ofstream outFile(outputPath + "/index.html");
        outFile << html;
        outFile.close();
        
        // Recursively generate subdirectory pages.
        for (const auto& entry : entries) {
            if (entry.isDirectory) {
                // Skip if this folder is the designated output folder.
                if (entry.name == globalOutputDir)
                    continue;
                
                std::string subInput = entry.path;
                std::string subOutput = outputPath + "/" + entry.name;
                generateSiteRecursive(subInput, subOutput, globalOutputDir);
            }
        }
    }
}

std::string HtmlGenerator::generateDirectoryPage(const std::string& path, 
                                               const std::vector<FileEntry>& entries) {
    std::stringstream ss;
    ss << readTemplate("templates/header.html");
    
    // Add breadcrumb navigation using repo-relative paths
    ss << "<div class='breadcrumb'>\n";
    ss << "<a href='/swlab/'>root</a> / "; // Replace 'swlab' with your repo name
    
    std::string currentPath;
    std::istringstream pathStream(path);
    std::string segment;
    while (std::getline(pathStream, segment, '/')) {
        if (!segment.empty() && segment != ".") {
            currentPath += segment + "/";
            ss << "<a href='/swlab/" << currentPath << "'>" << segment << "</a> / ";
        }
    }
    ss << "</div>\n";
    
    ss << "<div class='directory-list'>\n";
    
    // Add parent directory link if not in root
    if (path != "." && path != "./") {
        ss << "<p><a href='/swlab/" << DirectoryScanner::getRelativePath(".", path) << "'><span class='file-icon'>📁</span>Parent Directory</a></p>\n";
    }
    
    ss << "<table>\n";
    ss << "<tr><th>Name</th><th>Type</th><th>Size</th><th>Last Modified</th></tr>\n";
    
    // Sort entries: directories first, then files, both alphabetically
    std::vector<FileEntry> sortedEntries = entries;
    std::sort(sortedEntries.begin(), sortedEntries.end(), 
        [](const FileEntry& a, const FileEntry& b) {
            if (a.isDirectory != b.isDirectory) {
                return a.isDirectory > b.isDirectory;
            }
            return a.name < b.name;
        });
    
    for (const auto& entry : sortedEntries) {
        ss << "<tr>";
        if (entry.isDirectory) {
            // Use repo-relative paths instead of filesystem paths
            std::string relativeSubdir = DirectoryScanner::getRelativePath(".", entry.path);
            ss << "<td><a href='/swlab/" << relativeSubdir << "'>"
               << "<span class='file-icon'>📁</span>" << entry.name 
               << "</a></td>";
        } else {
            // For files, link to GitHub's raw content
            ss << "<td><a href='https://github.com/ashuwhy/swlab/blob/main/" 
               << entry.path << "' target='_blank'>"
               << "<span class='file-icon'>📄</span>" << entry.name 
               << "</a></td>";
        }
        ss << "<td>" << (entry.isDirectory ? "Directory" : "File") << "</td>";
        ss << "<td>" << formatSize(entry.size) << "</td>";
        
        // Add last modified time (you'll need to add this to FileEntry)
        auto ftime = std::filesystem::last_write_time(entry.path);
        auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
            ftime - std::filesystem::file_time_type::clock::now() + 
            std::chrono::system_clock::now());
        std::time_t cftime = std::chrono::system_clock::to_time_t(sctp);
        ss << "<td>" << std::put_time(std::localtime(&cftime), "%Y-%m-%d %H:%M:%S") << "</td>";
        
        ss << "</tr>\n";
    }
    
    ss << "</table>\n</div>\n";
    ss << readTemplate("templates/footer.html");
    
    return ss.str();
}

std::string HtmlGenerator::readTemplate(const std::string& templateName) {
    std::ifstream file(templateName);
    std::stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

std::string HtmlGenerator::formatSize(size_t size) {
    if (size < 1024) return std::to_string(size) + " B";
    if (size < 1024*1024) return std::to_string(size/1024) + " KB";
    return std::to_string(size/(1024*1024)) + " MB";
}
