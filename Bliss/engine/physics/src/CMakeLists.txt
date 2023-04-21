project(bliss_physics)

FILE(GLOB_RECURSE SOURCES
    *.cpp
	*.c
)

add_library(bliss_physics ${SOURCES})