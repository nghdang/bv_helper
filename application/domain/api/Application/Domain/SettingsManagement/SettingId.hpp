#pragma once

#include "SettingsTypes.hpp"

namespace Application {
namespace Domain {
namespace SettingsManagement {

class SettingId
{
public:
    SettingId(const MenuUuid& mainMenuId = "", const MenuUuid& subMenuId = "", const MenuUuid& settingId = "");

    MenuUuid getMainMenuId() const;
    MenuUuid getSubMenuId() const;
    MenuUuid getSettingId() const;

    std::string toString();
    void fromString(const std::string& settingIdInString);

protected:
    const std::string DELIMITER{"."};

    MenuUuid m_mainMenuId;
    MenuUuid m_subMenuId;
    MenuUuid m_settingId;
};

} // namespace SettingsManagement
} // namespace Domain
} // namespace Application
