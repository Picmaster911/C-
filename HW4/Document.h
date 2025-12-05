#pragma once

#include <string>

class Document
{

public:
	std::string m_content;
	void insert(size_t pos, const std::string& str);
	void erase(size_t pos, size_t count);
	void replace(size_t pos, size_t count, const std::string& str);
	const std::string& text() const;
Document()
{
	initDocument();
}
Document(std::string str)
{
	m_content = str;
}
private:
	void initDocument();
	void checkMemory(const std::string& str);
	void checkMemory(const std::string& str, size_t pos);
};

