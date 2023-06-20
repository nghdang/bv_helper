#pragma once

#include <QGuiApplication>

namespace Application {
namespace ViewManagement {
class ViewContext;
class ViewManager;
} // namespace ViewManagement
} // namespace Application

namespace Application {
namespace SettingsManagement {
class SettingsManager;
} // namespace SettingsManagement
} // namespace Application

namespace Application {
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
    std::shared_ptr<SettingsManagement::SettingsManager> m_settingsManager;
};

} // namespace Core
} // namespace Application
