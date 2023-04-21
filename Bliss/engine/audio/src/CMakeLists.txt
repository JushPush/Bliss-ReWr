project(bliss_audio)

FILE(GLOB_RECURSE SOURCES
    *.cpp
	*.c
)

add_library(bliss_audio ${SOURCES})