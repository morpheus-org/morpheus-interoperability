mcl_subpackage(Ccl)

if(NOT Mcl_INSTALL_TESTING)
  add_subdirectory(src)
endif()

mcl_add_test_directories(tests)
mcl_add_example_directories(examples)
