add_executable(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        UI_FRAMEWORK
)

add_subdirectory(res)
add_subdirectory(src)
add_subdirectory(inc)
if (${BUILD_UNIT_TESTS})
    add_subdirectory(gmock)
    add_subdirectory(test)
endif()

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
