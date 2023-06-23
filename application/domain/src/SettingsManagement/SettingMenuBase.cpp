#include "Application/Domain/SettingsManagement/SettingMenuBase.hpp"

namespace Application {
namespace Domain {
namespace SettingsManagement {

SettingMenuBase::SettingMenuBase(const MenuUuid& uuid, const std::string& displayText, const MenuType& menuType)
    : m_uuid{uuid}
    , m_displayText{displayText}
    , m_menuType{menuType}
{
}

MenuUuid SettingMenuBase::getUuId() const
{
    return m_uuid;
}

std::string SettingMenuBase::getDisplayText() const
{
    return m_displayText;
}

MenuType SettingMenuBase::getMenuType() const
{
    return m_menuType;
}

} // namespace SettingsManagement
} // namespace Domain
} // namespace Application
