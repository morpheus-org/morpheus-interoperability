set(Mcl_VALUETYPE_DOUBLE
    OFF
    CACHE INTERNAL
          "Whether to enable double precision value types. Default is OFF.")

set(Mcl_VALUETYPE_FLOAT
    OFF
    CACHE INTERNAL
          "Whether to enable single precision value types. Default is OFF.")

set(Mcl_VALUETYPE_INT
    OFF
    CACHE INTERNAL "Whether to enable int value types. Default is OFF.")

set(Mcl_VALUETYPE_INT64
    OFF
    CACHE INTERNAL "Whether to enable int64 value types. Default is OFF.")

set(Mcl_INDEXTYPE_INT
    OFF
    CACHE INTERNAL "Whether to enable int index types. Default is OFF.")

set(Mcl_INDEXTYPE_INT64
    OFF
    CACHE INTERNAL "Whether to enable int64 index types. Default is OFF.")

set(Mcl_LAYOUT_RIGHT
    OFF
    CACHE INTERNAL
          "Whether to enable right (Row-major) layout type. Default is OFF.")

set(Mcl_LAYOUT_LEFT
    OFF
    CACHE INTERNAL
          "Whether to enable left (Column-major) layout type. Default is OFF.")

if(Mcl_VALUETYPE_DOUBLE)
  set(Mcl_VALUETYPE "double")
elseif(Mcl_VALUETYPE_FLOAT)
  set(Mcl_VALUETYPE "float")
elseif(Mcl_VALUETYPE_INT)
  set(Mcl_VALUETYPE "int32_t")
elseif(Mcl_VALUETYPE_INT64)
  set(Mcl_VALUETYPE "int64_t")
else()
  set(Mcl_VALUETYPE "double")
  message(
    WARNING
      "Mcl_VALUETYPE was not specified.\n\tFalling back to default (${Mcl_VALUETYPE})."
  )
endif()

if(Mcl_INDEXTYPE_INT)
  set(Mcl_INDEXTYPE "int32_t")
elseif(Mcl_INDEXTYPE_INT64)
  set(Mcl_INDEXTYPE "int64_t")
else()
  set(Mcl_INDEXTYPE "int32_t")
  message(
    WARNING
      "Mcl_INDEXTYPE was not specified.\n\tFalling back to default (${Mcl_INDEXTYPE})."
  )
endif()

if(Mcl_LAYOUT_RIGHT)
  set(Mcl_LAYOUT "Kokkos::LayoutRight")
elseif(Mcl_LAYOUT_LEFT)
  set(Mcl_LAYOUT "Kokkos::LayoutLeft")
else()
  set(Mcl_LAYOUT "Kokkos::LayoutRight")
  message(
    WARNING
      "Mcl_LAYOUT was not specified.\n\tFalling back to default (${Mcl_LAYOUT})."
  )
endif()

message(STATUS "Selected Mcl ValueType: ${Mcl_VALUETYPE}")
message(STATUS "Selected Mcl IndexType: ${Mcl_INDEXTYPE}")
message(STATUS "Selected Mcl Layout: ${Mcl_LAYOUT}")
