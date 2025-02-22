﻿# CMakeList.txt : CMake project for Bliss, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.

# TODO: Add tests and install targets if needed.

#add_library("${PROJECT_NAME}" "")
#add_library(Bliss::Bliss ALIAS "${PROJECT_NAME}")

#target_include_directories("${PROJECT_NAME}" PRIVATE ${PROJECT_SOURCE_DIR}/external/include)
#target_link_directories("${PROJECT_NAME}" PRIVATE ${PROJECT_SOURCE_DIR}/external/lib)

#target_link_libraries("${PROJECT_NAME}" glfw3 GL X11 pthread vulkan)

set(Bliss_EXPORT_FILE "Bliss-Exports")
#install(TARGETS "${PROJECT_NAME}" EXPORT "${Bliss_EXPORT_FILE}")

#target_include_directories("${PROJECT_NAME}" PUBLIC
#	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
#	"$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>" #bliss_export.h
#	"$<INSTALL_INTERFACE:include>" #${CMAKE_INSTALL_PREFIX}/include
#)

if(NOT BUILD_SHARED_LIBS)
	set(STATIC_POSTFIX "-s")
	set_target_properties("${PROJECT_NAME}" PROPERTIES 
	COMPILE_FLAGS -DBLISS_STATIC_DEFINE)
endif()

#Rename target Bliss
#set_target_properties("${PROJECT_NAME}" PROPERTIES
#	DEBUG_POSTFIX "${STATIC_POSTFIX}-d" 
#	RELEASE_POSTFIX "${STATIC_POSTFIX}"
#	MINSIZEREL_POSTFIX "${STATIC_POSTFIX}-mr"
#	RELWITHDEBINFO_POSTFIX "${STATIC_POSTFIX}-rd"
#)

#include("GenerateExportHeader")
#generate_export_header("${PROJECT_NAME}")
#install(FILES "${CMAKE_CURRENT_BINARY_DIR}/bliss_export.h" DESTINATION "include")

#add_subdirectory("include")
#add_subdirectory("src")

add_subdirectory("engine")

set(Bliss_CONFIG_DIR "lib/cmake/${PROJECT_NAME}")
configure_file("${Bliss_SOURCE_DIR}/cmake/BlissConfig.cmake.in" "${Bliss_BINARY_DIR}/${Bliss_CONFIG_DIR}/BlissConfig.cmake")
#install(FILES "${Bliss_BINARY_DIR}/${Bliss_CONFIG_DIR}/BlissConfig.cmake" DESTINATION "${Bliss_CONFIG_DIR}")
#install(EXPORT "${Bliss_EXPORT_FILE}" DESTINATION "${Bliss_CONFIG_DIR}" NAMESPACE "Bliss::")
