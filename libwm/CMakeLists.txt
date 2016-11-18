add_library(
    wm

    ${CMAKE_CURRENT_SOURCE_DIR}/src/WindowManager.cpp
)

set_property(TARGET wm PROPERTY COMPILE_FLAGS "-std=c++11")

target_include_directories(
    wm PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(wm wlc)
target_link_libraries(wm boost-log boost-system)

install(TARGETS wm
    ARCHIVE  DESTINATION lib
    LIBRARY  DESTINATION lib
    RUNTIME  DESTINATION bin)  # This is for Windows
install(DIRECTORY include/ DESTINATION include)

export(TARGETS wm FILE PigaWMConfig.cmake)
