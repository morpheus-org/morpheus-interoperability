add_executable(06_Csr_Interface 06_Csr_Interface.c)

target_include_directories(
  06_Csr_Interface PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
                           ${CMAKE_CURRENT_SOURCE_DIR}/../../src)
target_link_libraries(06_Csr_Interface ${PROJECT_LIBS} Fcl::fcl)

set(RPATHS "$ENV{LD_LIBRARY_PATH}")
set_target_properties(06_Csr_Interface PROPERTIES BUILD_WITH_INSTALL_RPATH True
                                                  INSTALL_RPATH "${RPATHS}")
