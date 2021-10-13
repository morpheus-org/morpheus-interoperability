mcl_subpackage(Ccl) # TODO

if(NOT Mcl_INSTALL_TESTING)
  add_subdirectory(src)
endif()

mcl_add_test_directories(tests) # TODO
mcl_add_example_directories(examples) # TODO
