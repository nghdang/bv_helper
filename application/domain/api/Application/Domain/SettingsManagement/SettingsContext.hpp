#pragma once

#include <map>
#include <memory>
#include "SettingsTypes.hpp"

namespace Application {
namespace Domain {
namespace SettingsManagement {

class MainMenu;

class SettingsContext
{
public:
    void init();

    std::map<MenuUuid, std::shared_ptr<MainMenu>> getMainMenus() const;

    void loadFromPersistent();
    void saveToPersistent();

protected:
    const std::string CONTEXT_JSON_PATH{"settings_context.json"};
    const std::string PERSISTENT_JSON_PATH{"settings_persistent.json"};

    const std::string TOKEN_CHILDREN{"children"};
    const std::string TOKEN_MENU_TYPE{"menuType"};
    const std::string TOKEN_DISPLAY_TEXT{"displayText"};
    const std::string TOKEN_DIRECT_SELECT_VALUES{"directSelectValues"};

    std::map<MenuUuid, std::shared_ptr<MainMenu>> m_mainMenus;
};

} // namespace SettingsManagement
} // namespace Domain
} // namespace Application
