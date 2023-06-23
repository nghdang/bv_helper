#pragma once

#include <QObject>

namespace Application {
namespace Gui {
namespace Settings {

class SettingsMainMenuViewModel : public QObject
{
    Q_OBJECT
public:
    explicit SettingsMainMenuViewModel(QObject *parent = nullptr);

signals:

};

} // namespace Settings
} // namespace Gui
} // namespace Application

