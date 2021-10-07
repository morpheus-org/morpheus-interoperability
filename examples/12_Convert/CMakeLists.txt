add_executable(12_Convert 12_Convert.c)

target_include_directories(
  12_Convert PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
                     ${CMAKE_CURRENT_SOURCE_DIR}/../../src)
target_link_libraries(12_Convert ${PROJECT_LIBS} Fcl::fcl)

set(RPATHS "$ENV{LD_LIBRARY_PATH}")
set_target_properties(12_Convert PROPERTIES BUILD_WITH_INSTALL_RPATH True
                                            INSTALL_RPATH "${RPATHS}")
