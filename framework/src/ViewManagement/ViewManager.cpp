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

void ViewManager::initializeWindow(MainWindowConfigurator mainWindowConfigurator)
{
    WindowConfiguration mainWindowConfiguration;
    if (mainWindowConfigurator)
    {
        mainWindowConfigurator(mainWindowConfiguration);
    }

    auto viewModel = mainWindowConfiguration.getViewModelInstantiator()();

    auto qmlContext = std::make_unique<QQmlContext>(m_engine.get());
    qmlContext->setContextProperty(mainWindowConfiguration.getViewModelName(), viewModel.get());

    QQmlComponent mainWindowComp(m_engine.get());
    mainWindowComp.loadUrl(mainWindowConfiguration.getQmlUrl());
    auto quickWindow = (qobject_cast<QQuickWindow*>(mainWindowComp.create(qmlContext.get())));
    m_mainWindow = std::make_unique<Window>(mainWindowConfiguration, quickWindow, std::move(qmlContext), std::move(viewModel));

    auto stackView = m_mainWindow->getQuickWindow()->findChild<QQuickItem*>(mainWindowConfiguration.getStackViewObjectName());
    m_stackViewDriver = std::make_shared<StackViewDriver>(m_engine.get(), stackView);
}

void ViewManager::registerView(ViewConfigurator viewConfigurator)
{
    ViewConfiguration viewConfiguration;
    if (viewConfigurator)
    {
        viewConfigurator(viewConfiguration);
    }

    auto viewModel = viewConfiguration.getViewModelInstantiator()();
    viewModel->setParent(m_engine.get());

    auto qmlContext = std::make_unique<QQmlContext>(m_engine.get());
    qmlContext->setContextProperty(viewConfiguration.getViewModelName(), viewModel.get());

    QQmlComponent viewComp(m_engine.get());
    viewComp.loadUrl(viewConfiguration.getQmlUrl());
    auto quickItem = qobject_cast<QQuickItem*>(viewComp.create(qmlContext.get()));
    auto fsmStateName = viewConfiguration.getFsmStateName();
    m_views.emplace(fsmStateName, std::make_unique<View>(viewConfiguration, quickItem, std::move(qmlContext), std::move(viewModel)));
    m_guiStateMachine->connectToState(viewConfiguration.getFsmStateName(), [this, fsmStateName](bool active) { onStateChanged(fsmStateName, active); });
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
