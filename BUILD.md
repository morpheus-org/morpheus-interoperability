## Installing Fcl

### Setup Environment
```sh
$ MCL_INSTALL_DIR=/Volumes/PhD/Code/Libraries/install/morpheus-fortran-interop/g++-11-debug
$ CXX_COMPILER=/usr/local/bin/g++-11
$ C_COMPILER=/usr/local/bin/gcc-11
$ MORPHEUS_INSTALL_DIR=/Volumes/PhD/Code/Libraries/install/morpheus/g++-11-debug
```

```sh
$ cmake .. -DCMAKE_CXX_COMPILER=${CXX_COMPILER} -DCMAKE_C_COMPILER=${C_COMPILER} -DCMAKE_INSTALL_PREFIX=${MCL_INSTALL_DIR} \
           -DMorpheus_ROOT=${MORPHEUS_INSTALL_DIR} -DCMAKE_BUILD_TYPE=Release \
           -DCMAKE_CXX_EXTENSIONS=Off -DMcl_ENABLE_EXAMPLES=On -DMcl_ENABLE_TESTS=Off -DMcl_VALUETYPE_FLOAT=ON -DMcl_INDEXTYPE_INT64=On -DMcl_LAYOUT_LEFT=ON
$ make
$ make install
```

## Morpheus-Interoperabiltiy CMake Option Listing
* Mcl_ENABLE_TESTS: BOOL
  * Whether to build tests.
  * Default: OFF
* Mcl_ENABLE_EXAMPLES: BOOL
  * Whether to build examples.
  * Default: OFF
* Mcl_VALUETYPE_DOUBLE: BOOL
  * Whether to set ValueType to `double`.
  * Default: OFF.
* Mcl_VALUETYPE_FLOAT: BOOL
  * Whether to set ValueType to `float`.
  * Default: OFF.
* Mcl_VALUETYPE_INT: BOOL
  * Whether to set ValueType to `int32_t`.
  * Default: OFF.
* Mcl_VALUETYPE_INT64: BOOL
  * Whether to set ValueType to `int64_t`.
  * Default: OFF.
* Mcl_INDEXTYPE_INT: BOOL
  * Whether to set IndexType to `int32_t`.
  * Default: OFF.
* Mcl_INDEXTYPE_INT64: BOOL
  * Whether to set IndexType to `int64_t`.
  * Default: OFF.
* Mcl_LAYOUT_RIGHT: BOOL
  * Whether to set Layout to `Kokkos::LayoutRight` (Row-major).
  * Default: OFF.
* Mcl_LAYOUT_LEFT: BOOL
  * Whether to set Layout to `Kokkos::LayoutLeft` (Column-major).
  * Default: OFF.
