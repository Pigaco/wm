add_executable(
    pigawm 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

set_property(TARGET pigawm PROPERTY COMPILE_FLAGS "-std=c++11")

target_link_libraries(pigawm
    wm 
    boost
    boost-program_options)

install(TARGETS pigawm
    EXPORT PigaWMConfig
    ARCHIVE  DESTINATION lib
    LIBRARY  DESTINATION lib
    RUNTIME  DESTINATION bin)  # This is for Windows
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/app_config.cfg DESTINATION /usr/lib/piga/apps/aa_pigawm/)
install(EXPORT PigaWMConfig DESTINATION lib/cmake)
