project(Conway)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SRC_CXX_FILES 
	Events.cpp Gui.cpp GameOfLife.cpp Grid.cpp Loop.cpp Conway.cpp Main.cpp
)

set(SRC_HXX_FILES 
	Events.h Gui.h GameOfLife.h Grid.h Loop.h Conway.h
)

set(SRC_FILES ${SRC_CXX_FILES} ${SRC_HXX_FILES})

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE "../RaylibWrapper")
target_link_directories(${PROJECT_NAME} PRIVATE "../RaylibWrapper")

if(WIN32 AND MSVC)
	target_include_directories(${PROJECT_NAME} PUBLIC "${RAYLIB_DIR}/${RAYLIB_INCLUDE_DIR}")
	target_link_directories(${PROJECT_NAME} PUBLIC "${RAYLIB_DIR}/${RAYLIB_LIBRARY_DIR}")
else()
	target_include_directories(${PROJECT_NAME} PUBLIC "${RAYLIB_INCLUDE_DIR}")
	target_link_directories(${PROJECT_NAME} PUBLIC "${RAYLIB_LIBRARY_DIR}")
endif(WIN32 AND MSVC)

if(${STATIC_BUILD})
	if(MINGW OR UNIX)
		set(CMAKE_EXE_LINKER_FLAGS -static)
	endif(MINGW OR UNIX)
endif(${STATIC_BUILD})

# Link our Raylib wrapper
target_link_libraries(${PROJECT_NAME} PRIVATE RaylibWrapper)

if(WIN32)
	# MinGW
	if(MINGW)
		target_link_libraries(${PROJECT_NAME} PUBLIC raylib opengl32 gdi32 winmm)
	endif(MINGW)
	
	# MSVC (Visual Studio)
	if(MSVC)
		if(${STATIC_BUILD})
			target_link_libraries(${PROJECT_NAME} PUBLIC ${RAYLIB_STATIC_LIB})
		else()
			target_link_libraries(${PROJECT_NAME} PUBLIC raylib.lib)
		endif(${STATIC_BUILD})
	endif(MSVC)
endif(WIN32)

# Unix/Unix-like (X11 is required)
if(UNIX)
	target_link_libraries(${PROJECT_NAME} PUBLIC raylib GL m pthread dl rt X11)
endif(UNIX)