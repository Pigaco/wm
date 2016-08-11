project(pigawm)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(Boost REQUIRED system program_options)

add_library(boost INTERFACE IMPORTED)
set_property(TARGET boost PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIRS})

add_library(boost-program_options SHARED IMPORTED)
set_property(TARGET boost-program_options PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIRS})
set_property(TARGET boost-program_options PROPERTY IMPORTED_LOCATION ${Boost_PROGRAM_OPTIONS_LIBRARY})

find_package(Wlc REQUIRED)
add_library(wlc SHARED IMPORTED)
set_property(TARGET wlc PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${WLC_INCLUDE_DIRS})
set_property(TARGET wlc PROPERTY IMPORTED_LOCATION ${WLC_LIBRARIES})

add_subdirectory(libwm)
add_subdirectory(bin)
