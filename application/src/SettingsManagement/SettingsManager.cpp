#include "Application/SettingsManagement/SettingsManager.hpp"

#include <iostream>
#include "Application/SettingsManagement/SettingsDatabase.hpp"
#include "Application/SettingsManagement/SettingsDatabaseDriver.hpp"

namespace Application {
namespace SettingsManagement {

SettingsManager::SettingsManager(const std::shared_ptr<SettingsDatabase>& m_settingDatabase,
                                 const std::shared_ptr<SettingsDatabaseDriver>& m_settingDatabaseDriver)
{
}

SettingValueType SettingsManager::getSetting(SettingIdType settingId)
{
    SettingValueType settingValue;
    if (m_database->hasSetting(settingId))
    {
        settingValue = m_database->getSetting(settingId);
    }
    else
    {
        std::cout << "Setting " << settingId << " does not exist" << std::endl;
    }
    return settingValue;
}

void SettingsManager::setSetting(SettingIdType settingId, SettingValueType settingValue)
{
    if (m_database->hasSetting(settingId))
    {
        m_database->setSetting(settingId, settingValue);
    }
    else
    {
        std::cout << "Setting " << settingId << " does not exist" << std::endl;
    }
}

void SettingsManager::load()
{
    m_driver->load(m_database);
}

void SettingsManager::save()
{
    m_driver->save(m_database);
}

} // namespace SettingsManagement
} // namespace Application
