add_executable(05_Coo_Interface 05_Coo_Interface.c)

target_include_directories(
  05_Coo_Interface PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
                           ${CMAKE_CURRENT_SOURCE_DIR}/../../src)
target_link_libraries(05_Coo_Interface ${PROJECT_LIBS} Fcl::fcl)

set(RPATHS "$ENV{LD_LIBRARY_PATH}")
set_target_properties(05_Coo_Interface PROPERTIES BUILD_WITH_INSTALL_RPATH True
                                                  INSTALL_RPATH "${RPATHS}")
