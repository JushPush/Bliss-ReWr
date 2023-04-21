#project(graphics)

FILE(GLOB_RECURSE SOURCES
    *.cpp
	*.c
)

add_library(bliss_graphics ${SOURCES})

target_link_libraries(bliss_graphics glfw)