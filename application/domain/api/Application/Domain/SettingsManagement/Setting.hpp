#pragma once

#include <vector>
#include "SettingMenuBase.hpp"

namespace Application {
namespace Domain {
namespace SettingsManagement {

class Setting : public SettingMenuBase
{
public:
    Setting(const MenuUuid& uuid, const std::string& displayText, const MenuType& menuType,
            const std::vector<SettingValue>& directSelectValues);

    std::vector<SettingValue> getDirectSelectValues() const;

public: // SettingMenuBase interface
    SettingValue getValue(const SettingId& settingId) const override;
    void setValue(const SettingId& settingId, const SettingValue& settingValue) override;

protected:
    std::vector<SettingValue> m_directSelectValues;
};

} // namespace SettingsManagement
} // namespace Domain
} // namespace Application
