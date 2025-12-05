#include <iostream>
#include "Document.h"
#include <string>
#include "CommandScheduler.h"
#include "InsertTextCommand.h"
#include "ReplaceTextCommand.h"
#include "EraseTextCommand.h"

int main()
{
    auto doc = std::make_shared<Document>();
    auto doc2 = std::make_shared<Document>();
    CommandScheduler scheduler;
    scheduler.schedule(std::make_unique<InsertTextCommand>(doc, "Hello word", 5));
    scheduler.schedule(std::make_unique<InsertTextCommand>(doc, " This is new word", 23 ));
    scheduler.schedule(std::make_unique<InsertTextCommand>(doc, "-Insert-", 25));

    std::string str = "WWW://";
    scheduler.schedule(std::make_unique<ReplaceTextCommand>(doc,str,0,5));
    scheduler.schedule(std::make_unique<ReplaceTextCommand>(doc, str, 23, 5));
    scheduler.runAll();
    std::cout <<"First Run = " << doc->text()<< " \n";
    scheduler.schedule(std::make_unique<EraseTextCommand>(doc, 23, 6));
    scheduler.runAll();
    std::cout << "Second Run = " << doc->text() << " \n";

    {
        auto tempDoc = std::make_shared<Document>("Temporary document");
        scheduler.schedule(std::make_unique<ReplaceTextCommand>(tempDoc, "Temporary", 1,1));
    }

    std::cout << "Running all commands...\n\n";
    scheduler.runAll();
}