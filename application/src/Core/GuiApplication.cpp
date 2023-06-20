#include "Application/Core/GuiApplication.hpp"

#include <iostream>
#include "Application/Core/HeaderBarModel.hpp"
#include "Application/SettingsManagement/SettingsDatabase.hpp"
#include "Application/SettingsManagement/SettingsDatabaseDriver.hpp"
#include "Application/SettingsManagement/SettingsManager.hpp"
#include "Application/ViewManagement/ViewContext.hpp"
#include "Application/ViewManagement/ViewManager.hpp"

namespace Application {
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

    auto settingDatabase = std::make_shared<SettingsManagement::SettingsDatabase>();
    auto settingDatabaseDriver = std::make_shared<SettingsManagement::SettingsDatabaseDriver>();
    m_settingsManager = std::make_shared<SettingsManagement::SettingsManager>(std::move(settingDatabase), std::move(settingDatabaseDriver));
}

void GuiApplication::prepareExec()
{
    m_viewContext = std::make_shared<ViewManagement::ViewContext>(m_viewManager, m_settingsManager);
}

} // namespace Core
} // namespace Application
