#pragma once

#include <map>
#include <memory>
#include "SettingMenuBase.hpp"

namespace Application {
namespace Domain {
namespace SettingsManagement {

class Setting;

class SubMenu : public SettingMenuBase
{
public:
    SubMenu(const MenuUuid& uuid, const std::string& displayText, const MenuType& menuType,
            const std::map<MenuUuid, std::shared_ptr<Setting>>& settings);

    std::map<MenuUuid, std::shared_ptr<Setting>> getSettings() const;

public: // SettingMenuBase interface
    SettingValue getValue(const SettingId& settingId) const override;
    void setValue(const SettingId& settingId, const SettingValue& settingValue) override;

protected:
    std::map<MenuUuid, std::shared_ptr<Setting>> m_settings;
};

} // namespace SettingsManagement
} // namespace Domain
} // namespace Application
