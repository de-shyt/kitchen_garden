#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "libpqxx::pqxx" for configuration ""
set_property(TARGET libpqxx::pqxx APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(libpqxx::pqxx PROPERTIES
  IMPORTED_IMPLIB_NOCONFIG "${_IMPORT_PREFIX}/lib/libpqxx.dll.a"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/bin/libpqxx.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS libpqxx::pqxx )
list(APPEND _IMPORT_CHECK_FILES_FOR_libpqxx::pqxx "${_IMPORT_PREFIX}/lib/libpqxx.dll.a" "${_IMPORT_PREFIX}/bin/libpqxx.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
