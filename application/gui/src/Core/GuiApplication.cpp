#include "Application/Gui/Core/GuiApplication.hpp"

#include <iostream>
#include "Application/Domain/SettingsManagement/SettingsContext.hpp"
#include "Application/Domain/SettingsManagement/SettingsManager.hpp"
#include "Application/Gui/Core/HeaderBarModel.hpp"
#include "Application/Gui/ViewManagement/ViewContext.hpp"
#include "Application/Gui/ViewManagement/ViewManager.hpp"

namespace Application {
namespace Gui {
namespace Core {

GuiApplication::GuiApplication(int& argc, char** argv)
    : QGuiApplication(argc, argv)
{
    init();
}

void GuiApplication::init()
{
    qRegisterMetaType<HeaderBarModel*>();

    m_viewManager = std::make_shared<ViewManagement::ViewManager>();

    auto settingsContext = std::make_shared<Domain::SettingsManagement::SettingsContext>();
    m_settingsManager = std::make_shared<Domain::SettingsManagement::SettingsManager>(std::move(settingsContext));
}

void GuiApplication::prepareExec()
{
    m_viewContext = std::make_shared<ViewManagement::ViewContext>(m_viewManager, m_settingsManager);
}

} // namespace Core
} // namespace Gui
} // namespace Application
