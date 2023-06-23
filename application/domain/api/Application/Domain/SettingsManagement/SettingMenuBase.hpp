#pragma once

#include "SettingId.hpp"

namespace Application {
namespace Domain {
namespace SettingsManagement {

class SettingMenuBase
{
public:
    SettingMenuBase(const MenuUuid& uuid, const std::string& displayText, const MenuType& menuType);

    MenuUuid getUuId() const;

    std::string getDisplayText() const;

    MenuType getMenuType() const;

    virtual SettingValue getValue(const SettingId& settingId) const = 0;

    virtual void setValue(const SettingId& settingId, const SettingValue& settingValue) = 0;

protected:
    MenuUuid m_uuid;
    std::string m_displayText;
    MenuType m_menuType;
};

} // namespace SettingsManagement
} // namespace Domain
} // namespace Application
