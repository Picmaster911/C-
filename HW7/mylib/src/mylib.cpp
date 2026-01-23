#include <mylib/mylib.hpp>
#include <mylib/MyTypeOffExtetion.h>
#include <iostream>

namespace mylib
{

    namespace fs = std::filesystem;

    void listFileRecursive(const fs::path& dirPath, std::unique_ptr<MyTypeOffExtetion>& myTypeOffExtetion, std::vector< std::shared_ptr<FileInfo>>& files)
    {
        for (fs::recursive_directory_iterator it(dirPath); it != fs::recursive_directory_iterator(); ++it)
        {
            const auto& entry = *it;

            std::shared_ptr<FileInfo> targetFile = std::make_shared<FileInfo>();

            if (entry.is_regular_file())
            {
                targetFile->extension = entry.path().extension().string();
                targetFile->path = entry.path();
                targetFile->size = entry.file_size();

                std::ranges::transform(
                    targetFile->extension,
                    targetFile->extension.begin(),
                    [](unsigned char c) { return static_cast<char>(std::tolower(c)); }
                );

                files.push_back(std::move(targetFile));
                myTypeOffExtetion->countAllFile++;
                myTypeOffExtetion->totalSize = myTypeOffExtetion->totalSize + entry.file_size();
            };

            if (entry.is_regular_file() && entry.path().extension() == ".exe")
            {
                myTypeOffExtetion->path_exe.push_back(entry.path().string());
                std::cout << "Add Extension = exe " << "Level depth -> " << it.depth() << std::endl;
            };

            if (entry.is_regular_file() && entry.path().extension() == ".txt")
            {
                myTypeOffExtetion->path_txt.push_back(entry.path().string());
                std::cout << "Add Extension = txt " << "Level depth -> " << it.depth() << std::endl;
            };

            if (entry.is_regular_file() && (entry.path().extension() == ".jpg"
                || entry.path().extension() == ".png" || entry.path().extension() == ".bmp"))
            {
                myTypeOffExtetion->path_txt.push_back(entry.path().string());
                std::cout << "Add Extension = jpg, bmp, png " << "Level depth -> " << it.depth() << std::endl;
            };
        }
    }
}