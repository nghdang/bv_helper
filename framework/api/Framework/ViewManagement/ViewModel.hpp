#pragma once

#include <QObject>

namespace Framework {
namespace ViewManagement {

class ViewModel : public QObject
{
    Q_OBJECT
public:
    explicit ViewModel(QObject* parent = nullptr);

signals:
};

} // namespace ViewManagement
} // namespace Framework
