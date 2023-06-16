#pragma once

#include <QObject>
#include <iostream>

namespace Framework {
namespace ViewManagement {

class ViewModel : public QObject
{
    Q_OBJECT
public:
    explicit ViewModel(QObject* parent = nullptr);

    virtual void activated();
    virtual void activating();
    virtual void deactivated();
    virtual void deactivating();

signals:
};

} // namespace ViewManagement
} // namespace Framework
