project(pigawm)
cmake_minimum_required(VERSION 2.8)

set(PIGAWM_VERSION_MAJOR "0" CACHE STRING "Major-Version")
set(PIGAWM_VERSION_MINOR "2" CACHE STRING "Minor-Version")
set(PIGAWM_VERSION_PATCH "0" CACHE STRING "Patch-Version")
set(PIGAWM_VERSION_TWEAK "0" CACHE STRING "Tweak-Version")
set(PIGAWM_VERSION_BUILD "0" CACHE STRING "Build")
set(PIGAWM_VERSION ${PIGAWM_VERSION_MAJOR}.${PIGAWM_VERSION_MINOR}.${PIGAWM_VERSION_PATCH}.${PIGAWM_VERSION_TWEAK}:${PIGAWM_VERSION_BUILD})

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

find_package(PigaDaemon REQUIRED)

# Add wlc 
set(WLC_BUILD_STATIC ON)
add_subdirectory(wlc)
export(TARGETS wlc APPEND FILE PigaWMConfig.cmake)

add_subdirectory(libwm)
add_subdirectory(bin)

target_include_directories(wm PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/wlc/include/)

set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Managing the game windows.")
set(CPACK_PACKAGE_VENDOR "Pigaco")
set(CPACK_PACKAGE_VERSION_MAJOR ${PIGAWM_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PIGAWM_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PIGAWM_VERSION_PATCH})
set(CPACK_PACKAGE_VERSION_TWEAK ${PIGAWM_VERSION_TWEAK})
set(CPACK_DEBIAN_PACKAGE_HOMEPAGE "http://pigaco.net/pages/pigawm.html")
set(CPACK_DEBIAN_PACKAGE_DEPENDS)
set(CPACK_PACKAGE_NAME "piga-wm")
set(CPACK_GENERATOR "DEB")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Max Heisinger <mail@maximaximal.com>")
include(CPack)
