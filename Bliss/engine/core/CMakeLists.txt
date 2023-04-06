project(core)

FILE(GLOB SOURCES
    *.cpp
	*.c
)

add_library(core ${SOURCES})