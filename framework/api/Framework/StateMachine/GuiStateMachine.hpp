#pragma once

#include <QScxmlStateMachine>
#include <QSharedPointer>

namespace Framework {
namespace StateMachine {

class GuiStateMachine
{
public:
    explicit GuiStateMachine(const QString& stateMachineFilePath);

    QSharedPointer<QScxmlStateMachine> getStateMachine() const;

protected:
    QSharedPointer<QScxmlStateMachine> m_stateMachine;
};

} // namespace StateMachine
} // namespace Framework
