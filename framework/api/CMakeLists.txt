set(FW_HEADERS
    Framework/StateMachine/GuiStateMachine.hpp
    Framework/StateMachine/DataModel.hpp
    Framework/ViewManagement/ViewManager.hpp
    Framework/ViewManagement/ViewManagerConfiguration.hpp
    Framework/ViewManagement/AppWindow.hpp
    Framework/ViewManagement/AppWindowConfiguration.hpp
    Framework/ViewManagement/AppView.hpp
    Framework/ViewManagement/AppViewConfiguration.hpp
    Framework/ViewManagement/ViewModel.hpp
    Framework/ViewManagement/StackViewDriver.hpp
)

target_sources(${UI_FRAMEWORK} PRIVATE ${FW_HEADERS})
target_include_directories(${UI_FRAMEWORK} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
