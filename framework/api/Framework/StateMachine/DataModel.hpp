#pragma once

#include <QScxmlDataModel>
#include <QSharedPointer>

namespace Framework {
namespace StateMachine {

class DataModel
{
public:
    explicit DataModel(QScxmlDataModel* dataModel);

    void getProperty(const QString& propertyName, bool& returnValue);
    void setProperty(const QString& propertyName, bool value);

protected:
    QSharedPointer<QScxmlDataModel> m_dataModel;
};

} // namespace StateMachine
} // namespace Framework
