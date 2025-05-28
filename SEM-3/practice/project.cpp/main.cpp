#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <chrono>
#include <ctime>

namespace fs = std::filesystem;

void createFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "Hello, this is a sample file.\n";
        file.close();
        std::cout << "File created: " << filename << "\n";
    } else {
        std::cerr << "Failed to create file: " << filename << "\n";
    }
}

void deleteFile(const std::string& filename) {
    if (fs::remove(filename)) {
        std::cout << "File deleted: " << filename << "\n";
    } else {
        std::cerr << "Failed to delete file: " << filename << "\n";
    }
}

void renameFile(const std::string& oldName, const std::string& newName) {
    try {
        fs::rename(oldName, newName);
        std::cout << "Renamed '" << oldName << "' to '" << newName << "'\n";
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Rename error: " << e.what() << "\n";
    }
}

void listFilesInDirectory(const std::string& path) {
    try {
        std::cout << "Files in directory '" << path << "':\n";
        for (const auto& entry : fs::directory_iterator(path)) {
            std::cout << "  - " << entry.path().filename() << "\n";
        }
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Directory error: " << e.what() << "\n";
    }
}

void fileMetadata(const std::string& filename) {
    if (fs::exists(filename)) {
        std::cout << "File size: " << fs::file_size(filename) << " bytes\n";

        // Manual conversion for macOS compatibility
        auto ftime = fs::last_write_time(filename);
        auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
            ftime - decltype(ftime)::clock::now() + std::chrono::system_clock::now()
        );
        std::time_t cftime = std::chrono::system_clock::to_time_t(sctp);
        std::cout << "Last modified: " << std::asctime(std::localtime(&cftime));
    } else {
        std::cerr << "File does not exist: " << filename << "\n";
    }
}

int main() {
    std::string filename = "sample.txt";
    std::string renamedFile = "renamed_sample.txt";

    createFile(filename);
    fileMetadata(filename);
    renameFile(filename, renamedFile);
    listFilesInDirectory(".");
    deleteFile(renamedFile);

    return 0;
}
