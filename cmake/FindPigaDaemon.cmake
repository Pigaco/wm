# - Try to find PigaDaemon.
# Once done, this will define:
#   PigaDaemon_FOUND
#   PigaDaemon_INCLUDE_DIRS
#   PigaDaemon_LIBRARIES

include(LibFindMacros)

# Include Directories
find_path(PigaDaemon_INCLUDE_DIR
  NAMES piga/daemon/Daemon.hpp
  PATHS /usr/include /usr/local/include
  )

# Finally the library itself
find_library(PigaDaemon_LIBRARY
  NAMES piga_daemon piga_daemon.so
  PATHS /usr/lib /usr/local/lib
  )

set(PigaDaemon_PROCESS_INCLUDES ${PigaDaemon_INCLUDE_DIR})
set(PigaDaemon_PROCESS_LIBRARIES ${PigaDaemon_LIBRARY})
libfind_process(PigaDaemon)