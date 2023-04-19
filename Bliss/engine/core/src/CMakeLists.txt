project(core)

FILE(GLOB_RECURSE SOURCES
    *.cpp
	*.c
)

add_library(core ${SOURCES})