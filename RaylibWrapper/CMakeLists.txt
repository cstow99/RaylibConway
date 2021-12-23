set(WRAPPER_PROJECT "RaylibWrapper")
add_library(${WRAPPER_PROJECT} raylib-wrapper.cpp raylib-wrapper.h Vec2.h)

if(WIN32 AND MSVC)
	target_include_directories(${WRAPPER_PROJECT} PUBLIC "${RAYLIB_DIR}/${RAYLIB_INCLUDE_DIR}")
else()
	target_include_directories(${WRAPPER_PROJECT} PUBLIC "${RAYLIB_INCLUDE_DIR}")
endif(WIN32 AND MSVC)

