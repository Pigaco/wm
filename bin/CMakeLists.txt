add_executable(
    pigawm 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

target_link_libraries(pigawm
    wm 
    boost
    boost-program_options)
