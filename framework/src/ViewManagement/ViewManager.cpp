#include "Framework/ViewManagement/ViewManager.hpp"

#include <QQmlComponent>
#include <iostream>
#include "Framework/ViewManagement/AppView.hpp"
#include "Framework/ViewManagement/AppWindow.hpp"
#include "Framework/ViewManagement/StackViewDriver.hpp"

namespace Framework {
namespace ViewManagement {

ViewId ViewManager::viewIdGenerator = 0;

ViewManager::ViewManager(ViewManagerConfigurator configurator, QObject* parent)
    : QObject{parent}
{
    m_engine = QSharedPointer<QQmlApplicationEngine>::create();

    ViewManagerConfiguration configuration;
    if (configurator)
    {
        configurator(configuration);
    }

    m_guiStateMachine = std::make_shared<StateMachine::GuiStateMachine>(configuration.getStateMachineUrl().path());
}

StateMachine::GuiStateMachine* ViewManager::getGuiStateMachine() const
{
    return m_guiStateMachine.get();
}

QSharedPointer<QQmlApplicationEngine> ViewManager::getEngine() const
{
    return m_engine;
}

void ViewManager::initializeWindow(AppViewConfigurator configurator)
{
    AppViewConfiguration configuration;
    if (configurator)
    {
        configurator(configuration);
    }

    m_appWindow = std::make_shared<AppWindow>(configuration);
    m_appWindow->init(m_engine.get());
}

void ViewManager::registerView(AppViewConfigurator configurator)
{
    AppViewConfiguration configuration;
    if (configurator)
    {
        configurator(configuration);
    }
    configuration.setViewId(viewIdGenerator++);
    const auto& viewId = configuration.getViewId();
    m_registeredViewConfigurations.emplace(viewId, configuration);
    m_guiStateMachine->connectToState(configuration.getFsmStateName(), [this, viewId](bool active) { onStateChanged(viewId, active); });
}

void ViewManager::onStateChanged(ViewId viewId, bool active)
{
    if (active)
    {
        if (m_cacheViews.count(viewId))
        {
            m_activeView = m_cacheViews.at(viewId);
        }
        else
        {
            auto configuration = m_registeredViewConfigurations.at(viewId);
            m_activeView = std::make_shared<AppView>(configuration);
            m_activeView->init(m_engine.get());
            m_cacheViews.emplace(viewId, m_activeView);
        }

        if (m_previousView)
        {
            auto previousViewId = m_previousView->getConfiguration().getViewId();
            auto activeViewId = m_activeView->getConfiguration().getViewId();
            if (activeViewId > previousViewId)
            {
                m_appWindow->getStackViewDriver()->pushView(m_activeView->getQuickItem().get());
            }
            else if (activeViewId < previousViewId)
            {
                m_appWindow->getStackViewDriver()->popView();
            }
        }
        else
        {
            m_appWindow->getStackViewDriver()->pushView(m_activeView->getQuickItem().get());
        }
    }
    else
    {
        m_previousView = m_activeView;
    }
}

} // namespace ViewManagement
} // namespace Framework
