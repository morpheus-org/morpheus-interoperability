add_executable(10_DenseMatrix_Interface 10_DenseMatrix_Interface.c)

target_include_directories(
  10_DenseMatrix_Interface PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
                                   ${CMAKE_CURRENT_SOURCE_DIR}/../../src)
target_link_libraries(10_DenseMatrix_Interface ${PROJECT_LIBS} Fcl::fcl)

set(RPATHS "$ENV{LD_LIBRARY_PATH}")
set_target_properties(
  10_DenseMatrix_Interface PROPERTIES BUILD_WITH_INSTALL_RPATH True
                                      INSTALL_RPATH "${RPATHS}")
