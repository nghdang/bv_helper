#pragma once

#include <map>
#include <memory>
#include "SettingId.hpp"

namespace Application {
namespace Domain {
namespace SettingsManagement {

class SettingsContext;
class MainMenu;

class SettingsManager
{
public:
    SettingsManager(const std::shared_ptr<SettingsContext>& m_context);

    std::shared_ptr<MainMenu> getMainMenu(const MenuUuid& uuid);

    SettingValue getValue(const SettingId& settingId) const;
    void setValue(const SettingId& settingId, SettingValue settingValue);

    void loadFromPersistent();
    void saveToPersistent();

protected:
    std::shared_ptr<SettingsContext> m_context;
};

} // namespace SettingsManagement
} // namespace Domain
} // namespace Application
