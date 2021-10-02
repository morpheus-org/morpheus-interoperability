cmake_minimum_required(VERSION 3.10)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
project(Fcl LANGUAGES C CXX)

set(default_build_type "RelWithDebInfo")
set(BUILD_SHARED_LIBS OFF)

set(Fcl_VERSION_MAJOR 0)
set(Fcl_VERSION_MINOR 01)
set(Fcl_VERSION_PATCH 00)
set(Fcl_VERSION
    "${Fcl_VERSION_MAJOR}.${Fcl_VERSION_MINOR}.${Fcl_VERSION_PATCH}")
math(
  EXPR
  FCL_VERSION
  "${Fcl_VERSION_MAJOR} * 10000 + ${Fcl_VERSION_MINOR} * 100 + ${Fcl_VERSION_PATCH}"
)

message(STATUS "${PROJECT_NAME} version is: v${Fcl_VERSION} (${FCL_VERSION})")

if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.12.0")
  message(STATUS "Setting policy CMP0074 to use <Package>_ROOT variables")
  cmake_policy(SET CMP0074 NEW)
endif()

include(CMakeDetermineCCompiler)
include(CMakeDetermineCXXCompiler)

find_package(Morpheus REQUIRED)

include(CheckCXXCompilerFlag)
include(CheckCCompilerFlag)

include(GNUInstallDirs)

# Fcl-cxx library
add_library(fcl-cxx OBJECT src/Fcl_C_CooMatrix.cpp src/Fcl_C_DenseVector.cpp src/Fcl_C_Util.cpp)

set(fcl-cxx-public-headers ${PROJECT_SOURCE_DIR}/src/Fcl_C_CooMatrix.hpp
                           ${PROJECT_SOURCE_DIR}/src/Fcl_C_DenseVector.hpp
                           ${PROJECT_SOURCE_DIR}/src/Fcl_C_Types.hpp
                           ${PROJECT_SOURCE_DIR}/src/Fcl_C_Util.hpp)

set_property(TARGET fcl-cxx PROPERTY CXX_STANDARD 17)
set_target_properties(fcl-cxx PROPERTIES PUBLIC_HEADER
                                         "${fcl-cxx-public-headers}")
target_link_libraries(fcl-cxx PRIVATE Morpheus::morpheus)

add_library(fcl STATIC $<TARGET_OBJECTS:fcl-cxx>)
set_target_properties(fcl PROPERTIES PUBLIC_HEADER "${fcl-cxx-public-headers}")
target_include_directories(
  fcl INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/mod>
                $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_link_libraries(fcl INTERFACE Morpheus::morpheus)

# add Fcl library
add_library(Fcl::fcl ALIAS fcl)

# installation section
include(CMakePackageConfigHelpers)
configure_package_config_file(
  "cmake/FclConfig.cmake.in" "${PROJECT_BINARY_DIR}/FclConfig.cmake"
  INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake")

write_basic_package_version_file(
  "${PROJECT_BINARY_DIR}/FclConfigVersion.cmake"
  VERSION "${Fcl_VERSION}"
  COMPATIBILITY SameMinorVersion)

# install Fcl cmake config files
install(FILES "${PROJECT_BINARY_DIR}/FclConfigVersion.cmake"
              "${PROJECT_BINARY_DIR}/FclConfig.cmake"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}")
install(TARGETS fcl EXPORT FclTargets)
install(
  EXPORT FclTargets
  DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
  NAMESPACE Fcl::)

# install Fcl library and headers
install(
  TARGETS fcl
  ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
  PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

# unit testing section and toggle
if(Fcl_ENABLE_TESTS)
  add_subdirectory(tests)
endif()

if(Fcl_ENABLE_EXAMPLES)
  add_subdirectory(examples)
endif()
