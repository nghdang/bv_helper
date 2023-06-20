#pragma once

#include <map>
#include <memory>
#include "SettingsTypes.hpp"

namespace Application {
namespace SettingsManagement {

class SettingsDatabase;
class SettingsDatabaseDriver;

class SettingsManager
{
public:
    SettingsManager(const std::shared_ptr<SettingsDatabase>& m_settingDatabase, const std::shared_ptr<SettingsDatabaseDriver>& m_settingDatabaseDriver);

    SettingValueType getSetting(SettingIdType settingId);
    void setSetting(SettingIdType settingId, SettingValueType settingValue);

    void load();
    void save();

protected:
    std::shared_ptr<SettingsDatabase> m_database;
    std::shared_ptr<SettingsDatabaseDriver> m_driver;
};

} // namespace SettingsManagement
} // namespace Application
