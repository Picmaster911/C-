#include <filesystem>
#include <iostream>
#include <algorithm>
#include <ranges>
#include <unordered_set>
#include "MyTypeOffExtetion.h"


//   std::cout << entry.path() << " : " << entry.path() << "\n";
//   entry.is_directory()      // папка?
//   entry.is_regular_file()   // обычный файл?
//   entry.is_symlink()        // символическая ссылка?

struct FileInfo

{
    std::filesystem::path path;

    size_t size;

    std::string extension;
};

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
                // Lambda ->
                [](unsigned char c) {
                    return std::tolower(c);
                }
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
//  std::cout << currentPath << std::endl;
//  fs::path filePath = "data/config.json";
//  std::cout << "FileName" << filePath.filename() << std::endl;
//  std::cout << "Extension" << filePath.extension() << std::endl;
//  std::cout << "Parent" << filePath.parent_path() << std::endl;
//  for (const auto& entry : fs::directory_iterator(currentPath))
//  {
//     std::cout << "FileName" << entry.path().filename() << std::endl;
//  }

int main()
{
    std::vector< std::shared_ptr<FileInfo>> files;

    setlocale(LC_ALL, "Russian");

    std::unique_ptr<MyTypeOffExtetion> myExt = std::make_unique<MyTypeOffExtetion>();

    fs::path currentPath = fs::current_path();

    listFileRecursive(currentPath, myExt, files);


    auto textFiles =
        files
        | std::views::filter([](std::shared_ptr<FileInfo>& f) { return f->extension == ".txt"; });


    auto isImageFile = [](std::shared_ptr<FileInfo>& f)
        {
            static const std::unordered_set<std::string> exts{

                ".jpg", ".jpeg", ".png", ".bmp"
            };

            return exts.contains(f->extension);
        };

    auto imageFiles =
        files
        | std::views::filter(isImageFile);



    auto largeFiles =
        files
        | std::views::filter([](std::shared_ptr<FileInfo>& f)
            {

                return f->size > 100;

            });

    for (const auto& f : largeFiles)
    {
        std::cout << f->path;
    };

    std::cout << "Found exe file " << myExt->path_exe.size() << std::endl;
    std::cout << "Found .jpg, .png, .bmp file = " << myExt->path_picture.size() << std::endl;
    std::cout << "Found txt file = " << myExt->path_txt.size() << std::endl;
    std::cout << "Total size all file in folder = " << myExt->totalSize << " Byte" << std::endl;
    std::cout << "Total count other file = " << myExt->GetCountOtherFile() << " files" << std::endl;
    std::cout << "Size collection EXE = " << myExt->GetSizeCollectionFile(EXE) << " Byte" << std::endl;
    std::cout << "Size collection TXT = " << myExt->GetSizeCollectionFile(TXT) << " Byte" << std::endl;

    for (const auto& item : textFiles)
    {
        std::cout << item->extension;
    }

    //jast for my LAMBDA
    std::vector<int> myint{ 1,2,3,4,5,6,7,8 };

    auto my = std::find_if(myint.begin(), myint.end(), [](int x) { return x > 3 || x < 7; });
}

