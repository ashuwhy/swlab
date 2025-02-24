#include "directory_scanner.hpp"
#include <filesystem>
namespace fs = std::filesystem;

std::vector<FileEntry> DirectoryScanner::scanDirectory(const std::string& path) {
    std::vector<FileEntry> entries;
    
    for (const auto& entry : fs::directory_iterator(path)) {
        FileEntry fileEntry;
        fileEntry.name = entry.path().filename().string();
        fileEntry.isDirectory = entry.is_directory();
        fileEntry.path = entry.path().string();
        fileEntry.size = entry.is_regular_file() ? fs::file_size(entry.path()) : 0;
        entries.push_back(fileEntry);
    }
    
    return entries;
}

std::string DirectoryScanner::getRelativePath(const std::string& base, const std::string& path) {
    fs::path basePath(base);
    fs::path fullPath(path);
    return fs::relative(fullPath, basePath).string();
}
