# Morpheus only defines the variables if the backends are ON Define aux
# variables that exist as on/off
macro(CHECK_MORPHEUS_BACKEND BE)
  if(Morpheus_ENABLE_${BE})
    set(MCL_ENABLE_${BE} ON)
  else()
    set(MCL_ENABLE_${BE} OFF)
  endif()
  global_set(Mcl_ENABLE_${BE} ${MCL_ENABLE_${BE}})
endmacro(CHECK_MORPHEUS_BACKEND)

check_morpheus_backend(CUDA)
check_morpheus_backend(HIP)
check_morpheus_backend(OPENMP)
check_morpheus_backend(SERIAL)
