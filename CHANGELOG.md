# Changelog

## Current - Version 0.1.0
- C interface for `CooMatrix`, `CsrMatrix`, `DiaMatrix`,`DenseMatrix` and `DenseVector` containers.
  - Currently it is assumed that containers hold *double* value types, *int* index types and are stored on *host* with *row-major* layout. 
- `print`, `multiply`, `dot`, `waxpy`, `reduce` and `scan` algorithms used by the above containers enalbed in C.