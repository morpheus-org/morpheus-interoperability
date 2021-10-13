add_executable(09_Scan 09_Scan.c)

target_include_directories(
  09_Scan PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
                  ${CMAKE_CURRENT_SOURCE_DIR}/../../src)
target_link_libraries(09_Scan ${PROJECT_LIBS} Fcl::fcl)

set(RPATHS "$ENV{LD_LIBRARY_PATH}")
set_target_properties(09_Scan PROPERTIES BUILD_WITH_INSTALL_RPATH True
                                         INSTALL_RPATH "${RPATHS}")
