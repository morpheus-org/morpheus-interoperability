add_executable(02_coomat 02_coomat.cpp)

target_include_directories(
  02_coomat PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
                    ${CMAKE_CURRENT_SOURCE_DIR}/../../src)
target_link_libraries(02_coomat ${PROJECT_LIBS} Fcl::fcl)

set(RPATHS "$ENV{LD_LIBRARY_PATH}")
set_target_properties(02_coomat PROPERTIES BUILD_WITH_INSTALL_RPATH True
                                           INSTALL_RPATH "${RPATHS}")
