#include "Framework/ViewManagement/View.hpp"

namespace Framework {
namespace ViewManagement {

View::View(const ViewConfiguration& configuration, QQuickItem* quickItem, std::unique_ptr<QQmlContext> qmlContext, std::unique_ptr<ViewModel> viewModel)
    : m_configuration(configuration)
    , m_quickItem(std::unique_ptr<QQuickItem>(quickItem))
    , m_qmlContext(std::move(qmlContext))
    , m_viewModel(std::move(viewModel))
{
}

QQuickItem* View::getQuickItem() const
{
    return m_quickItem.get();
}

QQmlContext* View::getQmlContext() const
{
    return m_qmlContext.get();
}

ViewModel* View::getViewModel() const
{
    return m_viewModel.get();
}

} // namespace ViewManagement
} // namespace Framework
