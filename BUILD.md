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
           -DCMAKE_CXX_EXTENSIONS=Off -DMcl_ENABLE_EXAMPLES=On -DMcl_ENABLE_TESTS=Off
$ make
$ make install
```
