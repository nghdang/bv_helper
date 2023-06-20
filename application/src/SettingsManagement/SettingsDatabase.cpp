#include "Application/SettingsManagement/SettingsDatabase.hpp"

namespace Application {
namespace SettingsManagement {

SettingsDatabase::SettingsDatabase() {}

bool SettingsDatabase::hasSetting(SettingIdType settingId)
{
    return m_settings.count(settingId);
}

SettingValueType SettingsDatabase::getSetting(SettingIdType settingId)
{
    return m_settings.at(settingId);
}

void SettingsDatabase::setSetting(SettingIdType settingId, SettingValueType settingValue)
{
    m_settings[settingId] = settingValue;
}

} // namespace SettingsManagement
} // namespace Application
