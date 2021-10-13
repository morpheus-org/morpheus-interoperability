add_executable(04_c_compatibility 04_c_compatibility.c)

target_include_directories(
  04_c_compatibility PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
                             ${CMAKE_CURRENT_SOURCE_DIR}/../../src)
target_link_libraries(04_c_compatibility ${PROJECT_LIBS} Fcl::fcl)

set(RPATHS "$ENV{LD_LIBRARY_PATH}")
set_target_properties(
  04_c_compatibility PROPERTIES BUILD_WITH_INSTALL_RPATH True INSTALL_RPATH
                                                              "${RPATHS}")
