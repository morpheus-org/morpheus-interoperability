add_executable(11_Dynamic_Interface 11_Dynamic_Interface.c)

target_include_directories(
  11_Dynamic_Interface PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
                               ${CMAKE_CURRENT_SOURCE_DIR}/../../src)
target_link_libraries(11_Dynamic_Interface ${PROJECT_LIBS} Fcl::fcl)

set(RPATHS "$ENV{LD_LIBRARY_PATH}")
set_target_properties(
  11_Dynamic_Interface PROPERTIES BUILD_WITH_INSTALL_RPATH True INSTALL_RPATH
                                                                "${RPATHS}")
