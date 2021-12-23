# Locate Raylib library

if(WIN32)
	set(RAYLIB_INCLUDE_DIR "${RAYLIB_DIR}/include" CACHE PATH "Location of Raylib's include directory")
	set(RAYLIB_LIBRARY_DIR "${RAYLIB_DIR}/lib" CACHE PATH "Location of Raylib's library directory")
endif(WIN32)

set(RAYLIB_SEARCH_PATHS 
~/Library/Frameworks
/Library/Frameworks
/usr/local
/usr
/sw # Fink
/opt/local # DarwinPorts
/opt/csw # Blastwave
/opt
)

find_path(RAYLIB_INCLUDE_DIR raylib.h 
    HINTS
    $ENV{RAYLIB_DIR}
    PATH_SUFFIXES include
    PATHS ${RAYLIB_SEARCH_PATHS}
)

find_library(RAYLIB_LIBRARY_DIR
    NAMES raylib
    $ENV{RAYLIB_DIR}
    PATH_SUFFIXES lib64 lib
    PATHS ${RAYLIB_SEARCH_PATHS}
)

INCLUDE(FindPackageHandleStandardArgs)

find_package_handle_standard_args(Raylib REQUIRED_VARS RAYLIB_INCLUDE_DIR RAYLIB_LIBRARY_DIR)