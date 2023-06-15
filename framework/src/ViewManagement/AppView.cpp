#include "Framework/ViewManagement/AppView.hpp"

namespace Framework {
namespace ViewManagement {

AppView::AppView(const AppViewConfiguration& configuration, QQuickItem* quickItem, std::unique_ptr<QQmlContext> qmlContext,
                 std::unique_ptr<ViewModel> viewModel)
    : m_configuration(configuration)
    , m_quickItem(std::unique_ptr<QQuickItem>(quickItem))
    , m_qmlContext(std::move(qmlContext))
    , m_viewModel(std::move(viewModel))
{
}

QQuickItem* AppView::getQuickItem() const
{
    return m_quickItem.get();
}

QQmlContext* AppView::getQmlContext() const
{
    return m_qmlContext.get();
}

ViewModel* AppView::getViewModel() const
{
    return m_viewModel.get();
}

} // namespace ViewManagement
} // namespace Framework
