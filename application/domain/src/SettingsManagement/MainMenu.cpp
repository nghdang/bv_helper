#include "Application/Domain/SettingsManagement/MainMenu.hpp"

#include "Application/Domain/SettingsManagement/SubMenu.hpp"

namespace Application {
namespace Domain {
namespace SettingsManagement {

MainMenu::MainMenu(const MenuUuid& uuid, const std::string& displayText, const MenuType& menuType,
                   const std::map<MenuUuid, std::shared_ptr<SubMenu>>& subMenus)
    : SettingMenuBase{uuid, displayText, menuType}
    , m_subMenus{subMenus}
{
}

std::map<MenuUuid, std::shared_ptr<SubMenu>> MainMenu::getSubMenus() const
{
    return m_subMenus;
}

SettingValue MainMenu::getValue(const SettingId& settingId) const
{
    auto subMenu = m_subMenus.at(settingId.getSubMenuId());
    return subMenu->getValue(settingId);
}

void MainMenu::setValue(const SettingId& settingId, const SettingValue& settingValue)
{
    auto subMenu = m_subMenus.at(settingId.getSubMenuId());
    subMenu->setValue(settingId, settingValue);
}

} // namespace SettingsManagement
} // namespace Domain
} // namespace Application
