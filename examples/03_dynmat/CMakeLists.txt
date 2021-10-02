add_executable(03_dynmat 03_dynmat.cpp)

target_include_directories(
  03_dynmat PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
                        ${CMAKE_CURRENT_SOURCE_DIR}/../../src)
target_link_libraries(03_dynmat ${PROJECT_LIBS} Fcl::fcl)

set(RPATHS "$ENV{LD_LIBRARY_PATH}")
set_target_properties(03_dynmat PROPERTIES BUILD_WITH_INSTALL_RPATH True
                                               INSTALL_RPATH "${RPATHS}")
