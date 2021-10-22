# Disable in-source builds to prevent source tree corruption.
if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(
    FATAL_ERROR
      "FATAL: In-source builds are not allowed. You should create a separate directory for build files."
  )
endif()

# ~~~
# We want to determine if options are given with the wrong case.
# In order to detect which arguments are given to compare against the list of
# valid arguments, at the beginning here we need to form a list of all the given variables.
# If it begins with any case of McL, we add it to the list.
# ~~~
get_cmake_property(_variableNames VARIABLES)
set(MCL_GIVEN_VARIABLES)
foreach(var ${_variableNames})
  string(TOUPPER ${var} UC_VAR)
  string(FIND ${UC_VAR} MCL IDX)
  if(${IDX} EQUAL 0)
    list(APPEND MCL_GIVEN_VARIABLES ${var})
  endif()
endforeach()

# Basic initialization
set(Mcl_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(MCL_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(MCL_SRC_PATH ${Mcl_SOURCE_DIR})
set(MCL_PATH ${Mcl_SOURCE_DIR})
set(MCL_TOP_BUILD_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(MCL_TOP_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# Needed to simplify syntax of if statements
cmake_policy(SET CMP0054 NEW)
# Needed to make IN_LIST a valid operator
cmake_policy(SET CMP0057 NEW)

# Is this build a subdirectory of another project
get_directory_property(MCL_HAS_PARENT PARENT_DIRECTORY)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
                      "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules/")

cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

project(Mcl LANGUAGES C CXX)

if(NOT MCL_HAS_PARENT)
  if(NOT CMAKE_BUILD_TYPE)
    set(DEFAULT_BUILD_TYPE "RelWithDebInfo")
    message(
      STATUS
        "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
    set(CMAKE_BUILD_TYPE
        "${DEFAULT_BUILD_TYPE}"
        CACHE
          STRING
          "Choose the type of build, options are: Debug, Release, RelWithDebInfo and MinSizeRel."
          FORCE)
  endif()
endif()

if(NOT CMAKE_SIZEOF_VOID_P)
  string(FIND ${CMAKE_CXX_COMPILER} nvcc_wrapper FIND_IDX)
  if(NOT FIND_IDX STREQUAL -1)
    message(
      FATAL_ERROR
        "Mcl did not configure correctly and failed to validate compiler. The most likely cause is CUDA linkage using nvcc_wrapper. Please ensure your CUDA environment is correctly configured."
    )
  else()
    message(
      FATAL_ERROR
        "Mcl did not configure correctly and failed to validate compiler. The most likely cause is linkage errors during CMake compiler validation. Please consult the CMake error log shown below for the exact error during compiler validation"
    )
  endif()
elseif(NOT CMAKE_SIZEOF_VOID_P EQUAL 8)
  message(
    FATAL_ERROR
      "Mcl assumes a 64-bit build; i.e., 8-byte pointers, but found ${CMAKE_SIZEOF_VOID_P}-byte pointers instead"
  )
endif()

set(Mcl_VERSION_MAJOR 0)
set(Mcl_VERSION_MINOR 01)
set(Mcl_VERSION_PATCH 00)
set(Mcl_VERSION
    "${Mcl_VERSION_MAJOR}.${Mcl_VERSION_MINOR}.${Mcl_VERSION_PATCH}")
math(
  EXPR
  MCL_VERSION
  "${Mcl_VERSION_MAJOR} * 10000 + ${Mcl_VERSION_MINOR} * 100 + ${Mcl_VERSION_PATCH}"
)

message(
  STATUS
    "${PROJECT_NAME} (Morpheus Compatibility Layer) version is: v${Mcl_VERSION} (${MCL_VERSION})"
)

if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.12.0")
  message(STATUS "Setting policy CMP0074 to use <Package>_ROOT variables")
  cmake_policy(SET CMP0074 NEW)
endif()

# load utility functions
include(cmake/mcl_utils.cmake)

# Place here variables we will append as we go
global_set(MCL_TPL_EXPORTS)

mcl_setup_build_environment()

set(BUILD_SHARED_LIBS OFF)

set(MCL_EXT_LIBRARIES Morpheus::mcl Morpheus::ccl)
set(MCL_INT_LIBRARIES morpheus-mcl morpheus-ccl)
set_property(GLOBAL PROPERTY MCL_INT_LIBRARIES ${MCL_INT_LIBRARIES})

include(GNUInstallDirs)
if(MCL_HAS_PARENT)
  set(MCL_HEADER_INSTALL_DIR "include/mcl")
  set(MCL_IS_SUBDIRECTORY TRUE)
else()
  set(MCL_HEADER_INSTALL_DIR "${CMAKE_INSTALL_INCLUDEDIR}")
  set(MCL_IS_SUBDIRECTORY FALSE)
endif()

# Forward declare the package for certain options to be defined for subpackages
mcl_package_decl()

# Process the subpackages (subdirectories) for Morpheus
mcl_process_subpackages()

# If Morpheus itself is enabled, process the Morpheus package
if(NOT Mcl_INSTALL_TESTING)
  add_library(morpheus-mcl INTERFACE)
  # ~~~
  # Make sure in-tree projects can reference this as Morpheus::
  # to match the installed target names
  # ~~~
  add_library(Morpheus::mcl ALIAS morpheus-mcl)
  target_link_libraries(morpheus-mcl INTERFACE morpheus-ccl)
  mcl_internal_add_library_install(morpheus-mcl)
endif()

mcl_package_postprocess()
