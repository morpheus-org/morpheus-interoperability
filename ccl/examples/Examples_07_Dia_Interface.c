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

typedef ccl_hmat_dyn dyn;
typedef ccl_hmat_dia dia;
typedef ccl_hvec_dense_v vec;

int main() {
  ccl_initialize_without_args();
  {
    dia *A, *B;
    vec *x, *y;
    
    ccl_hmat_dia_create(&A, 4, 3, 6, 3);

    // Diagonal offsets
    ccl_hmat_dia_set_diagonal_offests_at(A, 0, -2);
    ccl_hmat_dia_set_diagonal_offests_at(A, 1, 0);
    ccl_hmat_dia_set_diagonal_offests_at(A, 2, 1);
    // First Diagonal
    ccl_hmat_dia_set_values_at(A, 0, 0, -1);
    ccl_hmat_dia_set_values_at(A, 1, 0, -1);
    ccl_hmat_dia_set_values_at(A, 2, 0, 40);
    ccl_hmat_dia_set_values_at(A, 3, 0, 60);
    // Second Diagonal
    ccl_hmat_dia_set_values_at(A, 0, 1, 10);
    ccl_hmat_dia_set_values_at(A, 1, 1, 0);
    ccl_hmat_dia_set_values_at(A, 2, 1, 50);
    ccl_hmat_dia_set_values_at(A, 3, 1, -2);
    // Third Diagonal
    ccl_hmat_dia_set_values_at(A, 0, 2, 20);
    ccl_hmat_dia_set_values_at(A, 1, 2, 30);
    ccl_hmat_dia_set_values_at(A, 2, 2, -3);
    ccl_hmat_dia_set_values_at(A, 3, 2, -3);

    ccl_hvec_dense_v_create(&x, 3, 3);
    ccl_hvec_dense_v_create(&y, 4, 0);

    ccl_hmat_dia_hvec_dense_v_multiply(A, x, y);

    ccl_hmat_dia_print(A);

    ccl_hmat_dia_resize(A, 4, 3, 6, 5);

     // Diagonal offsets
    ccl_hmat_dia_set_diagonal_offests_at(A, 0, -3);
    ccl_hmat_dia_set_diagonal_offests_at(A, 1, -2);
    ccl_hmat_dia_set_diagonal_offests_at(A, 2, -1);
    ccl_hmat_dia_set_diagonal_offests_at(A, 3, 0);
    ccl_hmat_dia_set_diagonal_offests_at(A, 4, 2);
    // First Diagonal
    ccl_hmat_dia_set_values_at(A, 0, 0, -1);
    ccl_hmat_dia_set_values_at(A, 1, 0, -1);
    ccl_hmat_dia_set_values_at(A, 2, 0, -1);
    ccl_hmat_dia_set_values_at(A, 3, 0, 40);
    // Second Diagonal
    ccl_hmat_dia_set_values_at(A, 0, 1, -2);
    ccl_hmat_dia_set_values_at(A, 1, 1, -2);
    ccl_hmat_dia_set_values_at(A, 2, 1, 0);
    ccl_hmat_dia_set_values_at(A, 3, 1, 50);
    // Third Diagonal
    ccl_hmat_dia_set_values_at(A, 0, 2, -3);
    ccl_hmat_dia_set_values_at(A, 1, 2, 0);
    ccl_hmat_dia_set_values_at(A, 2, 2, 0);
    ccl_hmat_dia_set_values_at(A, 3, 2, 60);
    // Fourth Diagonal
    ccl_hmat_dia_set_values_at(A, 0, 3, 10);
    ccl_hmat_dia_set_values_at(A, 1, 3, 0);
    ccl_hmat_dia_set_values_at(A, 2, 3, 30);
    ccl_hmat_dia_set_values_at(A, 3, 3, -4);
    // Fifth Diagonal
    ccl_hmat_dia_set_values_at(A, 0, 4, 20);
    ccl_hmat_dia_set_values_at(A, 1, 4, -5);
    ccl_hmat_dia_set_values_at(A, 2, 4, -5);
    ccl_hmat_dia_set_values_at(A, 3, 4, -5);

    ccl_hmat_dia_print(A);

    ccl_hmat_dia_create(&B, 0, 0, 0, 0);
    ccl_hmat_dia_allocate_from_hmat_dia(A, B);
    // Make sure offsets are same in order to get same positional values
    ccl_hmat_dia_set_diagonal_offests_at(B, 0, -3);
    ccl_hmat_dia_set_diagonal_offests_at(B, 1, -2);
    ccl_hmat_dia_set_diagonal_offests_at(B, 2, -1);
    ccl_hmat_dia_set_diagonal_offests_at(B, 3, 0);
    ccl_hmat_dia_set_diagonal_offests_at(B, 4, 2);
    ccl_hmat_dia_set_values_at(B, 0, 4, 120);

    ccl_hmat_dia_print(B);
    ccl_hmat_dia_print(A);

    printf("%d\t%d\t%d\t%d\t%d\n", ccl_hmat_dia_nrows(A),
                                   ccl_hmat_dia_ncols(A),
                                   ccl_hmat_dia_nnnz(A),
                                   ccl_hmat_dia_ndiags(A),
                                   ccl_hmat_dia_alignment(A));

    printf("%d\t%d\t%d\t%d\t%d\n", ccl_hmat_dia_nrows(B),
                                   ccl_hmat_dia_ncols(B),
                                   ccl_hmat_dia_nnnz(B),
                                   ccl_hmat_dia_ndiags(B),
                                   ccl_hmat_dia_alignment(B));
    
    ccl_hmat_dia_set_nrows(A, 15);
    ccl_hmat_dia_set_ncols(A, 22);
    ccl_hmat_dia_set_nnnz(A, 111);
    ccl_hmat_dia_set_ndiags(A, 8);
    ccl_hmat_dia_set_alignment(A, 64);

    printf("%d\t%d\t%d\t%d\t%d\n", ccl_hmat_dia_nrows(A),
                                   ccl_hmat_dia_ncols(A),
                                   ccl_hmat_dia_nnnz(A),
                                   ccl_hmat_dia_ndiags(A),
                                   ccl_hmat_dia_alignment(A));

    printf("dia Enum: %d\n", ccl_hmat_dia_format_enum(A));

    printf("dia Index: %d\n", ccl_hmat_dia_format_index(A));

    ccl_hmat_dia_destroy(&A);
    ccl_hmat_dia_destroy(&B);
    ccl_hvec_dense_v_destroy(&x);
    ccl_hvec_dense_v_destroy(&y);
  }
  ccl_finalize();

  return 0;
}
