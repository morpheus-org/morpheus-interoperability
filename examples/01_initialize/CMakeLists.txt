add_executable(01_initialize 01_initialize.cpp)

target_include_directories(
  01_initialize PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
                        ${CMAKE_CURRENT_SOURCE_DIR}/../../src)
target_link_libraries(01_initialize ${PROJECT_LIBS} Fcl::fcl)

set(RPATHS "$ENV{LD_LIBRARY_PATH}")
set_target_properties(01_initialize PROPERTIES BUILD_WITH_INSTALL_RPATH True
                                               INSTALL_RPATH "${RPATHS}")
