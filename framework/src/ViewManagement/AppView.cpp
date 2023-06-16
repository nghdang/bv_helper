#include "Framework/ViewManagement/AppView.hpp"

#include <QQmlComponent>
#include "Framework/ViewManagement/ViewModel.hpp"

namespace Framework {
namespace ViewManagement {

AppView::AppView(const AppViewConfiguration& configuration)
    : m_configuration(configuration)
{
}

void AppView::init(QQmlEngine* engine)
{
    m_viewModel = m_configuration.getViewModelInstantiator()();
    m_viewModel->setParent(engine);

    m_qmlContext = std::make_shared<QQmlContext>(engine);
    m_qmlContext->setContextProperty(m_configuration.getViewModelName(), m_viewModel.get());

    QQmlComponent viewComp(engine);
    viewComp.loadUrl(m_configuration.getQmlUrl());
    m_quickItem = std::shared_ptr<QQuickItem>(qobject_cast<QQuickItem*>(viewComp.create(m_qmlContext.get())));
}

AppViewConfiguration AppView::getConfiguration() const
{
    return m_configuration;
}

std::shared_ptr<ViewModel> AppView::getViewModel() const
{
    return m_viewModel;
}

std::shared_ptr<QQuickItem> AppView::getQuickItem() const
{
    return m_quickItem;
}

std::shared_ptr<QQmlContext> AppView::getQmlContext() const
{
    return m_qmlContext;
}

} // namespace ViewManagement
} // namespace Framework
