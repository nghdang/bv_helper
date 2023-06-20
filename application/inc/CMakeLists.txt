set(HEADERS
    Application/Common/ProfileItem.hpp
    Application/Common/ProfileCategory.hpp
    Application/Common/ProfileListModel.hpp
    Application/Common/ProfileCategoryListModel.hpp
    Application/Common/BaseViewModel.hpp
    Application/Common/BaseViewModelDependencies.hpp
    Application/Core/HeaderBarModel.hpp
    Application/Core/GuiApplication.hpp
    Application/MainWindow/MainWindowViewModel.hpp
    Application/UserProfile/UserProfileViewModel.hpp
    Application/TeamProfile/TeamProfileViewModel.hpp
    Application/GithubActivities/GithubActivitiesViewModel.hpp
    Application/JiraActivites/JiraActivitesViewModel.hpp
    Application/ViewManagement/ViewManager.hpp
    Application/ViewManagement/ViewContext.hpp
    Application/Helper/SharedConstants.hpp
    Application/SettingsManagement/SettingsTypes.hpp
    Application/SettingsManagement/SettingsManager.hpp
    Application/SettingsManagement/SettingsDatabase.hpp
    Application/SettingsManagement/SettingsDatabaseDriver.hpp
    Application/Helper/SettingIds.hpp)

target_sources(${PROJECT_NAME} PRIVATE ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
