set(THIRD_PARTY_HEADERS enum.h)

target_sources(${LIB_DOMAIN} PUBLIC ${THIRD_PARTY_HEADERS})
target_include_directories(${LIB_DOMAIN} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
