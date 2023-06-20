#pragma once

#include <map>
#include "SettingsTypes.hpp"

namespace Application {
namespace SettingsManagement {

class SettingsDatabase
{
public:
    SettingsDatabase();

    bool hasSetting(SettingIdType settingId);
    SettingValueType getSetting(SettingIdType settingId);
    void setSetting(SettingIdType settingId, SettingValueType settingValue);

protected:
    std::map<SettingIdType, SettingValueType> m_settings;
};

} // namespace SettingsManagement
} // namespace Application
