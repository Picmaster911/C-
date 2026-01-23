#pragma once
#define MYLIB_API
#include <filesystem>
#include <memory>
#include <vector>
#include <string>


namespace mylib {

    struct FileInfo {
        std::filesystem::path path;
        size_t size = 0;
        std::string extension;
    };

    class MyTypeOffExtetion; // forward

    MYLIB_API void listFileRecursive(
        const std::filesystem::path& dirPath,
        std::unique_ptr<MyTypeOffExtetion>& myTypeOffExtetion,
        std::vector<std::shared_ptr<FileInfo>>& files
    );

}
