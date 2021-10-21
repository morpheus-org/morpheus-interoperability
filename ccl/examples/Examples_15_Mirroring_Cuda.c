/**
 * Examples_15_Mirroring_Cuda.c
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
#include <assert.h>

typedef ccl_dmat_dyn dyn;
typedef ccl_dmat_coo coo;
typedef ccl_dmat_csr csr;
typedef ccl_dmat_dia dia;
typedef ccl_dvec_dense_v vec;

typedef ccl_dmat_coo_hostmirror mirror_coo;
typedef ccl_dmat_csr_hostmirror mirror_csr;
typedef ccl_dmat_dia_hostmirror mirror_dia;
typedef ccl_dvec_dense_v_hostmirror mirror_hvec;
typedef ccl_dmat_dyn_hostmirror mirror_dyn;

coo* ref_coo(){
  coo *A;
  ccl_dmat_coo_create(&A, 4, 3, 6);

  mirror_coo *Am = ccl_dmat_coo_create_mirror_container(A);
  // COO Equivalent:
  // Row Offsets: [0, 1, 2, 0, 2, 1]
  // Column Indices: [0, 1, 2, 0, 2, 1]
  // Values: [10, 20, 30, 40, 50, 60]
  ccl_dmat_coo_hostmirror_set_row_indices_at(Am, 0, 0);
  ccl_dmat_coo_hostmirror_set_row_indices_at(Am, 1, 1);
  ccl_dmat_coo_hostmirror_set_row_indices_at(Am, 2, 2);
  ccl_dmat_coo_hostmirror_set_row_indices_at(Am, 3, 0);
  ccl_dmat_coo_hostmirror_set_row_indices_at(Am, 4, 2);
  ccl_dmat_coo_hostmirror_set_row_indices_at(Am, 5, 1);
  
  ccl_dmat_coo_hostmirror_set_column_indices_at(Am, 0, 0);
  ccl_dmat_coo_hostmirror_set_column_indices_at(Am, 1, 1);
  ccl_dmat_coo_hostmirror_set_column_indices_at(Am, 2, 2);
  ccl_dmat_coo_hostmirror_set_column_indices_at(Am, 3, 0);
  ccl_dmat_coo_hostmirror_set_column_indices_at(Am, 4, 2);
  ccl_dmat_coo_hostmirror_set_column_indices_at(Am, 5, 1);
  
  ccl_dmat_coo_hostmirror_set_values_at(Am, 0, 10);
  ccl_dmat_coo_hostmirror_set_values_at(Am, 1, 20);
  ccl_dmat_coo_hostmirror_set_values_at(Am, 2, 30);
  ccl_dmat_coo_hostmirror_set_values_at(Am, 3, 40);
  ccl_dmat_coo_hostmirror_set_values_at(Am, 4, 50);
  ccl_dmat_coo_hostmirror_set_values_at(Am, 5, 60);

  ccl_dmat_coo_hostmirror_copy_to_dmat_coo(Am, A);

  ccl_dmat_coo_hostmirror_destroy(&Am);
  
  return A;
}

csr* ref_csr(){
  csr *A;
  ccl_dmat_csr_create(&A, 4, 3, 6);

  mirror_csr *Am = ccl_dmat_csr_create_mirror_container(A);
  // CSR Equivalent:
  // Row Offsets: [0, 2, 3, 5, 6]
  // Column Indices: [0, 1, 2, 0, 2, 1]
  // Values: [10, 20, 30, 40, 50, 60]
  ccl_dmat_csr_hostmirror_set_row_offsets_at(Am, 0, 0);
  ccl_dmat_csr_hostmirror_set_row_offsets_at(Am, 1, 2);
  ccl_dmat_csr_hostmirror_set_row_offsets_at(Am, 2, 3);
  ccl_dmat_csr_hostmirror_set_row_offsets_at(Am, 3, 5);
  ccl_dmat_csr_hostmirror_set_row_offsets_at(Am, 4, 6);
  
  ccl_dmat_csr_hostmirror_set_column_indices_at(Am, 0, 0);
  ccl_dmat_csr_hostmirror_set_column_indices_at(Am, 1, 1);
  ccl_dmat_csr_hostmirror_set_column_indices_at(Am, 2, 2);
  ccl_dmat_csr_hostmirror_set_column_indices_at(Am, 3, 0);
  ccl_dmat_csr_hostmirror_set_column_indices_at(Am, 4, 2);
  ccl_dmat_csr_hostmirror_set_column_indices_at(Am, 5, 1);
  
  ccl_dmat_csr_hostmirror_set_values_at(Am, 0, 10);
  ccl_dmat_csr_hostmirror_set_values_at(Am, 1, 20);
  ccl_dmat_csr_hostmirror_set_values_at(Am, 2, 30);
  ccl_dmat_csr_hostmirror_set_values_at(Am, 3, 40);
  ccl_dmat_csr_hostmirror_set_values_at(Am, 4, 50);
  ccl_dmat_csr_hostmirror_set_values_at(Am, 5, 60);

  ccl_dmat_csr_hostmirror_copy_to_dmat_csr(Am, A);

  ccl_dmat_csr_hostmirror_destroy(&Am);
  
  return A;
}

dia* ref_dia(){
  dia *A;
  ccl_dmat_dia_create(&A, 4, 3, 6, 3);

  mirror_dia *Am = ccl_dmat_dia_create_mirror_container(A);
  // Diagonal offsets
  ccl_dmat_dia_hostmirror_set_diagonal_offests_at(Am, 0, -2);
  ccl_dmat_dia_hostmirror_set_diagonal_offests_at(Am, 1, 0);
  ccl_dmat_dia_hostmirror_set_diagonal_offests_at(Am, 2, 1);
  // First Diagonal
  ccl_dmat_dia_hostmirror_set_values_at(Am, 0, 0, -1);
  ccl_dmat_dia_hostmirror_set_values_at(Am, 1, 0, -1);
  ccl_dmat_dia_hostmirror_set_values_at(Am, 2, 0, 40);
  ccl_dmat_dia_hostmirror_set_values_at(Am, 3, 0, 60);
  // Second Diagonal
  ccl_dmat_dia_hostmirror_set_values_at(Am, 0, 1, 10);
  ccl_dmat_dia_hostmirror_set_values_at(Am, 1, 1, 0);
  ccl_dmat_dia_hostmirror_set_values_at(Am, 2, 1, 50);
  ccl_dmat_dia_hostmirror_set_values_at(Am, 3, 1, -2);
  // Third Diagonal
  ccl_dmat_dia_hostmirror_set_values_at(Am, 0, 2, 20);
  ccl_dmat_dia_hostmirror_set_values_at(Am, 1, 2, 30);
  ccl_dmat_dia_hostmirror_set_values_at(Am, 2, 2, -3);
  ccl_dmat_dia_hostmirror_set_values_at(Am, 3, 2, -3);
  
  ccl_dmat_dia_hostmirror_copy_to_dmat_dia(Am, A);

  ccl_dmat_dia_hostmirror_destroy(&Am);

  return A;
}

int main() {
  ccl_initialize_without_args();
  { 
    // Reference Matrix
    //    [10 20 00]
    //    [00 00 30]
    //    [40 00 50]
    //    [00 60 00]
    
    coo *refcoo = ref_coo();
    csr *refcsr = ref_csr();
    dia *refdia = ref_dia();
    
    { 
      mirror_coo *mirror = ccl_dmat_coo_create_mirror(refcoo);
      mirror_coo *shallow_mirror = ccl_dmat_coo_create_mirror_container(refcoo);

      ccl_dmat_coo_copy_to_dmat_coo_hostmirror(refcoo, mirror);
      ccl_dmat_coo_copy_to_dmat_coo_hostmirror(refcoo, shallow_mirror);

      ccl_dmat_coo_hostmirror_print(mirror);
      ccl_dmat_coo_hostmirror_print(shallow_mirror);
      
      ccl_dmat_coo_hostmirror_destroy(&mirror);
      ccl_dmat_coo_hostmirror_destroy(&shallow_mirror);
    }

    // { 
    //   mirror_csr *mirror = ccl_dmat_csr_create_mirror(refcsr);

    //   ccl_dmat_csr_copy_to_dmat_csr_hostmirror(refcsr, mirror);
    //   ccl_dmat_csr_set_values_at(refcsr, 5, -15);
    //   ccl_dmat_csr_hostmirror_print(mirror);
    //   ccl_dmat_csr_set_values_at(refcsr, 5, 60);
    //   ccl_dmat_csr_hostmirror_destroy(&mirror);
    // }

    // { 
    //   mirror_dia *mirror = ccl_dmat_dia_create_mirror(refdia);

    //   ccl_dmat_dia_copy_to_dmat_dia_hostmirror(refdia, mirror);
    //   ccl_dmat_dia_set_values_at(refdia, 3, 0, -15);
    //   ccl_dmat_dia_hostmirror_print(mirror);
    //   ccl_dmat_dia_set_values_at(refdia, 3, 0, 60);
    //   ccl_dmat_dia_hostmirror_destroy(&mirror);
    // }

    // {
    //   dyn *A;
    //   ccl_dmat_dyn_create_from_dmat(refcsr, CSR_FORMAT, &A);
    //   mirror_dyn *mirror = ccl_dmat_dyn_create_mirror(A);

    //   ccl_dmat_csr_copy_to_dmat_dyn_hostmirror(refcsr, mirror);
    //   ccl_dmat_csr_set_values_at(refcsr, 5, -15);
    //   ccl_dmat_dyn_hostmirror_print(mirror);
    //   ccl_dmat_csr_set_values_at(refcsr, 5, 60);

    //   ccl_dmat_dyn_destroy(&A);
    //   ccl_dmat_dyn_hostmirror_destroy(&mirror);
    // }

    ccl_dmat_coo_destroy(&refcoo);
    ccl_dmat_csr_destroy(&refcsr);
    ccl_dmat_dia_destroy(&refdia);
    
  }
  ccl_finalize();

  return 0;
}
