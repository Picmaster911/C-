#include "Command.h"
#include "Document.h"
#include <memory>
#include <iostream>

class EraseTextCommand : public Command
{
	std::weak_ptr<Document> m_doc;
	size_t m_position;
	size_t m_count;

public:
	EraseTextCommand(std::shared_ptr<Document> doc,
		size_t position,
		size_t count)
		: m_doc(doc),
		m_position(position),
		m_count(count)

	{}

	void execute() override {
		auto doc = m_doc.lock();
		if (!doc)
		{
			std::cout << "Document no longer exists.\n";
			return;
		}
		doc->erase(m_position, m_count);
	}
};

