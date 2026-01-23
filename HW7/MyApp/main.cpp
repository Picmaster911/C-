#include <mylib/mylib.hpp>
#include <mylib/MyTypeOffExtetion.h>
#include <unordered_set>
#include <ranges>
#include <iostream>
namespace fs = std::filesystem;

int main()
{

    std::vector< std::shared_ptr<mylib::FileInfo>> files;

    setlocale(LC_ALL, "Russian");

    std::unique_ptr<mylib::MyTypeOffExtetion> myExt = std::make_unique<mylib::MyTypeOffExtetion>();

    fs::path currentPath = fs::current_path();

    mylib::listFileRecursive(currentPath, myExt, files);


    auto textFiles =
        files
        | std::views::filter([](std::shared_ptr<mylib::FileInfo>& f) { return f->extension == ".txt"; });


    auto isImageFile = [](std::shared_ptr<mylib::FileInfo>& f)
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
        | std::views::filter([](std::shared_ptr<mylib::FileInfo>& f)
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
    std::cout << "Size collection EXE = " << myExt->GetSizeCollectionFile(mylib::TypeExtension::EXE) << " Byte" << std::endl;
    std::cout << "Size collection TXT = " << myExt->GetSizeCollectionFile(mylib::TypeExtension::TXT) << " Byte" << std::endl;

    for (const auto& item : textFiles)
    {
        std::cout << item->extension;
    }

    std::cin.get();

    //jast for my LAMBDA
    std::vector<int> myint{ 1,2,3,4,5,6,7,8 };

    auto my = std::find_if(myint.begin(), myint.end(), [](int x) { return x > 3 || x < 7; });
}
