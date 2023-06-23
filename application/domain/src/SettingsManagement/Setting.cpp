#include "Application/Domain/SettingsManagement/Setting.hpp"

namespace Application {
namespace Domain {
namespace SettingsManagement {

Setting::Setting(const MenuUuid& uuid, const std::string& displayText, const MenuType& menuType,
                 const std::vector<SettingValue>& directSelectValues)
    : SettingMenuBase{uuid, displayText, menuType}
    , m_directSelectValues{directSelectValues}
{
}

std::vector<SettingValue> Setting::getDirectSelectValues() const
{
    return m_directSelectValues;
}

SettingValue Setting::getValue(const SettingId& settingId) const
{
    SettingValue settingValue;
    return settingValue;
}

void Setting::setValue(const SettingId& settingId, const SettingValue& settingValue) {}

} // namespace SettingsManagement
} // namespace Domain
} // namespace Application
