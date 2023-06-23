#pragma once

#include <QGuiApplication>

namespace Application {
namespace Gui {
namespace ViewManagement {
class ViewContext;
class ViewManager;
} // namespace ViewManagement
} // namespace Gui
} // namespace Application

namespace Application {
namespace Domain {
namespace SettingsManagement {
class SettingsManager;
} // namespace SettingsManagement
} // namespace Domain
} // namespace Application

namespace Application {
namespace Gui {
namespace Core {

class GuiApplication : public QGuiApplication
{
public:
    GuiApplication(int& argc, char** argv);

    void init();
    void prepareExec();

protected:
    std::shared_ptr<ViewManagement::ViewContext> m_viewContext;
    std::shared_ptr<ViewManagement::ViewManager> m_viewManager;
    std::shared_ptr<Domain::SettingsManagement::SettingsManager> m_settingsManager;
};

} // namespace Core
} // namespace Gui
} // namespace Application
