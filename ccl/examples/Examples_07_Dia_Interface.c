/**
 * Examples_07_Dia_Interface.c
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
typedef fcl_mat_dia_r64_i32_r_h dia;
typedef fcl_vec_dense_r64_i32_r_h vec;

int main() {
  morpheus_ccl_initialize_without_args();
  {
    dia *A, *B;
    vec *x, *y;
    
    morpheus_ccl_create_mat_dia_r64_i32_r_h(&A, 4, 3, 6, 3);

    // Diagonal offsets
    morpheus_ccl_set_diagonal_offests_at_dia_r64_i32_r_h(A, 0, -2);
    morpheus_ccl_set_diagonal_offests_at_dia_r64_i32_r_h(A, 1, 0);
    morpheus_ccl_set_diagonal_offests_at_dia_r64_i32_r_h(A, 2, 1);
    // First Diagonal
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 0, 0, -1);
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 1, 0, -1);
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 2, 0, 40);
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 3, 0, 60);
    // Second Diagonal
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 0, 1, 10);
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 1, 1, 0);
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 2, 1, 50);
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 3, 1, -2);
    // Third Diagonal
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 0, 2, 20);
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 1, 2, 30);
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 2, 2, -3);
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 3, 2, -3);

    morpheus_ccl_create_vec_dense_r64_i32_r_h(&x, 3, 3);
    morpheus_ccl_create_vec_dense_r64_i32_r_h(&y, 4, 0);

    morpheus_ccl_multiply_mat_dia_vec_dense_vec_dense_r64_i32_r_h_serial(A, x,
                                                                       y);

    morpheus_ccl_print_mat_dia_r64_i32_r_h(A);

    morpheus_ccl_resize_mat_dia_r64_i32_r_h(A, 4, 3, 6, 5);

     // Diagonal offsets
    morpheus_ccl_set_diagonal_offests_at_dia_r64_i32_r_h(A, 0, -3);
    morpheus_ccl_set_diagonal_offests_at_dia_r64_i32_r_h(A, 1, -2);
    morpheus_ccl_set_diagonal_offests_at_dia_r64_i32_r_h(A, 2, -1);
    morpheus_ccl_set_diagonal_offests_at_dia_r64_i32_r_h(A, 3, 0);
    morpheus_ccl_set_diagonal_offests_at_dia_r64_i32_r_h(A, 4, 2);
    // First Diagonal
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 0, 0, -1);
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 1, 0, -1);
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 2, 0, -1);
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 3, 0, 40);
    // Second Diagonal
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 0, 1, -2);
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 1, 1, -2);
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 2, 1, 0);
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 3, 1, 50);
    // Third Diagonal
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 0, 2, -3);
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 1, 2, 0);
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 2, 2, 0);
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 3, 2, 60);
    // Fourth Diagonal
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 0, 3, 10);
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 1, 3, 0);
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 2, 3, 30);
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 3, 3, -4);
    // Fifth Diagonal
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 0, 4, 20);
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 1, 4, -5);
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 2, 4, -5);
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(A, 3, 4, -5);

    morpheus_ccl_print_mat_dia_r64_i32_r_h(A);


    morpheus_ccl_create_mat_dia_r64_i32_r_h(&B, 0, 0, 0, 0);
    morpheus_ccl_allocate_mat_dia_from_mat_dia_r64_i32_r_h(A, B);
    // Make sure offsets are same in order to get same positional values
    morpheus_ccl_set_diagonal_offests_at_dia_r64_i32_r_h(B, 0, -3);
    morpheus_ccl_set_diagonal_offests_at_dia_r64_i32_r_h(B, 1, -2);
    morpheus_ccl_set_diagonal_offests_at_dia_r64_i32_r_h(B, 2, -1);
    morpheus_ccl_set_diagonal_offests_at_dia_r64_i32_r_h(B, 3, 0);
    morpheus_ccl_set_diagonal_offests_at_dia_r64_i32_r_h(B, 4, 2);
    morpheus_ccl_set_values_at_dia_r64_i32_r_h(B, 0, 4, 120);

    morpheus_ccl_print_mat_dia_r64_i32_r_h(B);
    morpheus_ccl_print_mat_dia_r64_i32_r_h(A);

    printf("%d\t%d\t%d\t%d\t%d\n", morpheus_ccl_nrows_mat_dia_r64_i32_r_h(A),
                                   morpheus_ccl_ncols_mat_dia_r64_i32_r_h(A),
                                   morpheus_ccl_nnnz_mat_dia_r64_i32_r_h(A),
                                   morpheus_ccl_ndiags_mat_dia_r64_i32_r_h(A),
                                   morpheus_ccl_alignment_mat_dia_r64_i32_r_h(A));

    printf("%d\t%d\t%d\t%d\t%d\n", morpheus_ccl_nrows_mat_dia_r64_i32_r_h(B),
                                   morpheus_ccl_ncols_mat_dia_r64_i32_r_h(B),
                                   morpheus_ccl_nnnz_mat_dia_r64_i32_r_h(B),
                                   morpheus_ccl_ndiags_mat_dia_r64_i32_r_h(B),
                                   morpheus_ccl_alignment_mat_dia_r64_i32_r_h(B));
    
    morpheus_ccl_set_nrows_mat_dia_r64_i32_r_h(A, 15);
    morpheus_ccl_set_ncols_mat_dia_r64_i32_r_h(A, 22);
    morpheus_ccl_set_nnnz_mat_dia_r64_i32_r_h(A, 111);
    morpheus_ccl_set_ndiags_mat_dia_r64_i32_r_h(A, 8);
    morpheus_ccl_set_alignment_mat_dia_r64_i32_r_h(A, 64);

    printf("%d\t%d\t%d\t%d\t%d\n", morpheus_ccl_nrows_mat_dia_r64_i32_r_h(A),
                                   morpheus_ccl_ncols_mat_dia_r64_i32_r_h(A),
                                   morpheus_ccl_nnnz_mat_dia_r64_i32_r_h(A),
                                   morpheus_ccl_ndiags_mat_dia_r64_i32_r_h(A),
                                   morpheus_ccl_alignment_mat_dia_r64_i32_r_h(A));

    printf("dia Enum: %d\n", morpheus_ccl_format_enum_mat_dia_r64_i32_r_h(A));

    printf("dia Index: %d\n", morpheus_ccl_format_index_mat_dia_r64_i32_r_h(A));

    morpheus_ccl_destroy_mat_dia_r64_i32_r_h(&A);
    morpheus_ccl_destroy_mat_dia_r64_i32_r_h(&B);
    morpheus_ccl_destroy_vec_dense_r64_i32_r_h(&x);
    morpheus_ccl_destroy_vec_dense_r64_i32_r_h(&y);
  }
  morpheus_ccl_finalize();

  return 0;
}
