#include "Framework/ViewManagement/ViewManager.hpp"

#include <QQmlComponent>
#include <iostream>

namespace Framework {
namespace ViewManagement {

ViewManager::ViewManager(ViewManagerConfigurator viewManagerConfigurator, QObject* parent)
    : QObject{parent}
{
    m_engine = QSharedPointer<QQmlApplicationEngine>::create();

    ViewManagerConfiguration viewManagerConfiguration;
    if (viewManagerConfigurator)
    {
        viewManagerConfigurator(viewManagerConfiguration);
    }

    m_guiStateMachine = std::make_unique<StateMachine::GuiStateMachine>(viewManagerConfiguration.getStateMachineUrl().path());
}

StateMachine::GuiStateMachine* ViewManager::getGuiStateMachine() const
{
    return m_guiStateMachine.get();
}

QSharedPointer<QQmlApplicationEngine> ViewManager::getEngine() const
{
    return m_engine;
}

void ViewManager::initializeWindow(AppWindowConfigurator appWindowConfigurator)
{
    AppWindowConfiguration appWindowConfiguration;
    if (appWindowConfigurator)
    {
        appWindowConfigurator(appWindowConfiguration);
    }

    auto viewModel = appWindowConfiguration.getViewModelInstantiator()();

    auto qmlContext = std::make_unique<QQmlContext>(m_engine.get());
    qmlContext->setContextProperty(appWindowConfiguration.getViewModelName(), viewModel.get());

    QQmlComponent mainWindowComp(m_engine.get());
    mainWindowComp.loadUrl(appWindowConfiguration.getQmlUrl());
    auto quickWindow = (qobject_cast<QQuickWindow*>(mainWindowComp.create(qmlContext.get())));
    m_mainWindow = std::make_unique<AppWindow>(appWindowConfiguration, quickWindow, std::move(qmlContext), std::move(viewModel));

    auto stackView = m_mainWindow->getQuickWindow()->findChild<QQuickItem*>(appWindowConfiguration.getStackViewObjectName());
    m_stackViewDriver = std::make_shared<StackViewDriver>(m_engine.get(), stackView);
}

void ViewManager::registerView(AppViewConfigurator appViewConfigurator)
{
    AppViewConfiguration appViewConfiguration;
    if (appViewConfigurator)
    {
        appViewConfigurator(appViewConfiguration);
    }

    auto viewModel = appViewConfiguration.getViewModelInstantiator()();
    viewModel->setParent(m_engine.get());

    auto qmlContext = std::make_unique<QQmlContext>(m_engine.get());
    qmlContext->setContextProperty(appViewConfiguration.getViewModelName(), viewModel.get());

    QQmlComponent viewComp(m_engine.get());
    viewComp.loadUrl(appViewConfiguration.getQmlUrl());
    auto quickItem = qobject_cast<QQuickItem*>(viewComp.create(qmlContext.get()));
    auto fsmStateName = appViewConfiguration.getFsmStateName();
    m_views.emplace(fsmStateName, std::make_unique<AppView>(appViewConfiguration, quickItem, std::move(qmlContext), std::move(viewModel)));
    m_guiStateMachine->connectToState(appViewConfiguration.getFsmStateName(), [this, fsmStateName](bool active) { onStateChanged(fsmStateName, active); });
}

void ViewManager::onStateChanged(const QString& stateName, bool active)
{
    if (active)
    {
        m_stackViewDriver->pushView(nullptr, m_views[stateName]->getQuickItem());
    }
}

} // namespace ViewManagement
} // namespace Framework
