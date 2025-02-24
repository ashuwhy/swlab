#include "directory_scanner.hpp"
#include "html_generator.hpp"
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    try {
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
        
        std::cout << "Scanning directory: " << inputPath << std::endl;
        std::cout << "Output directory: " << outputPath << std::endl;
        
        HtmlGenerator::generateSite(inputPath, outputPath);
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}
