#pragma once

#include <memory>

namespace Application {
namespace SettingsManagement {

class SettingsDatabase;

class SettingsDatabaseDriver
{
public:
    SettingsDatabaseDriver();

    void load(const std::shared_ptr<SettingsDatabase>& database);
    void save(const std::shared_ptr<SettingsDatabase>& database);
};

} // namespace SettingsManagement
} // namespace Application
