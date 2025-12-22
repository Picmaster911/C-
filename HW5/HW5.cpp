#include <filesystem>
#include <iostream>
#include <algorithm>
#include "MyTypeOffExtetion.h"

//   std::cout << entry.path() << " : " << entry.path() << "\n";
//   entry.is_directory()      // папка?
//   entry.is_regular_file()   // обычный файл?
//   entry.is_symlink()        // символическая ссылка?

namespace fs = std::filesystem;

void listFileRecursive(const fs::path& dirPath,  std::unique_ptr<MyTypeOffExtetion>& myTypeOffExtetion)
{
    for (fs::recursive_directory_iterator it(dirPath); it != fs::recursive_directory_iterator(); ++it)
    {
        const auto& entry = *it;
        if (entry.is_regular_file())
        {
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
    setlocale(LC_ALL, "Russian");

    std::unique_ptr<MyTypeOffExtetion> myExt = std::make_unique<MyTypeOffExtetion>();

    fs::path currentPath = fs::current_path();

    listFileRecursive(currentPath, myExt);

    std::cout << "Found exe file " << myExt->path_exe.size() << std::endl;
    std::cout << "Found .jpg, .png, .bmp file = " << myExt->path_picture.size() << std::endl;
    std::cout << "Found txt file = " << myExt->path_txt.size() << std::endl;
    std::cout << "Total size all file in folder = " << myExt->totalSize <<" Byte" << std::endl;

    //jast for my
    std::vector<int> myint{ 1,2,3,4,5,6,7,8 };

    auto my = std::find_if(myint.begin(), myint.end(), [](int x) { return x > 3 || x < 7; });

}

