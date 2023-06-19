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

    virtual void activating();
    virtual void activated();
    virtual void deactivating();
    virtual void deactivated();

signals:
};

} // namespace ViewManagement
} // namespace Framework
