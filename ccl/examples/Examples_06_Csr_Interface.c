/**
 * Examples_06_Csr_Interface.c
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
typedef fcl_mat_dyn_r64_i32_r_h dyn;
typedef fcl_mat_csr_r64_i32_r_h csr;
typedef fcl_vec_dense_r64_i32_r_h vec;

int main() {
  morpheus_ccl_initialize_without_args();
  {
    csr *A, *B;
    vec *x, *y;

    morpheus_ccl_create_mat_csr_r64_i32_r_h(&A, 4, 3, 6);
    // Simple Matrix
    //    [10 20 00]
    //    [00 00 30]
    //    [40 00 50]
    //    [00 60 00]
    // CSR Equivalent:
    // Row Offsets: [0, 2, 3, 5, 6]
    // Column Indices: [0, 1, 2, 0, 2, 1]
    // Values: [10, 20, 30, 40, 50, 60]
    morpheus_ccl_set_row_offsets_at_csr_r64_i32_r_h(A, 0, 0);
    morpheus_ccl_set_row_offsets_at_csr_r64_i32_r_h(A, 1, 2);
    morpheus_ccl_set_row_offsets_at_csr_r64_i32_r_h(A, 2, 3);
    morpheus_ccl_set_row_offsets_at_csr_r64_i32_r_h(A, 3, 5);
    morpheus_ccl_set_row_offsets_at_csr_r64_i32_r_h(A, 4, 6);
    
    morpheus_ccl_set_column_indices_at_csr_r64_i32_r_h(A, 0, 0);
    morpheus_ccl_set_column_indices_at_csr_r64_i32_r_h(A, 1, 1);
    morpheus_ccl_set_column_indices_at_csr_r64_i32_r_h(A, 2, 2);
    morpheus_ccl_set_column_indices_at_csr_r64_i32_r_h(A, 3, 0);
    morpheus_ccl_set_column_indices_at_csr_r64_i32_r_h(A, 4, 2);
    morpheus_ccl_set_column_indices_at_csr_r64_i32_r_h(A, 5, 1);
    
    morpheus_ccl_set_values_at_csr_r64_i32_r_h(A, 0, 10);
    morpheus_ccl_set_values_at_csr_r64_i32_r_h(A, 1, 20);
    morpheus_ccl_set_values_at_csr_r64_i32_r_h(A, 2, 30);
    morpheus_ccl_set_values_at_csr_r64_i32_r_h(A, 3, 40);
    morpheus_ccl_set_values_at_csr_r64_i32_r_h(A, 4, 50);
    morpheus_ccl_set_values_at_csr_r64_i32_r_h(A, 5, 60);

    morpheus_ccl_create_vec_dense_r64_i32_r_h(&x, 3, 3);
    morpheus_ccl_create_vec_dense_r64_i32_r_h(&y, 6, 0);

    morpheus_ccl_multiply_mat_csr_vec_dense_vec_dense_r64_i32_r_h_serial(A, x,
                                                                       y);

    morpheus_ccl_resize_mat_csr_r64_i32_r_h(A, 5, 5, 13);

    morpheus_ccl_create_mat_csr_r64_i32_r_h(&B, 0, 0, 0);
    morpheus_ccl_allocate_mat_csr_from_mat_csr_r64_i32_r_h(A, B);

    // Medium matrix
    // [ 1, -1, -3,  0,  0]
    // [-2,  5,  0,  0,  0]
    // [ 0,  0,  4,  6,  4]
    // [-4,  0,  2,  7,  0]
    // [ 0,  8,  0,  0, -5]
    // CSR Equivalent:
    // Row Offsets: [0, 3, 5, 8, 11, 13]
    // Column Indices: [0, 1, 2, 0, 1, 2, 3, 4, 0, 2, 3, 1, 4]
    // Values: [1, -1, -3, -2, 5, 4, 6, 4, -4, 2, 7, 8, -5]
    morpheus_ccl_set_row_offsets_at_csr_r64_i32_r_h(A, 0, 0);
    morpheus_ccl_set_row_offsets_at_csr_r64_i32_r_h(A, 1, 3);
    morpheus_ccl_set_row_offsets_at_csr_r64_i32_r_h(A, 2, 5);
    morpheus_ccl_set_row_offsets_at_csr_r64_i32_r_h(A, 3, 8);
    morpheus_ccl_set_row_offsets_at_csr_r64_i32_r_h(A, 4, 11);
    morpheus_ccl_set_row_offsets_at_csr_r64_i32_r_h(A, 5, 13);

    morpheus_ccl_set_column_indices_at_csr_r64_i32_r_h(A, 0, 0);
    morpheus_ccl_set_column_indices_at_csr_r64_i32_r_h(A, 1, 1);
    morpheus_ccl_set_column_indices_at_csr_r64_i32_r_h(A, 2, 2);
    morpheus_ccl_set_column_indices_at_csr_r64_i32_r_h(A, 3, 0);
    morpheus_ccl_set_column_indices_at_csr_r64_i32_r_h(A, 4, 1);
    morpheus_ccl_set_column_indices_at_csr_r64_i32_r_h(A, 5, 2);
    morpheus_ccl_set_column_indices_at_csr_r64_i32_r_h(A, 6, 3);
    morpheus_ccl_set_column_indices_at_csr_r64_i32_r_h(A, 7, 4);
    morpheus_ccl_set_column_indices_at_csr_r64_i32_r_h(A, 8, 0);
    morpheus_ccl_set_column_indices_at_csr_r64_i32_r_h(A, 9, 2);
    morpheus_ccl_set_column_indices_at_csr_r64_i32_r_h(A, 10, 3);
    morpheus_ccl_set_column_indices_at_csr_r64_i32_r_h(A, 11, 1);
    morpheus_ccl_set_column_indices_at_csr_r64_i32_r_h(A, 12, 4);
    
    morpheus_ccl_set_values_at_csr_r64_i32_r_h(A, 0, 1);
    morpheus_ccl_set_values_at_csr_r64_i32_r_h(A, 1, -1);
    morpheus_ccl_set_values_at_csr_r64_i32_r_h(A, 2, -3);
    morpheus_ccl_set_values_at_csr_r64_i32_r_h(A, 3, -2);
    morpheus_ccl_set_values_at_csr_r64_i32_r_h(A, 4, 5);
    morpheus_ccl_set_values_at_csr_r64_i32_r_h(A, 5, 4);
    morpheus_ccl_set_values_at_csr_r64_i32_r_h(A, 6, 6);
    morpheus_ccl_set_values_at_csr_r64_i32_r_h(A, 7, 4);
    morpheus_ccl_set_values_at_csr_r64_i32_r_h(A, 8, -4);
    morpheus_ccl_set_values_at_csr_r64_i32_r_h(A, 9, 2);
    morpheus_ccl_set_values_at_csr_r64_i32_r_h(A, 10, 7);
    morpheus_ccl_set_values_at_csr_r64_i32_r_h(A, 11, 8);
    morpheus_ccl_set_values_at_csr_r64_i32_r_h(A, 12, -5);

    morpheus_ccl_print_mat_csr_r64_i32_r_h(B);
    morpheus_ccl_print_mat_csr_r64_i32_r_h(A);
    
    morpheus_ccl_set_nrows_mat_csr_r64_i32_r_h(A, 15);
    morpheus_ccl_set_ncols_mat_csr_r64_i32_r_h(A, 22);
    morpheus_ccl_set_nnnz_mat_csr_r64_i32_r_h(A, 111);

    printf("Csr Enum: %d\n", morpheus_ccl_format_enum_mat_csr_r64_i32_r_h(A));

    printf("Csr Index: %d\n", morpheus_ccl_format_index_mat_csr_r64_i32_r_h(A));

    morpheus_ccl_destroy_mat_csr_r64_i32_r_h(&A);
    morpheus_ccl_destroy_mat_csr_r64_i32_r_h(&B);
    morpheus_ccl_destroy_vec_dense_r64_i32_r_h(&x);
    morpheus_ccl_destroy_vec_dense_r64_i32_r_h(&y);
  }
  morpheus_ccl_finalize();

  return 0;
}
