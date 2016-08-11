add_library(
    wm

    ${CMAKE_CURRENT_SOURCE_DIR}/src/WindowManager.cpp
)

target_compile_features(wm PRIVATE cxx_raw_string_literals)
target_compile_features(wm PRIVATE cxx_nullptr)

target_include_directories(
    wm PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(wm wlc)

install(TARGETS wm
    ARCHIVE  DESTINATION lib
    LIBRARY  DESTINATION lib
    RUNTIME  DESTINATION bin)  # This is for Windows
install(DIRECTORY include/ DESTINATION include)

export(TARGETS wm FILE PigaWMConfig.cmake)
