set(FW_HEADERS
    Framework/ViewManagement/ViewManager.hpp
    Framework/ViewManagement/ViewManagerConfiguration.hpp
    Framework/StateMachine/GuiStateMachine.hpp
    Framework/StateMachine/DataModel.hpp
)

target_sources(${UI_FRAMEWORK} PRIVATE ${FW_HEADERS})
target_include_directories(${UI_FRAMEWORK} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
