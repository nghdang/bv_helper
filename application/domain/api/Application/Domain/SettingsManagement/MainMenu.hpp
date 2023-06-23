#pragma once

#include <map>
#include <memory>
#include "SettingMenuBase.hpp"

namespace Application {
namespace Domain {
namespace SettingsManagement {

class SubMenu;

class MainMenu : public SettingMenuBase
{
public:
    MainMenu(const MenuUuid& uuid, const std::string& displayText, const MenuType& menuType,
             const std::map<MenuUuid, std::shared_ptr<SubMenu>>& subMenus);

    std::map<MenuUuid, std::shared_ptr<SubMenu>> getSubMenus() const;

public: // SettingMenuBase interface
    SettingValue getValue(const SettingId& settingId) const override;
    void setValue(const SettingId& settingId, const SettingValue& settingValue) override;

protected:
    std::map<MenuUuid, std::shared_ptr<SubMenu>> m_subMenus;
};

} // namespace SettingsManagement
} // namespace Domain
} // namespace Application
