/**
 * Examples_11_Dynamic_Interface.c
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
typedef ccl_mat_dyn dyn;
typedef ccl_mat_coo coo;
typedef ccl_mat_csr csr;
typedef ccl_mat_dia dia;
typedef ccl_vec_dense vec;

int main() {
  morpheus_ccl_initialize_without_args();
  {
    dia *Adia;
    csr *Acsr;
    vec *x, *y;
    dyn *A;
    
    morpheus_ccl_create_mat_dia(&Adia, 4, 3, 6, 3);

    // Diagonal offsets
    morpheus_ccl_set_diagonal_offests_at_dia(Adia, 0, -2);
    morpheus_ccl_set_diagonal_offests_at_dia(Adia, 1, 0);
    morpheus_ccl_set_diagonal_offests_at_dia(Adia, 2, 1);
    // First Diagonal
    morpheus_ccl_set_values_at_dia(Adia, 0, 0, -1);
    morpheus_ccl_set_values_at_dia(Adia, 1, 0, -1);
    morpheus_ccl_set_values_at_dia(Adia, 2, 0, 40);
    morpheus_ccl_set_values_at_dia(Adia, 3, 0, 60);
    // Second Diagonal
    morpheus_ccl_set_values_at_dia(Adia, 0, 1, 10);
    morpheus_ccl_set_values_at_dia(Adia, 1, 1, 0);
    morpheus_ccl_set_values_at_dia(Adia, 2, 1, 50);
    morpheus_ccl_set_values_at_dia(Adia, 3, 1, -2);
    // Third Diagonal
    morpheus_ccl_set_values_at_dia(Adia, 0, 2, 20);
    morpheus_ccl_set_values_at_dia(Adia, 1, 2, 30);
    morpheus_ccl_set_values_at_dia(Adia, 2, 2, -3);
    morpheus_ccl_set_values_at_dia(Adia, 3, 2, -3);

    morpheus_ccl_create_mat_csr(&Acsr, 4, 3, 6);
    // Simple Matrix
    //    [10 20 00]
    //    [00 00 30]
    //    [40 00 50]
    //    [00 60 00]
    // CSR Equivalent:
    // Row Offsets: [0, 2, 3, 5, 6]
    // Column Indices: [0, 1, 2, 0, 2, 1]
    // Values: [10, 20, 30, 40, 50, 60]
    morpheus_ccl_set_row_offsets_at_csr(Acsr, 0, 0);
    morpheus_ccl_set_row_offsets_at_csr(Acsr, 1, 2);
    morpheus_ccl_set_row_offsets_at_csr(Acsr, 2, 3);
    morpheus_ccl_set_row_offsets_at_csr(Acsr, 3, 5);
    morpheus_ccl_set_row_offsets_at_csr(Acsr, 4, 6);
    
    morpheus_ccl_set_column_indices_at_csr(Acsr, 0, 0);
    morpheus_ccl_set_column_indices_at_csr(Acsr, 1, 1);
    morpheus_ccl_set_column_indices_at_csr(Acsr, 2, 2);
    morpheus_ccl_set_column_indices_at_csr(Acsr, 3, 0);
    morpheus_ccl_set_column_indices_at_csr(Acsr, 4, 2);
    morpheus_ccl_set_column_indices_at_csr(Acsr, 5, 1);
    
    morpheus_ccl_set_values_at_csr(Acsr, 0, 10);
    morpheus_ccl_set_values_at_csr(Acsr, 1, 20);
    morpheus_ccl_set_values_at_csr(Acsr, 2, 30);
    morpheus_ccl_set_values_at_csr(Acsr, 3, 40);
    morpheus_ccl_set_values_at_csr(Acsr, 4, 50);
    morpheus_ccl_set_values_at_csr(Acsr, 5, 60);

    morpheus_ccl_create_vec_dense(&x, 3, 3);
    morpheus_ccl_create_vec_dense(&y, 4, 0);

    morpheus_ccl_create_mat_dyn_from_mat(Adia, DIA_FORMAT, &A);

    morpheus_ccl_multiply_mat_dyn_vec_dense_vec_dense_serial(A, x,
                                                                       y);

    morpheus_ccl_print_mat_dyn(A);

    morpheus_ccl_assign_mat_dyn_from_mat(Acsr, CSR_FORMAT, A);
    morpheus_ccl_print_mat_dyn(A);

    morpheus_ccl_destroy_mat_dia(&Adia);
    morpheus_ccl_destroy_vec_dense(&x);
    morpheus_ccl_destroy_vec_dense(&y);
  }
  morpheus_ccl_finalize();

  return 0;
}
