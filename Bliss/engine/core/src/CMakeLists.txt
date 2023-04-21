project(bliss_core)

FILE(GLOB_RECURSE SOURCES
    *.cpp
	*.c
    *.inl
)

add_library(bliss_core ${SOURCES})