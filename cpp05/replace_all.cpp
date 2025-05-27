#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

bool endsWith(const std::string& str, const std::string& suffix) {
    return str.size() >= suffix.size() &&
           str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

void replaceInFile(const std::string& filePath, const std::string& oldWord, const std::string& newWord) {
    std::ifstream inFile(filePath);
    if (!inFile) {
        std::cerr << "Error: Could not open file " << filePath << std::endl;
        return;
    }

    std::string content;
    std::string line;
    bool modified = false;

    while (std::getline(inFile, line)) {
        size_t pos;
        while ((pos = line.find(oldWord)) != std::string::npos) {
            line.replace(pos, oldWord.length(), newWord);
            modified = true;
        }
        content += line + "\n";
    }
    inFile.close();

    if (modified) {
        std::ofstream outFile(filePath);
        if (!outFile) {
            std::cerr << "Error: Could not write to file " << filePath << std::endl;
            return;
        }
        outFile << content;
        outFile.close();
        std::cout << "Replaced all occurrences of \"" << oldWord << "\" with \"" << newWord << "\" in " << filePath << std::endl;
    }
}

void processDirectory(const std::string& directory, const std::string& oldWord, const std::string& newWord) {
    for (const auto& entry : fs::recursive_directory_iterator(directory)) {
        if (entry.is_regular_file()) {
            const std::string filePath = entry.path().string();
            if (endsWith(filePath, ".cpp") || endsWith(filePath, ".hpp")) {
                replaceInFile(filePath, oldWord, newWord);
            }
        }
    }
}

int main() {
    const std::string directory = "/home/abostano/Desktop/CPP-Modules/cpp05/ex00";
    const std::string oldWord = "Bureucrat";
    const std::string newWord = "Bureaucrat";

    processDirectory(directory, oldWord, newWord);

    return 0;
}