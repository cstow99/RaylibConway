set(SRC_CXX_FILES
	Help.cpp
	C_Algorithm.cpp
	Grid.cpp
	Conway.cpp
)

set(SRC_HXX_FILES
	Help.h
	C_Algorithm.h
	Grid.h
	Conway.h
)

set(SRC_FILES ${SRC_CXX_FILES} ${SRC_HXX_FILES})
add_executable(${PROJECT_NAME} ${SRC_FILES})

#if(WIN32 AND MSVC)
#	target_include_directories(${PROJECT_NAME} PUBLIC "${RAYLIB_DIR}/${RAYLIB_INCLUDE_DIR}")
#	target_link_directories(${PROJECT_NAME} PUBLIC "${RAYLIB_DIR}/${RAYLIB_LIBRARY_DIR}")
#else()
	target_include_directories(${PROJECT_NAME} PUBLIC "${RAYLIB_INCLUDE_DIR}")
	target_link_directories(${PROJECT_NAME} PUBLIC "${RAYLIB_LIBRARY_DIR}")
#endif(WIN32 AND MSVC)

if(${STATIC_BUILD})
	set(CMAKE_EXE_LINKER_FLAGS -static)
endif(${STATIC_BUILD})

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
		
		target_link_libraries(${PROJECT_NAME} PUBLIC opengl32.lib gdi32.lib winmm.lib)
	endif(MSVC)
endif(WIN32)

if(UNIX)
	target_link_libraries(${PROJECT_NAME} PUBLIC raylib GL m pthread dl rt X11)
endif(UNIX)
