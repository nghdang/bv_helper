set(DOMAIN_HEADERS
    Application/Domain/SettingsManagement/SettingsTypes.hpp
    Application/Domain/SettingsManagement/SettingId.hpp
    Application/Domain/SettingsManagement/SettingMenuBase.hpp
    Application/Domain/SettingsManagement/MainMenu.hpp
    Application/Domain/SettingsManagement/SubMenu.hpp
    Application/Domain/SettingsManagement/Setting.hpp
    Application/Domain/SettingsManagement/SettingsManager.hpp
    Application/Domain/SettingsManagement/SettingsContext.hpp)

target_sources(${LIB_DOMAIN} PRIVATE ${DOMAIN_HEADERS})
target_include_directories(${LIB_DOMAIN} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
