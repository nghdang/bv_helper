#include "Application/Domain/SettingsManagement/SettingId.hpp"

#include <iostream>

namespace Application {
namespace Domain {
namespace SettingsManagement {

SettingId::SettingId(const MenuUuid& mainMenuId, const MenuUuid& subMenuId, const MenuUuid& settingId)
    : m_mainMenuId{mainMenuId}
    , m_subMenuId{subMenuId}
    , m_settingId{settingId}
{
}

MenuUuid SettingId::getMainMenuId() const
{
    return m_mainMenuId;
}

MenuUuid SettingId::getSubMenuId() const
{
    return m_subMenuId;
}

MenuUuid SettingId::getSettingId() const
{
    return m_settingId;
}

std::string SettingId::toString()
{
    return m_mainMenuId + DELIMITER + m_subMenuId + DELIMITER + m_settingId;
}

void SettingId::fromString(const std::string& settingIdInString)
{
    size_t start{0};
    auto end = settingIdInString.find(DELIMITER);
    m_mainMenuId = settingIdInString.substr(start, end - start);

    start = end + 1;
    end = settingIdInString.find(DELIMITER, start);
    m_subMenuId = settingIdInString.substr(start, end - start);

    start = end + 1;
    m_settingId = settingIdInString.substr(start);
}

} // namespace SettingsManagement
} // namespace Domain
} // namespace Application
