#include "Framework/ViewManagement/ViewManager.hpp"

#include <QQmlComponent>
#include <iostream>
#include "Framework/ViewManagement/AppView.hpp"
#include "Framework/ViewManagement/AppWindow.hpp"
#include "Framework/ViewManagement/StackViewDriver.hpp"
#include "Framework/ViewManagement/ViewModel.hpp"

namespace Framework {
namespace ViewManagement {

ViewId ViewManager::viewIdGenerator = 0;

ViewManager::ViewManager(ViewManagerConfigurator configurator, QObject* parent)
    : QObject{parent}
    , m_previousViewId{-1}
    , m_activeViewId{-1}
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
        m_activeViewId = viewId;
        std::shared_ptr<AppView> previousView;
        std::shared_ptr<AppView> activeView;

        if (m_activeViewId > m_previousViewId)
        {
            if (m_previousViewId >= 0)
            {
                auto configuration = m_registeredViewConfigurations.at(m_activeViewId);
                activeView = std::make_shared<AppView>(configuration);
                activeView->init(m_engine.get());
                previousView = m_cacheViews.top();

                activeView->getViewModel()->activating();
                previousView->getViewModel()->deactivating();
                m_appWindow->getStackViewDriver()->pushView(activeView->getQuickItem().get());
                m_cacheViews.push(activeView);
                activeView->getViewModel()->activated();
                previousView->getViewModel()->deactivated();
            }
            else
            {
                auto configuration = m_registeredViewConfigurations.at(m_activeViewId);
                activeView = std::make_shared<AppView>(configuration);
                activeView->init(m_engine.get());

                activeView->getViewModel()->activating();
                m_appWindow->getStackViewDriver()->pushView(activeView->getQuickItem().get());
                m_cacheViews.push(activeView);
                activeView->getViewModel()->activated();
            }
        }
        else
        {
            previousView = m_cacheViews.top();
            m_cacheViews.pop();
            activeView = m_cacheViews.top();

            activeView->getViewModel()->activating();
            previousView->getViewModel()->deactivating();
            m_appWindow->getStackViewDriver()->popView();
            activeView->getViewModel()->activated();
            previousView->getViewModel()->deactivated();
        }
    }
    else
    {
        m_previousViewId = viewId;
    }
}

} // namespace ViewManagement
} // namespace Framework
