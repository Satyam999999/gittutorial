#include <iostream>
#include <filesystem>
#include <map>

namespace fs = std::filesystem;

std::map<std::string, std::string> fileCategories = {
    {".jpg", "Images"}, {".png", "Images"},
    {".pdf", "Documents"}, {".docx", "Documents"},
    {".cpp", "Code"}, {".h", "Code"},
    {".zip", "Archives"}, {".rar", "Archives"}
};

std::string getCategory(const std::string& extension) {
    if (fileCategories.find(extension) != fileCategories.end()) {
        return fileCategories[extension];
    }
    return "Others";
}

void organizeFiles(const std::string& targetPath) {
    for (const auto& entry : fs::directory_iterator(targetPath)) {
        if (fs::is_regular_file(entry)) {
            std::string ext = entry.path().extension().string();
            std::string category = getCategory(ext);

            fs::path newDir = targetPath + "/" + category;
            fs::create_directories(newDir);

            fs::path newPath = newDir / entry.path().filename();
            fs::rename(entry.path(), newPath);

            std::cout << "Moved: " << entry.path().filename() << " → " << category << "\n";
        }
    }
}

int main(int argc, char* argv[]) {
    std::string path = (argc > 1) ? argv[1] : ".";
    try {
        organizeFiles(path);
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    return 0;
}
