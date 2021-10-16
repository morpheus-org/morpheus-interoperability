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

typedef ccl_hmat_dyn dyn;
typedef ccl_hmat_coo coo;
typedef ccl_hmat_csr csr;
typedef ccl_hmat_dia dia;
typedef ccl_hvec_dense_v vec;

int main() {
  ccl_initialize_without_args();
  {
    dia *Adia;
    csr *Acsr;
    vec *x, *y;
    dyn *A;
    
    ccl_hmat_dia_create(&Adia, 4, 3, 6, 3);

    // Diagonal offsets
    ccl_hmat_dia_set_diagonal_offests_at(Adia, 0, -2);
    ccl_hmat_dia_set_diagonal_offests_at(Adia, 1, 0);
    ccl_hmat_dia_set_diagonal_offests_at(Adia, 2, 1);
    // First Diagonal
    ccl_hmat_dia_set_values_at(Adia, 0, 0, -1);
    ccl_hmat_dia_set_values_at(Adia, 1, 0, -1);
    ccl_hmat_dia_set_values_at(Adia, 2, 0, 40);
    ccl_hmat_dia_set_values_at(Adia, 3, 0, 60);
    // Second Diagonal
    ccl_hmat_dia_set_values_at(Adia, 0, 1, 10);
    ccl_hmat_dia_set_values_at(Adia, 1, 1, 0);
    ccl_hmat_dia_set_values_at(Adia, 2, 1, 50);
    ccl_hmat_dia_set_values_at(Adia, 3, 1, -2);
    // Third Diagonal
    ccl_hmat_dia_set_values_at(Adia, 0, 2, 20);
    ccl_hmat_dia_set_values_at(Adia, 1, 2, 30);
    ccl_hmat_dia_set_values_at(Adia, 2, 2, -3);
    ccl_hmat_dia_set_values_at(Adia, 3, 2, -3);

    ccl_hmat_csr_create(&Acsr, 4, 3, 6);
    // Simple Matrix
    //    [10 20 00]
    //    [00 00 30]
    //    [40 00 50]
    //    [00 60 00]
    // CSR Equivalent:
    // Row Offsets: [0, 2, 3, 5, 6]
    // Column Indices: [0, 1, 2, 0, 2, 1]
    // Values: [10, 20, 30, 40, 50, 60]
    ccl_hmat_csr_set_row_offsets_at(Acsr, 0, 0);
    ccl_hmat_csr_set_row_offsets_at(Acsr, 1, 2);
    ccl_hmat_csr_set_row_offsets_at(Acsr, 2, 3);
    ccl_hmat_csr_set_row_offsets_at(Acsr, 3, 5);
    ccl_hmat_csr_set_row_offsets_at(Acsr, 4, 6);
    
    ccl_hmat_csr_set_column_indices_at(Acsr, 0, 0);
    ccl_hmat_csr_set_column_indices_at(Acsr, 1, 1);
    ccl_hmat_csr_set_column_indices_at(Acsr, 2, 2);
    ccl_hmat_csr_set_column_indices_at(Acsr, 3, 0);
    ccl_hmat_csr_set_column_indices_at(Acsr, 4, 2);
    ccl_hmat_csr_set_column_indices_at(Acsr, 5, 1);
    
    ccl_hmat_csr_set_values_at(Acsr, 0, 10);
    ccl_hmat_csr_set_values_at(Acsr, 1, 20);
    ccl_hmat_csr_set_values_at(Acsr, 2, 30);
    ccl_hmat_csr_set_values_at(Acsr, 3, 40);
    ccl_hmat_csr_set_values_at(Acsr, 4, 50);
    ccl_hmat_csr_set_values_at(Acsr, 5, 60);

    ccl_hvec_dense_v_create(&x, 3, 3);
    ccl_hvec_dense_v_create(&y, 4, 0);

    ccl_hmat_dyn_create_from_hmat(Adia, DIA_FORMAT, &A);

    ccl_hmat_dyn_hvec_dense_v_multiply(A, x, y);

    ccl_hmat_dyn_print(A);

    ccl_hmat_dyn_assign_from_hmat(Acsr, CSR_FORMAT, A);
    ccl_hmat_dyn_print(A);

    ccl_hmat_dia_destroy(&Adia);
    ccl_hvec_dense_v_destroy(&x);
    ccl_hvec_dense_v_destroy(&y);
  }
  ccl_finalize();

  return 0;
}
