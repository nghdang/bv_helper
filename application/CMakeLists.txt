add_executable(${PROJECT_NAME})

add_library(${LIB_DOMAIN} STATIC)

target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB_FRAMEWORK} ${LIB_DOMAIN})

if(EXISTS ${CONAN_JSONFORMODERNCPP_ROOT})
  target_link_libraries(${LIB_DOMAIN} PRIVATE CONAN_PKG::jsonformoderncpp)
else()
  target_link_libraries(${LIB_DOMAIN} PRIVATE CONAN_PKG::nlohmann_json)
endif()

add_subdirectory(gui)
add_subdirectory(domain)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

add_custom_command(
  TARGET ${PROJECT_NAME}
  POST_BUILD
  COMMAND
    ${CMAKE_COMMAND} -E copy
    "${CMAKE_CURRENT_SOURCE_DIR}/../settings_context.json"
    "$<TARGET_FILE_DIR:${PROJECT_NAME}>/settings_context.json")
