add_executable(13_Mirroring 13_Mirroring.c)

target_include_directories(
  13_Mirroring PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
                       ${CMAKE_CURRENT_SOURCE_DIR}/../../src)
target_link_libraries(13_Mirroring ${PROJECT_LIBS} Fcl::fcl)

set(RPATHS "$ENV{LD_LIBRARY_PATH}")
set_target_properties(13_Mirroring PROPERTIES BUILD_WITH_INSTALL_RPATH True
                                              INSTALL_RPATH "${RPATHS}")
