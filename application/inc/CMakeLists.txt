set(HEADERS
    Application/Common/ProfileItem.hpp
    Application/Common/ProfileCategory.hpp
    Application/Common/ProfileListModel.hpp
    Application/Common/ProfileCategoryListModel.hpp
    Application/Common/BaseViewModel.hpp
    Application/Common/BaseViewModelDependencies.hpp
    Application/Appliance/HeaderBarModel.hpp
    Application/Appliance/GuiApplication.hpp
    Application/MainWindow/MainWindowViewModel.hpp
    Application/UserProfile/UserProfileViewModel.hpp
    Application/TeamProfile/TeamProfileViewModel.hpp
    Application/GithubActivities/GithubActivitiesViewModel.hpp
    Application/JiraActivites/JiraActivitesViewModel.hpp
    Application/ViewManagement/ViewManager.hpp
    Application/ViewManagement/ViewContext.hpp
)

target_sources(${PROJECT_NAME} PRIVATE ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
