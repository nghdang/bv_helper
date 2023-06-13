set(HEADERS
    Common/ProfileItem.hpp
    Common/ProfileCategory.hpp
    Common/ProfileListModel.hpp
    Common/ProfileCategoryListModel.hpp
    Common/BaseViewModel.hpp
    Common/BaseViewModelDependencies.hpp
    Appliance/HeaderBarModel.hpp
    MainWindow/MainWindowViewModel.hpp
    UserProfile/UserProfileViewModel.hpp
    TeamProfile/TeamProfileViewModel.hpp
    GithubActivities/GithubActivitiesViewModel.hpp
    JiraActivites/JiraActivitesViewModel.hpp
)

target_sources(${PROJECT_NAME} PRIVATE ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
