## Installing Fcl

### Setup Environment
```sh
$ FCL_INSTALL_DIR=/Volumes/PhD/Code/Libraries/install/morpheus-fortran-interop/g++-11-debug
$ CXX_COMPILER=/usr/local/bin/g++-11
$ MORPHEUS_INSTALL_DIR=/Volumes/PhD/Code/Libraries/install/morpheus/g++-11-debug
```

```sh
$ cmake .. -DCMAKE_CXX_COMPILER=${CXX_COMPILER} -DCMAKE_INSTALL_PREFIX=${FCL_INSTALL_DIR} \
           -DMorpheus_ROOT=${MORPHEUS_INSTALL_DIR} -DCMAKE_BUILD_TYPE=Release \
           -DCMAKE_CXX_EXTENSIONS=Off -DFcl_ENABLE_EXAMPLES=Off -DFcl_ENABLE_TESTS=Off
$ make
$ make install
```
