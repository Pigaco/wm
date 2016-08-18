project(pigawm)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost REQUIRED system program_options log thread)

add_library(boost INTERFACE IMPORTED)
set_property(TARGET boost PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIRS})

add_library(boost-program_options SHARED IMPORTED)
set_property(TARGET boost-program_options PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIRS})
set_property(TARGET boost-program_options PROPERTY IMPORTED_LOCATION ${Boost_PROGRAM_OPTIONS_LIBRARY})

add_library(boost-thread SHARED IMPORTED)
set_property(TARGET boost-thread PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIRS})
set_property(TARGET boost-thread PROPERTY IMPORTED_LOCATION ${Boost_THREAD_LIBRARY})

add_library(boost-system SHARED IMPORTED)
set_property(TARGET boost-system PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIRS})
set_property(TARGET boost-system PROPERTY IMPORTED_LOCATION ${Boost_SYSTEM_LIBRARY})

add_library(boost-log SHARED IMPORTED)
set_property(TARGET boost-log PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIRS})
set_property(TARGET boost-log PROPERTY IMPORTED_LOCATION ${Boost_LOG_LIBRARY})

find_package(Wlc REQUIRED)
add_library(wlc SHARED IMPORTED)
set_property(TARGET wlc PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${WLC_INCLUDE_DIRS})
set_property(TARGET wlc PROPERTY IMPORTED_LOCATION ${WLC_LIBRARIES})

find_package(PigaDaemon REQUIRED)

add_subdirectory(libwm)
add_subdirectory(bin)
