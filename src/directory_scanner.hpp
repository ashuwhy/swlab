#pragma once
#include <string>
#include <vector>
#include <filesystem>

struct FileEntry {
    std::string name;
    bool isDirectory;
    std::string path;
    size_t size;
    std::filesystem::file_time_type lastModified;
};

class DirectoryScanner {
public:
    static std::vector<FileEntry> scanDirectory(const std::string& path);
    static std::string getRelativePath(const std::string& base, const std::string& path);
};
