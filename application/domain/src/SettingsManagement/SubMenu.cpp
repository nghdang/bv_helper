#include "Application/Domain/SettingsManagement/SubMenu.hpp"

#include "Application/Domain/SettingsManagement/Setting.hpp"

namespace Application {
namespace Domain {
namespace SettingsManagement {

SubMenu::SubMenu(const MenuUuid& uuid, const std::string& displayText, const MenuType& menuType,
                 const std::map<MenuUuid, std::shared_ptr<Setting>>& settings)
    : SettingMenuBase{uuid, displayText, menuType}
    , m_settings{settings}
{
}

std::map<MenuUuid, std::shared_ptr<Setting>> SubMenu::getSettings() const
{
    return m_settings;
}

SettingValue SubMenu::getValue(const SettingId& settingId) const
{
    auto setting = m_settings.at(settingId.getSettingId());
    return setting->getValue(settingId);
}

void SubMenu::setValue(const SettingId& settingId, const SettingValue& settingValue)
{
    auto setting = m_settings.at(settingId.getSettingId());
    setting->setValue(settingId, settingValue);
}

} // namespace SettingsManagement
} // namespace Domain
} // namespace Application
