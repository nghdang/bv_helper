#include "Application/Domain/SettingsManagement/SettingsManager.hpp"

#include <iostream>
#include "Application/Domain/SettingsManagement/MainMenu.hpp"
#include "Application/Domain/SettingsManagement/SettingsContext.hpp"

namespace Application {
namespace Domain {
namespace SettingsManagement {

SettingsManager::SettingsManager(const std::shared_ptr<SettingsContext>& context)
    : m_context{context}
{
    m_context->init();
}

std::shared_ptr<MainMenu> SettingsManager::getMainMenu(const MenuUuid& uuid)
{
    return m_context->getMainMenus().at(uuid);
}

SettingValue SettingsManager::getValue(const SettingId& settingId) const
{
    auto mainMenu = m_context->getMainMenus().at(settingId.getMainMenuId());
    return mainMenu->getValue(settingId);
}

void SettingsManager::setValue(const SettingId& settingId, SettingValue settingValue)
{
    auto mainMenu = m_context->getMainMenus().at(settingId.getMainMenuId());
    mainMenu->setValue(settingId, settingValue);
}

void SettingsManager::loadFromPersistent()
{
    m_context->loadFromPersistent();
}

void SettingsManager::saveToPersistent()
{
    m_context->saveToPersistent();
}

} // namespace SettingsManagement
} // namespace Domain
} // namespace Application
