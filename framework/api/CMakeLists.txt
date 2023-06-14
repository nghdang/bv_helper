set(FW_HEADERS
    Framework/StateMachine/GuiStateMachine.hpp
    Framework/StateMachine/DataModel.hpp
    Framework/ViewManagement/ViewManager.hpp
    Framework/ViewManagement/ViewManagerConfiguration.hpp
    Framework/ViewManagement/Window.hpp
    Framework/ViewManagement/WindowConfiguration.hpp
    Framework/ViewManagement/View.hpp
    Framework/ViewManagement/ViewConfiguration.hpp
    Framework/ViewManagement/ViewModel.hpp
    Framework/ViewManagement/StackViewDriver.hpp
)

target_sources(${UI_FRAMEWORK} PRIVATE ${FW_HEADERS})
target_include_directories(${UI_FRAMEWORK} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
