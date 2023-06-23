add_library(${LIB_FRAMEWORK} SHARED)

target_link_libraries(${LIB_FRAMEWORK} PUBLIC Qt6::Core Qt6::Quick Qt6::Scxml)

add_subdirectory(res)
add_subdirectory(src)
add_subdirectory(api)
if(${BUILD_FW_GMOCK})
  add_subdirectory(gmock)
endif()
if(${BUILD_FW_UNIT_TESTS})
  add_subdirectory(test)
endif()

install(
  TARGETS ${LIB_FRAMEWORK}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
