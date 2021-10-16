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
  morpheus_ccl_initialize_without_args();
  {
    mat *A, *B;

    morpheus_ccl_create_hmat_dense(&A, 2,3, 5);

    morpheus_ccl_create_hmat_dense_from_hmat_dense(A, &B);

    morpheus_ccl_set_values_at_hmat_dense(A, 0, 2, -10);

    morpheus_ccl_resize_hmat_dense(B, 3, 4);
    morpheus_ccl_assign_hmat_dense(B, 3, 4, 10);

    morpheus_ccl_print_hmat_dense(A);
    morpheus_ccl_print_hmat_dense(B);

    morpheus_ccl_destroy_hmat_dense(&A);
    morpheus_ccl_destroy_hmat_dense(&B);
  }
  morpheus_ccl_finalize();

  return 0;
}
