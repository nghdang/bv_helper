#include "Framework/StateMachine/GuiStateMachine.hpp"

#include "Framework/StateMachine/DataModel.hpp"

namespace Framework {
namespace StateMachine {

GuiStateMachine::GuiStateMachine(const QString& stateMachineFilePath)
{
    m_stateMachine = QSharedPointer<QScxmlStateMachine>(QScxmlStateMachine::fromFile(stateMachineFilePath));
    m_dataModel = std::make_shared<DataModel>(m_stateMachine->dataModel());
    m_stateMachine->setRunning(true);
}

GuiStateMachine::~GuiStateMachine()
{
    if (m_stateMachine->isRunning())
    {
        m_stateMachine->setRunning(false);
    }
}

void GuiStateMachine::connectToState(const QString& stateName, std::function<void(bool)> stateChangedHandler)
{
    m_stateMachine->connectToState(stateName, stateChangedHandler);
}

std::shared_ptr<DataModel> GuiStateMachine::getDataModel() const
{
    return m_dataModel;
}

void GuiStateMachine::submitEvent(const QString& eventName)
{
    m_stateMachine->submitEvent(eventName);
}

bool GuiStateMachine::isRunning() const
{
    return m_stateMachine->isRunning();
}

void GuiStateMachine::setRunning(bool value)
{
    m_stateMachine->setRunning(value);
}

} // namespace StateMachine
} // namespace Framework
