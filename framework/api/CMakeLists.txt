set(FRAMEWORK_HEADERS
    Framework/StateMachine/GuiStateMachine.hpp
    Framework/StateMachine/DataModel.hpp
    Framework/ViewManagement/ViewManager.hpp
    Framework/ViewManagement/ViewManagerConfiguration.hpp
    Framework/ViewManagement/AppView.hpp
    Framework/ViewManagement/AppWindow.hpp
    Framework/ViewManagement/AppViewConfiguration.hpp
    Framework/ViewManagement/ViewModel.hpp
    Framework/ViewManagement/StackViewDriver.hpp)

target_sources(${LIB_FRAMEWORK} PRIVATE ${FRAMEWORK_HEADERS})
target_include_directories(${LIB_FRAMEWORK} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
