/**
 * Examples_05_Coo_Interface.c
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
typedef fcl_mat_coo_r64_i32_r_h coo;
typedef fcl_vec_dense_r64_i32_r_h vec;

int main() {
  c_morpheus_initialize_without_args();
  {
    coo *A, *B;
    vec *x, *y;

    c_morpheus_create_mat_coo_r64_i32_r_h(&A, 5, 3, 3);

    int i;
    for(i=0; i<3; i++){
      c_morpheus_set_row_indices_at_coo_r64_i32_r_h(A, i, i);
      c_morpheus_set_column_indices_at_coo_r64_i32_r_h(A, i, i);
      c_morpheus_set_values_at_coo_r64_i32_r_h(A, i, i);
    }
    c_morpheus_set_row_indices_at_coo_r64_i32_r_h(A, 0, 15);

    c_morpheus_create_vec_dense_r64_i32_r_h(&x, 3, 3);
    c_morpheus_create_vec_dense_r64_i32_r_h(&y, 5, 0);

    c_morpheus_multiply_mat_coo_vec_dense_vec_dense_r64_i32_r_h_serial(A, x,
                                                                       y);

    c_morpheus_resize_mat_coo_r64_i32_r_h(A, 10, 10, 64);

    c_morpheus_create_mat_coo_r64_i32_r_h(&B, 0,0,0);
    c_morpheus_allocate_mat_coo_from_mat_coo_r64_i32_r_h(A, B);

    for(i=0; i<64; i++){
      c_morpheus_set_row_indices_at_coo_r64_i32_r_h(B, i, i);
      c_morpheus_set_column_indices_at_coo_r64_i32_r_h(B, i, i);
      c_morpheus_set_values_at_coo_r64_i32_r_h(B, i, i);
    }
    c_morpheus_set_values_at_coo_r64_i32_r_h(B, 63, -55);

    c_morpheus_print_mat_coo_r64_i32_r_h(B);
    c_morpheus_print_mat_coo_r64_i32_r_h(A);
    
    c_morpheus_set_nrows_mat_coo_r64_i32_r_h(A, 15);
    c_morpheus_set_ncols_mat_coo_r64_i32_r_h(A, 22);
    c_morpheus_set_nnnz_mat_coo_r64_i32_r_h(A, 111);

    printf("Coo Enum: %d\n", c_morpheus_format_enum_mat_coo_r64_i32_r_h(A));

    printf("Coo Index: %d\n", c_morpheus_format_index_mat_coo_r64_i32_r_h(A));

    c_morpheus_destroy_mat_coo_r64_i32_r_h(&A);
    c_morpheus_destroy_mat_coo_r64_i32_r_h(&B);
    c_morpheus_destroy_vec_dense_r64_i32_r_h(&x);
    c_morpheus_destroy_vec_dense_r64_i32_r_h(&y);
  }
  c_morpheus_finalize();

  return 0;
}
