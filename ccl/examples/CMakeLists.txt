message(STATUS "Morpheus Ccl Examples are enabled")

mcl_include_directories(${CMAKE_CURRENT_BINARY_DIR})
mcl_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

mcl_add_executable(Examples_01_initialize SOURCES Examples_01_initialize.cpp)
mcl_add_executable(Examples_02_coomat SOURCES Examples_02_coomat.cpp)
mcl_add_executable(Examples_03_dynmat SOURCES Examples_03_dynmat.cpp)
mcl_add_executable(Examples_04_c_compatibility SOURCES
                   Examples_04_c_compatibility.c)
mcl_add_executable(Examples_05_Coo_Interface SOURCES
                   Examples_05_Coo_Interface.c)
mcl_add_executable(Examples_06_Csr_Interface SOURCES
                   Examples_06_Csr_Interface.c)
mcl_add_executable(Examples_07_Dia_Interface SOURCES
                   Examples_07_Dia_Interface.c)
mcl_add_executable(Examples_08_Vec_Interface SOURCES
                   Examples_08_Vec_Interface.c)
mcl_add_executable(Examples_09_Scan SOURCES Examples_09_Scan.c)
mcl_add_executable(Examples_10_DenseMatrix_Interface SOURCES
                   Examples_10_DenseMatrix_Interface.c)
mcl_add_executable(Examples_11_Dynamic_Interface SOURCES
                   Examples_11_Dynamic_Interface.c)
mcl_add_executable(Examples_12_Convert SOURCES Examples_12_Convert.c)
mcl_add_executable(Examples_13_Mirroring SOURCES Examples_13_Mirroring.c)
mcl_add_executable(Examples_14_Mirroring_Omp SOURCES
                   Examples_14_Mirroring_Omp.c)
mcl_add_executable(Examples_15_Mirroring_Cuda SOURCES
                   Examples_15_Mirroring_Cuda.c)
