#include "directory_scanner.hpp"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

std::vector<FileEntry> DirectoryScanner::scanDirectory(const std::string& path) {
    std::vector<FileEntry> entries;
    
    // Get the absolute path of the output directory
    fs::path outputPath = fs::absolute("docs").lexically_normal();
    std::string outputStr = outputPath.string();
    
    for (const auto& entry : fs::directory_iterator(path)) {
        // Skip the output directory to prevent recursion
        fs::path entryPath = fs::absolute(entry.path()).lexically_normal();
        if (entryPath.string() == outputStr) {
            continue;
        }
        
        FileEntry fileEntry;
        fileEntry.name = entry.path().filename().string();
        fileEntry.isDirectory = entry.is_directory();
        fileEntry.path = entry.path().string();
        fileEntry.size = entry.is_regular_file() ? fs::file_size(entry.path()) : 0;
        fileEntry.lastModified = fs::last_write_time(entry.path());
        entries.push_back(fileEntry);
    }
    
    return entries;
}

std::string DirectoryScanner::getRelativePath(const std::string& base, const std::string& path) {
    fs::path basePath(base);
    fs::path fullPath(path);
    return fs::relative(fullPath, basePath).string();
}
