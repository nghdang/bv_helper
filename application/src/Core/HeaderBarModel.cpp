#include "Application/Core/HeaderBarModel.hpp"

HeaderBarModel::HeaderBarModel(QObject* parent)
    : QObject{parent}
{
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
