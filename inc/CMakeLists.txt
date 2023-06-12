set(HEADERS
    MainWindow/MainWindowViewModel.hpp
    Common/ProfileItem.hpp
    Common/ProfileCategory.hpp
    Common/ProfileListModel.hpp
    Common/ProfileCategoryListModel.hpp
    UserProfile/UserProfileViewModel.hpp
    TeamProfile/TeamProfileViewModel.hpp
    GithubActivities/GithubActivitiesViewModel.hpp
    JiraActivites/JiraActivitesViewModel.hpp
)

target_sources(${PROJECT_NAME} PRIVATE ${HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
