#include "Document.h"
#include <exception>
#include <stdexcept>

void Document::insert(size_t pos, const std::string& str)
{
	checkMemory(str, pos);
	m_content.insert(pos, str);
}

void Document::erase(size_t pos, size_t count)
{
	if (pos > m_content.size())
		throw std::out_of_range("Document::erase: pos > size");
	m_content.erase(pos, count);
}

void Document::replace(size_t pos, size_t count, const std::string& str)
{
	if (pos > m_content.size())
		throw std::out_of_range("Document::erase: pos > size");
	checkMemory(str);
	m_content.replace(pos, count, str);
}

const std::string& Document::text() const
{
	return m_content;
}

void Document::initDocument()
{
	m_content.reserve(1000);
}

void Document::checkMemory(const std::string& str)
{
	if (m_content.size() > 0)
	{
		if (m_content.size() + str.size() > m_content.capacity())
		{
			m_content.reserve(m_content.capacity() + str.size() + 1000);
		}
	}
}

void Document::checkMemory(const std::string& str, size_t pos)
{
	if (m_content.size() == 0)
	{
		m_content.resize(pos + str.size(),' ');
	}
}