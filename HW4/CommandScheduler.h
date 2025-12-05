#pragma once
#include <queue>
#include <memory>
#include "Command.h"
class CommandScheduler
{
    std::queue<std::unique_ptr<Command>> m_pending;
public:
    void schedule(std::unique_ptr<Command> cmd);
    void runAll();
};

