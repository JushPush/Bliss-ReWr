#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Bliss::Bliss" for configuration "Release"
set_property(TARGET Bliss::Bliss APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Bliss::Bliss PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libBliss.so"
  IMPORTED_SONAME_RELEASE "libBliss.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS Bliss::Bliss )
list(APPEND _IMPORT_CHECK_FILES_FOR_Bliss::Bliss "${_IMPORT_PREFIX}/lib/libBliss.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
