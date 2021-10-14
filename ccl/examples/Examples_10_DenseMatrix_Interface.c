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

#include "Fcl_C.hpp"

#include <stdio.h>
#include <string.h>
typedef fcl_mat_dyn_r64_i32_r_h dyn;
typedef fcl_mat_dense_r64_i32_r_h mat;

int main() {
  c_morpheus_initialize_without_args();
  {
    mat *A, *B;

    c_morpheus_create_mat_dense_r64_i32_r_h(&A, 2,3, 5);

    c_morpheus_create_mat_dense_from_mat_dense_r64_i32_r_h(A, &B);

    c_morpheus_set_values_at_mat_dense_r64_i32_r_h(A, 0, 2, -10);

    c_morpheus_resize_mat_dense_r64_i32_r_h(B, 3, 4);
    c_morpheus_assign_mat_dense_r64_i32_r_h(B, 3, 4, 10);

    c_morpheus_print_mat_dense_r64_i32_r_h(A);
    c_morpheus_print_mat_dense_r64_i32_r_h(B);

    c_morpheus_destroy_mat_dense_r64_i32_r_h(&A);
    c_morpheus_destroy_mat_dense_r64_i32_r_h(&B);
  }
  c_morpheus_finalize();

  return 0;
}