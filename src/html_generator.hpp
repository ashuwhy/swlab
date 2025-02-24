#pragma once
#include "directory_scanner.hpp"
#include <string>
#include <vector>

class HtmlGenerator {
public:
    static void generateSite(const std::string& inputPath, const std::string& outputPath);
private:
    static std::string generateDirectoryPage(const std::string& path, const std::vector<FileEntry>& entries);
    static std::string readTemplate(const std::string& templateName);
    static std::string formatSize(size_t size);
};
