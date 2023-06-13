#pragma once

#include <QObject>
#include <memory>
#include "Framework/StateMachine/GuiStateMachine.hpp"
#include "Framework/ViewManagement/ViewManagerConfiguration.hpp"

namespace Framework {
namespace ViewManagement {

class ViewManager : public QObject
{
    Q_OBJECT
public:
    using ViewManagerConfigurator = std::function<void(ViewManagerConfiguration& viewManagerConfiguration)>;

    explicit ViewManager(ViewManagerConfigurator viewManagerConfigurator, QObject* parent = nullptr);

signals:

protected:
    std::unique_ptr<StateMachine::GuiStateMachine> m_guiStateMachine;
};

} // namespace ViewManagement
} // namespace Framework
