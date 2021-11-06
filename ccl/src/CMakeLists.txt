include(../../cmake/mcl_set_types.cmake)
mcl_configure_file(MorpheusCcl_config.hpp)

mcl_include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}
                        ${MCL_TOP_BUILD_DIR})

set(Mcl_ENABLE_INDIVIDUAL_TESTS
    OFF
    CACHE INTERNAL "Whether to enable individual unit tests. Default is OFF.")

set(CCL_HEADER_INSTALL_DIR ${MCL_HEADER_INSTALL_DIR}/ccl)

install(
  DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/"
  DESTINATION ${CCL_HEADER_INSTALL_DIR}
  FILES_MATCHING
  PATTERN "*.hpp"
  PATTERN "*.h")

set(CCL_CORE_SOURCES)
append_glob(CCL_CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

set(CCL_CORE_HEADERS)
append_glob(CCL_CORE_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)
append_glob(CCL_CORE_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/fwd/*.hpp)

if(MORPHEUS_ENABLE_SERIAL)
  append_glob(CCL_CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/host/*.cpp)
  append_glob(CCL_CORE_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/host/*.hpp)
endif()

if(MORPHEUS_ENABLE_OPENMP)
  append_glob(CCL_CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/phost/*.cpp)
  append_glob(CCL_CORE_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/phost/*.hpp)
endif()

if(MORPHEUS_ENABLE_CUDA)
  append_glob(CCL_CORE_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/dev/*.cpp)
  append_glob(CCL_CORE_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/dev/*.hpp)
endif()

append_glob(CCL_CORE_HEADERS ${CMAKE_CURRENT_BINARY_DIR}/MorpheusCcl_config.hpp)

foreach(HEADER ${CCL_CORE_HEADERS})
  get_filename_component(dirname ${HEADER} DIRECTORY)
  mcl_include_directories(${dirname})
endforeach()

mcl_add_library(morpheus-ccl SOURCES ${CCL_CORE_SOURCES} HEADERS
                ${CCL_CORE_HEADERS} ADD_BUILD_OPTIONS)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/MorpheusCcl_config.hpp
        DESTINATION ${CCL_HEADER_INSTALL_DIR})

mcl_lib_include_directories(
  morpheus-ccl ${MCL_TOP_BUILD_DIR} ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR})

# Link with Morpheus
target_link_libraries(morpheus-ccl PUBLIC Morpheus::morpheus)

foreach(HEADER ${CCL_CORE_HEADERS})
  get_filename_component(dirname ${HEADER} DIRECTORY)
  target_include_directories(morpheus-ccl PUBLIC $<BUILD_INTERFACE:${dirname}>)
endforeach()
target_include_directories(
  morpheus-ccl PUBLIC $<INSTALL_INTERFACE:${CCL_HEADER_INSTALL_DIR}>)
