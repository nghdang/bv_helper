#pragma once

#include <QScxmlStateMachine>
#include <QSharedPointer>
#include <functional>
#include <memory>

namespace Framework {
namespace StateMachine {

class DataModel;

class GuiStateMachine
{
public:
    explicit GuiStateMachine(const QString& stateMachineFilePath);
    virtual ~GuiStateMachine();

    void connectToState(const QString& stateName, std::function<void(bool)> stateChangedHandler);
    std::shared_ptr<DataModel> getDataModel() const;
    void submitEvent(const QString& eventName);
    bool isRunning() const;
    void setRunning(bool value);

protected:
    QSharedPointer<QScxmlStateMachine> m_stateMachine;
    std::shared_ptr<DataModel> m_dataModel;
};

} // namespace StateMachine
} // namespace Framework
