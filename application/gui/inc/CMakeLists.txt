set(HEADERS
    Application/Gui/Common/ProfileItem.hpp
    Application/Gui/Common/ProfileCategory.hpp
    Application/Gui/Common/ProfileListModel.hpp
    Application/Gui/Common/ProfileCategoryListModel.hpp
    Application/Gui/Common/BaseViewModel.hpp
    Application/Gui/Common/BaseViewModelDependencies.hpp
    Application/Gui/Core/HeaderBarModel.hpp
    Application/Gui/Core/GuiApplication.hpp
    Application/Gui/MainWindow/MainWindowViewModel.hpp
    Application/Gui/UserProfile/UserProfileViewModel.hpp
    Application/Gui/TeamProfile/TeamProfileViewModel.hpp
    Application/Gui/GithubActivities/GithubActivitiesViewModel.hpp
    Application/Gui/JiraActivites/JiraActivitesViewModel.hpp
    Application/Gui/ViewManagement/ViewManager.hpp
    Application/Gui/ViewManagement/ViewContext.hpp
    Application/Gui/Helper/SharedConstants.hpp
    Application/Gui/Helper/SettingIds.hpp
    Application/Gui/Settings/SettingsMainMenuViewModel.hpp)

target_sources(${PROJECT_NAME} PRIVATE ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
