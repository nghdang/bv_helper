#include "Framework/StateMachine/DataModel.hpp"

namespace Framework {
namespace StateMachine {

DataModel::DataModel(QScxmlDataModel* dataModel)

{
    m_dataModel = QSharedPointer<QScxmlDataModel>(dataModel);
}

void DataModel::getProperty(const QString& propertyName, bool& returnValue)
{
    auto propertyValue = m_dataModel->scxmlProperty(propertyName);
    returnValue = propertyValue.toBool();
}

void DataModel::setProperty(const QString& propertyName, bool value)
{
    m_dataModel->setScxmlProperty(propertyName, QVariant::fromValue(value), QString(""));
}

} // namespace StateMachine
} // namespace Framework
