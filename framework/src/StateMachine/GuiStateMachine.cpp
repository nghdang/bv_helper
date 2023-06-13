#include "Framework/StateMachine/GuiStateMachine.hpp"

#include <iostream>

namespace Framework {
namespace StateMachine {

GuiStateMachine::GuiStateMachine(const QString& stateMachineFilePath)
{
    m_stateMachine = QScxmlStateMachine::fromFile(stateMachineFilePath);
    if (m_stateMachine->parseErrors().empty())
    {
    }
    else
    {
        for (const auto& error : m_stateMachine->parseErrors())
        {
            std::cout << error.fileName().toStdString() << std::endl;
            std::cout << "    " << error.line() << ":" << error.description().toStdString() << std::endl;
        }
    }
}

} // namespace StateMachine
} // namespace Framework
