add_executable(08_Vec_Interface 08_Vec_Interface.c)

target_include_directories(
  08_Vec_Interface PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
                           ${CMAKE_CURRENT_SOURCE_DIR}/../../src)
target_link_libraries(08_Vec_Interface ${PROJECT_LIBS} Fcl::fcl)

set(RPATHS "$ENV{LD_LIBRARY_PATH}")
set_target_properties(08_Vec_Interface PROPERTIES BUILD_WITH_INSTALL_RPATH True
                                                  INSTALL_RPATH "${RPATHS}")
