#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <cstdint>
namespace fs = std::filesystem;

enum TypeExtension
{
	EXE,
	TXT,
	PICTURE,
	OTHER
};

class MyTypeOffExtetion
{
private:
	int _countOtherFile;

	std::uintmax_t getSizeCollectionFile(std::vector<std::string> collection)
	{
		std::uintmax_t totalSize = 0;

		for (const auto& item : collection)
		{
			if (fs::exists(item) && fs::is_regular_file(item))
			{
				std::uintmax_t size = fs::file_size(item);
				totalSize += size;
			}
		}

		return totalSize;
	}

public:
	std::vector<std::string> path_exe;
	std::vector<std::string> path_txt;
	std::vector<std::string> path_picture;
	std::vector<std::string> other_file;
	uintmax_t totalSize;
	uintmax_t countAllFile;

	uintmax_t GetCountOtherFile()
	{
		_countOtherFile =
			countAllFile - path_exe.size() - path_txt.size() - path_picture.size();
		return _countOtherFile;
	}


	std::uintmax_t GetSizeCollectionFile(TypeExtension typeExtension)
	{
		switch (typeExtension)
		{
			case EXE: return getSizeCollectionFile(path_exe);
			case TXT: return getSizeCollectionFile(path_txt);
			case PICTURE: return getSizeCollectionFile(path_picture);
			case OTHER: return getSizeCollectionFile(other_file);
			default:      return 0;
		}

	}

};

