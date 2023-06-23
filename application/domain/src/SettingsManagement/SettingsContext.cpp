#include "Application/Domain/SettingsManagement/SettingsContext.hpp"

#include <fstream>
#include <iomanip>
#include <iostream>
#include "Application/Domain/SettingsManagement/MainMenu.hpp"
#include "Application/Domain/SettingsManagement/Setting.hpp"
#include "Application/Domain/SettingsManagement/SettingsTypes.hpp"
#include "Application/Domain/SettingsManagement/SubMenu.hpp"
#include "nlohmann/json.hpp"

namespace Application {
namespace Domain {
namespace SettingsManagement {

void SettingsContext::init()
{
    std::ifstream ifs{CONTEXT_JSON_PATH};
    auto jsonObject = nlohmann::json::parse(ifs);
    for (const auto& mainMenuIt : jsonObject.items())
    {
        MenuUuid mainMenuUuid{mainMenuIt.key()};
        auto mainMenuJsonObject = mainMenuIt.value();
        auto mainMenuMenuType = MenuType::_from_string_nocase(std::string(mainMenuJsonObject[TOKEN_MENU_TYPE]).c_str());
        std::map<MenuUuid, std::shared_ptr<SubMenu>> subMenus;
        for (const auto& subMenuIt : mainMenuJsonObject[TOKEN_CHILDREN].items())
        {
            MenuUuid subMenuUuid{subMenuIt.key()};
            auto subMenuJsonObject = subMenuIt.value();
            auto subMenuMenuType =
              MenuType::_from_string_nocase(std::string(subMenuJsonObject[TOKEN_MENU_TYPE]).c_str());
            std::map<MenuUuid, std::shared_ptr<Setting>> settings;
            for (const auto& settingIt : subMenuJsonObject[TOKEN_CHILDREN].items())
            {
                MenuUuid settingUuid{settingIt.key()};
                auto settingJsonObject = subMenuIt.value();
                auto settingMenuType =
                  MenuType::_from_string_nocase(std::string(settingJsonObject[TOKEN_MENU_TYPE]).c_str());
                std::vector<SettingValue> directSelectValues;
                for (const auto& directSelectValue : settingJsonObject[TOKEN_DIRECT_SELECT_VALUES])
                {
                    directSelectValues.push_back(directSelectValue);
                }
                auto setting = std::make_shared<Setting>(settingUuid, settingJsonObject[TOKEN_DISPLAY_TEXT],
                                                         settingMenuType, directSelectValues);
                settings.emplace(settingUuid, setting);
            }
            auto subMenu =
              std::make_shared<SubMenu>(subMenuUuid, subMenuJsonObject[TOKEN_DISPLAY_TEXT], subMenuMenuType, settings);
            subMenus.emplace(subMenuUuid, subMenu);
        }
        auto mainMenu =
          std::make_shared<MainMenu>(mainMenuUuid, mainMenuJsonObject[TOKEN_DISPLAY_TEXT], mainMenuMenuType, subMenus);
        m_mainMenus.emplace(mainMenuUuid, mainMenu);
    }
    ifs.close();
}

std::map<MenuUuid, std::shared_ptr<MainMenu>> SettingsContext::getMainMenus() const
{
    return m_mainMenus;
}

void SettingsContext::loadFromPersistent()
{
    std::ifstream ifs{PERSISTENT_JSON_PATH};
    auto jsonObject = nlohmann::json::parse(ifs);
    for (const auto& it : jsonObject.items())
    {
        SettingId settingId;
        settingId.fromString(it.key());
        m_mainMenus.at(settingId.getMainMenuId())->setValue(settingId, it.value());
    }
    ifs.close();
}

void SettingsContext::saveToPersistent()
{
    std::ofstream ofs{PERSISTENT_JSON_PATH};
    nlohmann::json jsonObject;
    for (const auto& mainMenuIt : m_mainMenus)
    {
        for (const auto& subMenuIt : mainMenuIt.second->getSubMenus())
        {
            for (const auto& settingIt : subMenuIt.second->getSettings())
            {
                SettingId settingId{mainMenuIt.first, subMenuIt.first, settingIt.first};
                jsonObject[settingId.toString()] = settingIt.second->getValue(settingId);
            }
        }
    }
    ofs << std::setw(4) << jsonObject << std::endl;
    ofs.close();
}

} // namespace SettingsManagement
} // namespace Domain
} // namespace Application
