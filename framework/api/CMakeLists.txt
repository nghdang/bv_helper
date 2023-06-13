set(FW_HEADERS
    ViewManagement/ViewManager.hpp
    ViewManagement/ViewManagerConfiguration.hpp
    StateMachine/GuiStateMachine.hpp
    StateMachine/DataModel.hpp
)

target_sources(${UI_FRAMEWORK} PRIVATE ${FW_HEADERS})
target_include_directories(${UI_FRAMEWORK} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
