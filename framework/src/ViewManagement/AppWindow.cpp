#include "Framework/ViewManagement/AppWindow.hpp"

#include <QQmlComponent>
#include <QQuickItem>
#include "Framework/ViewManagement/StackViewDriver.hpp"
#include "Framework/ViewManagement/ViewModel.hpp"

namespace Framework {
namespace ViewManagement {

AppWindow::AppWindow(const AppViewConfiguration& configuration)
    : AppView{configuration}
{
}

void AppWindow::init(QQmlEngine* engine)
{
    m_viewModel = m_configuration.getViewModelInstantiator()();

    m_qmlContext = std::make_shared<QQmlContext>(engine);
    m_qmlContext->setContextProperty(m_configuration.getViewModelName(), m_viewModel.get());

    QQmlComponent mainWindowComp(engine);
    mainWindowComp.loadUrl(m_configuration.getQmlUrl());
    m_quickWindow =
      std::shared_ptr<QQuickWindow>(qobject_cast<QQuickWindow*>(mainWindowComp.create(m_qmlContext.get())));

    auto stackView = m_quickWindow->findChild<QQuickItem*>(m_configuration.getStackViewObjectName());
    m_stackViewDriver = std::make_shared<StackViewDriver>(engine);
    m_stackViewDriver->init(stackView);
}

std::shared_ptr<QQuickWindow> AppWindow::getQuickWindow() const
{
    return m_quickWindow;
}

std::shared_ptr<StackViewDriver> AppWindow::getStackViewDriver() const
{
    return m_stackViewDriver;
}

} // namespace ViewManagement
} // namespace Framework
