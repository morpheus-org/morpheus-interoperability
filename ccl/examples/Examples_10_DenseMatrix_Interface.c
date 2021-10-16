/**
 * Examples_10_DenseMatrix_Interface.c
 * 
 * EPCC, The University of Edinburgh
 * 
 * (c) 2021 The University of Edinburgh
 * 
 * Contributing Authors:
 * Christodoulos Stylianou (c.stylianou@ed.ac.uk)
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * 	http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <Morpheus_Ccl.hpp>

#include <stdio.h>
#include <string.h>

typedef ccl_hmat_dyn dyn;
typedef ccl_hmat_dense mat;

int main() {
  ccl_initialize_without_args();
  {
    mat *A, *B;

    ccl_hmat_dense_create(&A, 2,3, 5);

    ccl_hmat_dense_create_from_hmat_dense(A, &B);

    ccl_hmat_dense_set_values_at(A, 0, 2, -10);

    ccl_hmat_dense_resize(B, 3, 4);
    ccl_hmat_dense_assign(B, 3, 4, 10);

    ccl_hmat_dense_print(A);
    ccl_hmat_dense_print(B);

    ccl_hmat_dense_destroy(&A);
    ccl_hmat_dense_destroy(&B);
  }
  ccl_finalize();

  return 0;
}
