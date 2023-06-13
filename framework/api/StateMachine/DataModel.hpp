#pragma once

#include <QScxmlDataModel>

namespace Framework {
namespace StateMachine {

class DataModel : public QScxmlDataModel
{
public:
    explicit DataModel(QObject* parent = nullptr);
};

} // namespace StateMachine
} // namespace Framework
