#include "Command.h"
#include "Document.h"
#include <memory>
#include <iostream>

class InsertTextCommand : public Command {
    std::weak_ptr<Document> m_doc;
    std::string m_text;
    size_t m_position;
public:
    InsertTextCommand(std::shared_ptr<Document> doc,
        std::string text,
        size_t position)
        : m_doc(doc),
        m_text(std::move(text)),
        m_position(position)
    {}

    void execute() override {
        auto doc = m_doc.lock();
        if (!doc) {
            std::cout << "Document no longer exists.\n";
            return;
        }
        doc->insert(m_position, m_text);
    }
};
