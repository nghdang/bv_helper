#pragma once

#include <QScxmlStateMachine>

namespace Framework {
namespace StateMachine {

class GuiStateMachine
{
public:
    explicit GuiStateMachine(const QString& stateMachineFilePath);

    GuiStateMachine(const GuiStateMachine& rhs) = delete;
    GuiStateMachine& operator=(const GuiStateMachine& rhs) = delete;

protected:
    QScxmlStateMachine* m_stateMachine;
};

} // namespace StateMachine
} // namespace Framework
