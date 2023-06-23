set(DOMAIN_SOURCES
    SettingsManagement/SettingId.cpp
    SettingsManagement/SettingMenuBase.cpp
    SettingsManagement/MainMenu.cpp
    SettingsManagement/SubMenu.cpp
    SettingsManagement/Setting.cpp
    SettingsManagement/SettingsManager.cpp
    SettingsManagement/SettingsContext.cpp)

target_sources(${LIB_DOMAIN} PRIVATE ${DOMAIN_SOURCES})
