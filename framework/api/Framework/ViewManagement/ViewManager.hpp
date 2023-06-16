#pragma once

#include <QObject>
#include <QQmlApplicationEngine>
#include <memory>
#include "AppViewConfiguration.hpp"
#include "Framework/StateMachine/GuiStateMachine.hpp"
#include "ViewManagerConfiguration.hpp"

namespace Framework {
namespace ViewManagement {

class AppView;
class AppWindow;
class StackViewDriver;

class ViewManager : public QObject
{
    Q_OBJECT

public:
    using ViewManagerConfigurator = std::function<void(ViewManagerConfiguration& configuration)>;
    using AppViewConfigurator = std::function<void(AppViewConfiguration& configuration)>;

    explicit ViewManager(ViewManagerConfigurator configurator, QObject* parent = nullptr);

    StateMachine::GuiStateMachine* getGuiStateMachine() const;

    QSharedPointer<QQmlApplicationEngine> getEngine() const;

    void initializeWindow(AppViewConfigurator configurator);

    void registerView(AppViewConfigurator configurator);

public slots:
    void onStateChanged(ViewId viewId, bool active);

signals:

private:
    std::shared_ptr<StateMachine::GuiStateMachine> m_guiStateMachine;

    QSharedPointer<QQmlApplicationEngine> m_engine;

    std::shared_ptr<AppWindow> m_appWindow;

    static ViewId viewIdGenerator;
    std::map<ViewId, const AppViewConfiguration> m_registeredViewConfigurations;

    std::shared_ptr<AppView> m_activeView;
    std::shared_ptr<AppView> m_previousView;
    std::map<ViewId, std::shared_ptr<AppView>> m_cacheViews;
};

} // namespace ViewManagement
} // namespace Framework
