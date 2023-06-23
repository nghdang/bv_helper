#include "Application/Gui/Core/HeaderBarModel.hpp"

namespace Application {
namespace Gui {

HeaderBarModel::HeaderBarModel(QObject* parent)
    : QObject{parent}
    , m_isShowHeaderBar{true}
{
}

bool HeaderBarModel::isShowHeaderBar() const
{
    return m_isShowHeaderBar;
}

void HeaderBarModel::setIsShowHeaderBar(bool value)
{
    m_isShowHeaderBar = value;
    emit isShowHeaderBarChanged();
}

QString HeaderBarModel::getHeaderText() const
{
    return m_headerText;
}

void HeaderBarModel::setHeaderText(const QString& value)
{
    if (value != m_headerText)
    {
        m_headerText = value;
        emit headerTextChanged();
    }
}

bool HeaderBarModel::hasBackButton() const
{
    return true;
}

void HeaderBarModel::setHasBackButton(bool value)
{
    m_hasBackButton = value;
    emit hasBackButtonChanged();
}

bool HeaderBarModel::hasNextButton() const
{
    return true;
}

void HeaderBarModel::setHasNextButton(bool value)
{
    m_hasBackButton = value;
    emit hasBackButtonChanged();
}

} // namespace Gui
} // namespace Application
