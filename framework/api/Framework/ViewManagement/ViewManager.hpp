#pragma once

#include <QObject>
#include <QQmlApplicationEngine>
#include <memory>
#include "AppView.hpp"
#include "AppViewConfiguration.hpp"
#include "AppWindow.hpp"
#include "AppWindowConfiguration.hpp"
#include "Framework/StateMachine/GuiStateMachine.hpp"
#include "StackViewDriver.hpp"
#include "ViewManagerConfiguration.hpp"

namespace Framework {
namespace ViewManagement {

class ViewManager : public QObject
{
    Q_OBJECT

public:
    using ViewManagerConfigurator = std::function<void(ViewManagerConfiguration& viewManagerConfiguration)>;
    using AppWindowConfigurator = std::function<void(AppWindowConfiguration& appWindowConfiguration)>;
    using AppViewConfigurator = std::function<void(AppViewConfiguration& appViewConfiguration)>;

    explicit ViewManager(ViewManagerConfigurator viewManagerConfigurator, QObject* parent = nullptr);

    StateMachine::GuiStateMachine* getGuiStateMachine() const;

    QSharedPointer<QQmlApplicationEngine> getEngine() const;

    void initializeWindow(AppWindowConfigurator mainWindowConfigurator);

    void registerView(AppViewConfigurator viewConfigurator);

public slots:
    void onStateChanged(const QString& stateName, bool active);

signals:

protected:
    std::unique_ptr<StateMachine::GuiStateMachine> m_guiStateMachine;

    QSharedPointer<QQmlApplicationEngine> m_engine;

    std::unique_ptr<AppWindow> m_mainWindow;

    std::shared_ptr<StackViewDriver> m_stackViewDriver;

    std::map<QString, std::unique_ptr<AppView>> m_views;
};

} // namespace ViewManagement
} // namespace Framework
