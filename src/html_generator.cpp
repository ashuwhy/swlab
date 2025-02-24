#include "html_generator.hpp"
#include <fstream>
#include <sstream>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

void HtmlGenerator::generateSite(const std::string& inputPath, const std::string& outputPath) {
    fs::create_directories(outputPath);
    
    // Copy CSS file
    fs::copy_file("templates/style.css", outputPath + "/style.css", 
                  fs::copy_options::overwrite_existing);
    
    auto entries = DirectoryScanner::scanDirectory(inputPath);
    std::string html = generateDirectoryPage(inputPath, entries);
    
    std::ofstream outFile(outputPath + "/index.html");
    outFile << html;
}

std::string HtmlGenerator::generateDirectoryPage(const std::string& path, 
                                               const std::vector<FileEntry>& entries) {
    std::stringstream ss;
    ss << readTemplate("templates/header.html");
    
    ss << "<div class='directory-list'>\n";
    ss << "<h2>Directory: " << path << "</h2>\n";
    
    // Add parent directory link if not in root
    if (path != "." && path != "./") {
        ss << "<p><a href='..'>📁 Parent Directory</a></p>\n";
    }
    
    ss << "<table>\n";
    ss << "<tr><th>Name</th><th>Type</th><th>Size</th></tr>\n";
    
    for (const auto& entry : entries) {
        ss << "<tr>";
        if (entry.isDirectory) {
            // Create a subdirectory and its index.html
            std::string subdir = entry.path;
            std::string relativeSubdir = DirectoryScanner::getRelativePath(".", subdir);
            auto subEntries = DirectoryScanner::scanDirectory(subdir);
            
            // Create subdirectory in docs
            std::filesystem::create_directories("docs/" + relativeSubdir);
            
            // Generate subdirectory page
            std::ofstream subFile("docs/" + relativeSubdir + "/index.html");
            subFile << generateDirectoryPage(subdir, subEntries);
            
            // Create link to subdirectory
            ss << "<td><a href='" << relativeSubdir << "'>📁 " << entry.name << "</a></td>";
        } else {
            ss << "<td>📄 " << entry.name << "</td>";
        }
        ss << "<td>" << (entry.isDirectory ? "Directory" : "File") << "</td>";
        ss << "<td>" << formatSize(entry.size) << "</td>";
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
