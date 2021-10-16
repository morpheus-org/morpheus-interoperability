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

typedef ccl_hmat_dyn dyn;
typedef ccl_hmat_csr csr;
typedef ccl_hvec_dense_v vec;

int main() {
  ccl_initialize_without_args();
  {
    csr *A, *B;
    vec *x, *y;

    ccl_hmat_csr_create(&A, 4, 3, 6);
    // Simple Matrix
    //    [10 20 00]
    //    [00 00 30]
    //    [40 00 50]
    //    [00 60 00]
    // CSR Equivalent:
    // Row Offsets: [0, 2, 3, 5, 6]
    // Column Indices: [0, 1, 2, 0, 2, 1]
    // Values: [10, 20, 30, 40, 50, 60]
    ccl_hmat_csr_set_row_offsets_at(A, 0, 0);
    ccl_hmat_csr_set_row_offsets_at(A, 1, 2);
    ccl_hmat_csr_set_row_offsets_at(A, 2, 3);
    ccl_hmat_csr_set_row_offsets_at(A, 3, 5);
    ccl_hmat_csr_set_row_offsets_at(A, 4, 6);
    
    ccl_hmat_csr_set_column_indices_at(A, 0, 0);
    ccl_hmat_csr_set_column_indices_at(A, 1, 1);
    ccl_hmat_csr_set_column_indices_at(A, 2, 2);
    ccl_hmat_csr_set_column_indices_at(A, 3, 0);
    ccl_hmat_csr_set_column_indices_at(A, 4, 2);
    ccl_hmat_csr_set_column_indices_at(A, 5, 1);
    
    ccl_hmat_csr_set_values_at(A, 0, 10);
    ccl_hmat_csr_set_values_at(A, 1, 20);
    ccl_hmat_csr_set_values_at(A, 2, 30);
    ccl_hmat_csr_set_values_at(A, 3, 40);
    ccl_hmat_csr_set_values_at(A, 4, 50);
    ccl_hmat_csr_set_values_at(A, 5, 60);

    ccl_hvec_dense_v_create(&x, 3, 3);
    ccl_hvec_dense_v_create(&y, 6, 0);

    ccl_hmat_csr_hvec_dense_v_multiply(A, x, y);

    ccl_hmat_csr_resize(A, 5, 5, 13);

    ccl_hmat_csr_create(&B, 0, 0, 0);
    ccl_hmat_csr_allocate_from_hmat_csr(A, B);

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
    ccl_hmat_csr_set_row_offsets_at(A, 0, 0);
    ccl_hmat_csr_set_row_offsets_at(A, 1, 3);
    ccl_hmat_csr_set_row_offsets_at(A, 2, 5);
    ccl_hmat_csr_set_row_offsets_at(A, 3, 8);
    ccl_hmat_csr_set_row_offsets_at(A, 4, 11);
    ccl_hmat_csr_set_row_offsets_at(A, 5, 13);

    ccl_hmat_csr_set_column_indices_at(A, 0, 0);
    ccl_hmat_csr_set_column_indices_at(A, 1, 1);
    ccl_hmat_csr_set_column_indices_at(A, 2, 2);
    ccl_hmat_csr_set_column_indices_at(A, 3, 0);
    ccl_hmat_csr_set_column_indices_at(A, 4, 1);
    ccl_hmat_csr_set_column_indices_at(A, 5, 2);
    ccl_hmat_csr_set_column_indices_at(A, 6, 3);
    ccl_hmat_csr_set_column_indices_at(A, 7, 4);
    ccl_hmat_csr_set_column_indices_at(A, 8, 0);
    ccl_hmat_csr_set_column_indices_at(A, 9, 2);
    ccl_hmat_csr_set_column_indices_at(A, 10, 3);
    ccl_hmat_csr_set_column_indices_at(A, 11, 1);
    ccl_hmat_csr_set_column_indices_at(A, 12, 4);
    
    ccl_hmat_csr_set_values_at(A, 0, 1);
    ccl_hmat_csr_set_values_at(A, 1, -1);
    ccl_hmat_csr_set_values_at(A, 2, -3);
    ccl_hmat_csr_set_values_at(A, 3, -2);
    ccl_hmat_csr_set_values_at(A, 4, 5);
    ccl_hmat_csr_set_values_at(A, 5, 4);
    ccl_hmat_csr_set_values_at(A, 6, 6);
    ccl_hmat_csr_set_values_at(A, 7, 4);
    ccl_hmat_csr_set_values_at(A, 8, -4);
    ccl_hmat_csr_set_values_at(A, 9, 2);
    ccl_hmat_csr_set_values_at(A, 10, 7);
    ccl_hmat_csr_set_values_at(A, 11, 8);
    ccl_hmat_csr_set_values_at(A, 12, -5);

    ccl_hmat_csr_print(B);
    ccl_hmat_csr_print(A);
    
    ccl_hmat_csr_set_nrows(A, 15);
    ccl_hmat_csr_set_ncols(A, 22);
    ccl_hmat_csr_set_nnnz(A, 111);

    printf("Csr Enum: %d\n", ccl_hmat_csr_format_enum(A));

    printf("Csr Index: %d\n", ccl_hmat_csr_format_index(A));

    ccl_hmat_csr_destroy(&A);
    ccl_hmat_csr_destroy(&B);
    ccl_hvec_dense_v_destroy(&x);
    ccl_hvec_dense_v_destroy(&y);
  }
  ccl_finalize();

  return 0;
}
