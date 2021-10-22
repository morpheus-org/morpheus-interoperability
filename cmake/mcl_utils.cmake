macro(GLOBAL_SET VARNAME)
  set(${VARNAME}
      ${ARGN}
      CACHE INTERNAL "")
endmacro()

macro(APPEND_GLOB VAR)
  file(GLOB LOCAL_TMP_VAR ${ARGN})
  list(APPEND ${VAR} ${LOCAL_TMP_VAR})
endmacro()

function(VERIFY_EMPTY CONTEXT)
  if(${ARGN})
    message(FATAL_ERROR "Unhandled arguments in ${CONTEXT}:\n${ARGN}")
  endif()
endfunction()

macro(MCL_SETUP_BUILD_ENVIRONMENT)
  # set an internal option, if not already set
  set(Mcl_INSTALL_TESTING
      OFF
      CACHE INTERNAL "Whether to build tests and examples against installation")

  set(Mcl_ENABLE_TESTS
      OFF
      CACHE INTERNAL "Whether to build tests")

  set(Mcl_ENABLE_EXAMPLES
      OFF
      CACHE INTERNAL "Whether to build examples")

  set(Mcl_ENABLE_BENCHMARKS
      OFF
      CACHE INTERNAL "Whether to build benchmarks")

  if(Mcl_INSTALL_TESTING)
    set(Mcl_ENABLE_TESTS ON)
    set(Mcl_ENABLE_EXAMPLES ON)
    set(Mcl_ENABLE_BENCHMARKS ON)
    # We are NOT going build Mcl but instead look for an installed Mcl then
    # build examples and tests against that installed Mcl
    find_package(Mcl REQUIRED)

    # Still need to figure out which backends
    include(cmake/kokkos_backends.cmake)
  else()
    # Regular build, not install testing
    if(NOT Mcl_HAS_PARENT)
      # This is a standalone build
      find_package(Morpheus REQUIRED)
      message(STATUS "Found Morpheus at ${Morpheus_DIR}")
    endif()
    # Still need to figure out which backends
    include(cmake/kokkos_backends.cmake)

  endif()
endmacro()

macro(MCL_PACKAGE_DECL)
  set(PACKAGE_NAME Mcl)
  set(PACKAGE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
  string(TOUPPER ${PACKAGE_NAME} PACKAGE_NAME_UC)
  set(${PACKAGE_NAME}_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
endmacro(MCL_PACKAGE_DECL)

macro(MCL_PACKAGE_POSTPROCESS)
  include(CMakePackageConfigHelpers)
  if(NOT Mcl_INSTALL_TESTING)
    configure_package_config_file(
      cmake/MclConfig.cmake.in "${Mcl_BINARY_DIR}/MclConfig.cmake"
      INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Mcl)

    write_basic_package_version_file(
      "${Mcl_BINARY_DIR}/MclConfigVersion.cmake"
      VERSION "${Mcl_VERSION}"
      COMPATIBILITY SameMajorVersion)

    install(FILES "${Mcl_BINARY_DIR}/MclConfig.cmake"
                  "${Mcl_BINARY_DIR}/MclConfigVersion.cmake"
            DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Mcl)

    install(
      EXPORT MclTargets
      DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Mcl
      NAMESPACE Morpheus::) # keep Morpheus namespace
  else()
    write_basic_package_version_file(
      "${CMAKE_CURRENT_BINARY_DIR}/MclConfigVersion.cmake"
      VERSION "${Mcl_VERSION}"
      COMPATIBILITY SameMajorVersion)

    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/MclConfigVersion.cmake
            DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Mcl)
  endif()
endmacro(MCL_PACKAGE_POSTPROCESS)

macro(MCL_PROCESS_SUBPACKAGES)
  add_subdirectory(ccl)
endmacro()

macro(MCL_SUBPACKAGE NAME)
  set(PACKAGE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
  set(PARENT_PACKAGE_NAME ${PACKAGE_NAME})
  set(PACKAGE_NAME ${PACKAGE_NAME}${NAME})
  string(TOUPPER ${PACKAGE_NAME} PACKAGE_NAME_UC)
  set(${PACKAGE_NAME}_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
endmacro()

function(MCL_LIB_TYPE LIB RET)
  get_target_property(PROP ${LIB} TYPE)
  if(${PROP} STREQUAL "INTERFACE_LIBRARY")
    set(${RET}
        "INTERFACE"
        PARENT_SCOPE)
  else()
    set(${RET}
        "PUBLIC"
        PARENT_SCOPE)
  endif()
endfunction()

function(MCL_INTERNAL_ADD_LIBRARY LIBRARY_NAME)
  cmake_parse_arguments(PARSE "STATIC;SHARED" "" "HEADERS;SOURCES" ${ARGN})

  if(PARSE_HEADERS)
    list(REMOVE_DUPLICATES PARSE_HEADERS)
  endif()
  if(PARSE_SOURCES)
    list(REMOVE_DUPLICATES PARSE_SOURCES)
  endif()

  if(PARSE_STATIC)
    set(LINK_TYPE STATIC)
  endif()

  if(PARSE_SHARED)
    set(LINK_TYPE SHARED)
  endif()

  # MSVC and other platforms want to have the headers included as source files
  # for better dependency detection
  add_library(${LIBRARY_NAME} ${LINK_TYPE} ${PARSE_HEADERS} ${PARSE_SOURCES})

  if(PARSE_SHARED OR BUILD_SHARED_LIBS)
    set_target_properties(
      ${LIBRARY_NAME}
      PROPERTIES VERSION ${MORPHEUS_VERSION}
                 SOVERSION ${Morpheus_VERSION_MAJOR}.${Morpheus_VERSION_MINOR})
  endif()

  mcl_internal_add_library_install(${LIBRARY_NAME})

  # In case we are building in-tree, add an alias name that matches the install
  # Morpheus:: name
  add_library(Morpheus::${LIBRARY_NAME} ALIAS ${LIBRARY_NAME})
endfunction()

function(MCL_SET_LIBRARY_PROPERTIES LIBRARY_NAME)
  cmake_parse_arguments(PARSE "PLAIN_STYLE" "" "" ${ARGN})

  if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.18")
    # I can use link options check for CXX linkage using the simple 3.18 way
    target_link_options(${LIBRARY_NAME} PUBLIC
                        $<$<LINK_LANGUAGE:CXX>:${KOKKOS_LINK_OPTIONS}>)
  else()
    # I can use link options just assume CXX linkage
    target_link_options(${LIBRARY_NAME} PUBLIC ${KOKKOS_LINK_OPTIONS})
  endif()

  target_compile_options(
    ${LIBRARY_NAME} PUBLIC $<$<COMPILE_LANGUAGE:CXX>:${KOKKOS_COMPILE_OPTIONS}>)

  target_compile_definitions(
    ${LIBRARY_NAME}
    PUBLIC $<$<COMPILE_LANGUAGE:CXX>:${KOKKOS_COMPILE_DEFINITIONS}>)

  target_link_libraries(${LIBRARY_NAME} PUBLIC ${KOKKOS_LINK_LIBRARIES})

  if(MORPHEUS_ENABLE_CUDA)
    target_compile_options(
      ${LIBRARY_NAME} PUBLIC $<$<COMPILE_LANGUAGE:CXX>:${KOKKOS_CUDA_OPTIONS}>)
    foreach(OPT ${KOKKOS_CUDAFE_OPTIONS})
      list(APPEND NODEDUP_CUDAFE_OPTIONS -Xcudafe ${OPT})
    endforeach()
    target_compile_options(
      ${LIBRARY_NAME}
      PUBLIC $<$<COMPILE_LANGUAGE:CXX>:${NODEDUP_CUDAFE_OPTIONS}>)
  endif()

  if(MORPHEUS_ENABLE_HIP)
    target_compile_options(
      ${LIBRARY_NAME}
      PUBLIC $<$<COMPILE_LANGUAGE:CXX>:${KOKKOS_AMDGPU_OPTIONS}>)
  endif()

  list(LENGTH KOKKOS_XCOMPILER_OPTIONS XOPT_LENGTH)
  if(XOPT_LENGTH GREATER 1)
    message(
      FATAL_ERROR
        "CMake deduplication does not allow multiple -Xcompiler flags (${KOKKOS_XCOMPILER_OPTIONS}): will require Kokkos to upgrade to minimum 3.12"
    )
  endif()
  if(KOKKOS_XCOMPILER_OPTIONS)
    set(NODEDUP_XCOMPILER_OPTIONS)
    foreach(OPT ${KOKKOS_XCOMPILER_OPTIONS})
      # I have to do this for now because we can't guarantee 3.12 support I
      # really should do this with the shell option
      list(APPEND NODEDUP_XCOMPILER_OPTIONS -Xcompiler)
      list(APPEND NODEDUP_XCOMPILER_OPTIONS ${OPT})
    endforeach()
    target_compile_options(
      ${LIBRARY_NAME}
      PUBLIC $<$<COMPILE_LANGUAGE:CXX>:${NODEDUP_XCOMPILER_OPTIONS}>)
  endif()

  if(KOKKOS_CXX_STANDARD_FEATURE)
    # GREAT! I can do this the right way
    target_compile_features(${LIBRARY_NAME}
                            PUBLIC ${KOKKOS_CXX_STANDARD_FEATURE})
    if(NOT KOKKOS_USE_CXX_EXTENSIONS)
      set_target_properties(${LIBRARY_NAME} PROPERTIES CXX_EXTENSIONS OFF)
    endif()
  else()
    # OH, well, no choice but the wrong way
    target_compile_options(${LIBRARY_NAME} PUBLIC ${KOKKOS_CXX_STANDARD_FLAG})
  endif()
endfunction()

function(MCL_ADD_LIBRARY LIBRARY_NAME)
  cmake_parse_arguments(PARSE "ADD_BUILD_OPTIONS" "" "HEADERS" ${ARGN})

  # Forward the headers, we want to know about all headers to make sure they
  # appear correctly in IDEs
  mcl_internal_add_library(${LIBRARY_NAME} ${PARSE_UNPARSED_ARGUMENTS} HEADERS
                           ${PARSE_HEADERS})
  if(PARSE_ADD_BUILD_OPTIONS)
    mcl_set_library_properties(${LIBRARY_NAME})
  endif()
endfunction()

macro(MCL_INTERNAL_ADD_LIBRARY_INSTALL LIBRARY_NAME)
  mcl_lib_type(${LIBRARY_NAME} INCTYPE)
  target_include_directories(${LIBRARY_NAME} ${INCTYPE}
                             $<INSTALL_INTERFACE:${MCL_HEADER_INSTALL_DIR}>)

  install(
    TARGETS ${LIBRARY_NAME}
    EXPORT ${PROJECT_NAME}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR} COMPONENT ${PACKAGE_NAME})

  install(
    TARGETS ${LIBRARY_NAME}
    EXPORT MclTargets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

  verify_empty(MCL_ADD_LIBRARY ${PARSE_UNPARSED_ARGUMENTS})
endmacro()

function(MCL_LIB_TYPE LIB RET)
  get_target_property(PROP ${LIB} TYPE)
  if(${PROP} STREQUAL "INTERFACE_LIBRARY")
    set(${RET}
        "INTERFACE"
        PARENT_SCOPE)
  else()
    set(${RET}
        "PUBLIC"
        PARENT_SCOPE)
  endif()
endfunction()

function(MCL_LIB_INCLUDE_DIRECTORIES TARGET)
  # append to a list for later
  mcl_lib_type(${TARGET} INCTYPE)
  foreach(DIR ${ARGN})
    target_include_directories(${TARGET} ${INCTYPE} $<BUILD_INTERFACE:${DIR}>)
  endforeach()
endfunction()

function(MCL_CONFIGURE_FILE PACKAGE_NAME_CONFIG_FILE)
  # Configure the file
  configure_file(${PACKAGE_SOURCE_DIR}/cmake/${PACKAGE_NAME_CONFIG_FILE}.in
                 ${CMAKE_CURRENT_BINARY_DIR}/${PACKAGE_NAME_CONFIG_FILE})
endfunction(MCL_CONFIGURE_FILE)

function(MCL_INCLUDE_DIRECTORIES)
  cmake_parse_arguments(INC "REQUIRED_DURING_INSTALLATION_TESTING" "" ""
                        ${ARGN})
  include_directories(${INC_UNPARSED_ARGUMENTS})
endfunction()

macro(MCL_ADD_TEST_DIRECTORIES)
  if(Mcl_ENABLE_TESTS)
    foreach(TEST_DIR ${ARGN})
      add_subdirectory(${TEST_DIR})
    endforeach()
  endif()
endmacro()

macro(MCL_ADD_EXAMPLE_DIRECTORIES)
  if(Mcl_ENABLE_EXAMPLES)
    foreach(EXAMPLE_DIR ${ARGN})
      add_subdirectory(${EXAMPLE_DIR})
    endforeach()
  endif()
endmacro()

macro(MCL_ADD_BENCHMARK_DIRECTORIES)
  if(Mcl_ENABLE_BENCHMARKS)
    foreach(BENCHMARK_DIR ${ARGN})
      add_subdirectory(${BENCHMARK_DIR})
    endforeach()
  endif()
endmacro()

function(MCL_ADD_EXECUTABLE ROOT_NAME)
  cmake_parse_arguments(PARSE "TESTONLY" "" "SOURCES;TESTONLYLIBS" ${ARGN})

  set(EXE_NAME ${PACKAGE_NAME}_${ROOT_NAME})
  add_executable(${EXE_NAME} ${PARSE_SOURCES})
  if(PARSE_TESTONLYLIBS)
    target_link_libraries(${EXE_NAME} PRIVATE ${PARSE_TESTONLYLIBS})
  endif()
  verify_empty(MCL_ADD_EXECUTABLE ${PARSE_UNPARSED_ARGUMENTS})
  # All executables must link to all the morpheus targets This is just private
  # linkage because exe is final
  target_link_libraries(${EXE_NAME} PRIVATE Morpheus::mcl)
endfunction()
