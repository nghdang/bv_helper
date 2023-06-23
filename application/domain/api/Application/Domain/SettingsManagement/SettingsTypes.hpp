#pragma once

#include <string>
#include "enum.h"

namespace Application {
namespace Domain {
namespace SettingsManagement {

using MenuUuid = std::string;
using SettingValue = std::string;

BETTER_ENUM(MenuType, int, UNKNOWN = 0, MAIN_MENU = 1, SUB_MENU = 2, SETTING = 3);

} // namespace SettingsManagement
} // namespace Domain
} // namespace Application
