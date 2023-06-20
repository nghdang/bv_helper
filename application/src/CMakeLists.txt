set(SOURCES
    Common/ProfileListModel.cpp
    Common/ProfileCategoryListModel.cpp
    Common/BaseViewModel.cpp
    Common/BaseViewModelDependencies.cpp
    Core/Main.cpp
    Core/HeaderBarModel.cpp
    Core/GuiApplication.cpp
    MainWindow/MainWindowViewModel.cpp
    UserProfile/UserProfileViewModel.cpp
    TeamProfile/TeamProfileViewModel.cpp
    GithubActivities/GithubActivitiesViewModel.cpp
    JiraActivites/JiraActivitesViewModel.cpp
    ViewManagement/ViewManager.cpp
    ViewManagement/ViewContext.cpp
    SettingsManagement/SettingsManager.cpp
    SettingsManagement/SettingsDatabase.cpp
    SettingsManagement/SettingsDatabaseDriver.cpp)

target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
