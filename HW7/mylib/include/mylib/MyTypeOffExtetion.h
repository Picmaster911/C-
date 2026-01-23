#pragma once
#include <vector>
#include <string>
#include <filesystem>
#include <cstdint>

namespace mylib {

    namespace fs = std::filesystem;

    enum class TypeExtension
    {
        EXE,
        TXT,
        PICTURE,
        OTHER
    };

    class MyTypeOffExtetion
    {
    private:
        std::uintmax_t _countOtherFile = 0;

        std::uintmax_t getSizeCollectionFile(const std::vector<std::string>& collection) const
        {
            std::uintmax_t totalSize = 0;

            for (const auto& item : collection)
            {
                if (fs::exists(item) && fs::is_regular_file(item))
                    totalSize += fs::file_size(item);
            }

            return totalSize;
        }

    public:
        std::vector<std::string> path_exe;
        std::vector<std::string> path_txt;
        std::vector<std::string> path_picture;
        std::vector<std::string> other_file;

        std::uintmax_t totalSize = 0;
        std::uintmax_t countAllFile = 0;

        std::uintmax_t GetCountOtherFile()
        {
            _countOtherFile = countAllFile
                - path_exe.size()
                - path_txt.size()
                - path_picture.size();
            return _countOtherFile;
        }

        std::uintmax_t GetSizeCollectionFile(TypeExtension typeExtension) const
        {
            switch (typeExtension)
            {
            case TypeExtension::EXE:     return getSizeCollectionFile(path_exe);
            case TypeExtension::TXT:     return getSizeCollectionFile(path_txt);
            case TypeExtension::PICTURE: return getSizeCollectionFile(path_picture);
            case TypeExtension::OTHER:   return getSizeCollectionFile(other_file);
            default: return 0;
            }
        }
    };

} // namespace mylib
