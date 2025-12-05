#include "Command.h"
#include "Document.h"
#include <memory>
#include <iostream>
#include <string>

class ReplaceTextCommand : public Command
{
	std::weak_ptr<Document> m_doc;
	std::string m_str;
	size_t  m_position;
	size_t m_count;
public:
	ReplaceTextCommand(std::shared_ptr<Document> doc,
		std::string str,
		size_t position,
		size_t count)
		:m_doc(doc),
		m_str(str),
		m_position(position),
		m_count (count)
	{}

	void execute() override {
		auto doc = m_doc.lock();
		if (!doc)
		{
			std::cout << "Document no longer exists.\n";
			return;
		}
		doc->replace(m_position, m_count, m_str);
	}
};

