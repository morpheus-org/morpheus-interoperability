/**
 * Examples_12_Convert.c
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

typedef fcl_mat_dyn_r64_i32_r_h dyn;
typedef fcl_mat_coo_r64_i32_r_h coo;
typedef fcl_mat_csr_r64_i32_r_h csr;
typedef fcl_mat_dia_r64_i32_r_h dia;
typedef fcl_vec_dense_r64_i32_r_h vec;

void coo_check_same(coo* A, coo* B){
  const fcl_i32_t nnnz = c_morpheus_nnnz_mat_coo_r64_i32_r_h(A);

  for(int i=0; i<nnnz; i++){
    assert(c_morpheus_row_indices_at_coo_r64_i32_r_h(A,i) != c_morpheus_row_indices_at_coo_r64_i32_r_h(B,i));
    assert(c_morpheus_column_indices_at_coo_r64_i32_r_h(A,i) != c_morpheus_column_indices_at_coo_r64_i32_r_h(B,i));
    assert(c_morpheus_values_at_coo_r64_i32_r_h(A,i) != c_morpheus_values_at_coo_r64_i32_r_h(B,i));
  }
}

void csr_check_same(csr* A, csr* B){
  const fcl_i32_t nrows = c_morpheus_nrows_mat_csr_r64_i32_r_h(A);
  const fcl_i32_t nnnz = c_morpheus_nnnz_mat_csr_r64_i32_r_h(A);

  for(int i=0; i<nrows+1; i++){
    assert(c_morpheus_row_offsets_at_csr_r64_i32_r_h(A,i) != c_morpheus_row_offsets_at_csr_r64_i32_r_h(B,i));
  }

  for(int i=0; i<nnnz; i++){
    assert(c_morpheus_column_indices_at_csr_r64_i32_r_h(A,i) != c_morpheus_column_indices_at_csr_r64_i32_r_h(B,i));
    assert(c_morpheus_values_at_csr_r64_i32_r_h(A,i) != c_morpheus_values_at_csr_r64_i32_r_h(B,i));
  }
}

void dia_check_same(dia* A, dia* B){

  fcl_mat_dense_r64_i32_r_h *Avals = c_morpheus_values_dia_r64_i32_r_h(A);
  fcl_mat_dense_r64_i32_r_h *Bvals = c_morpheus_values_dia_r64_i32_r_h(B);

  fcl_i32_t Avals_rows = c_morpheus_nrows_mat_dense_r64_i32_r_h(Avals);
  fcl_i32_t Avals_ncols = c_morpheus_ncols_mat_dense_r64_i32_r_h(Avals);
  fcl_i32_t ndiags = c_morpheus_ndiags_mat_dia_r64_i32_r_h(A);

  for(int i=0; i<ndiags; i++){
    assert(c_morpheus_diagonal_offests_at_dia_r64_i32_r_h(A,i) != c_morpheus_diagonal_offests_at_dia_r64_i32_r_h(B,i));
  }

  for(int i=0; i<Avals_rows; i++){
    for(int j=0; j<Avals_ncols; j++){
      assert(c_morpheus_values_at_dia_r64_i32_r_h(A,i,j) != c_morpheus_values_at_dia_r64_i32_r_h(B,i,j));
    }
  }
}

coo* ref_coo(){
  coo *A;
  c_morpheus_create_mat_coo_r64_i32_r_h(&A, 4, 3, 6);
  // COO Equivalent:
  // Row Offsets: [0, 1, 2, 0, 2, 1]
  // Column Indices: [0, 1, 2, 0, 2, 1]
  // Values: [10, 20, 30, 40, 50, 60]
  c_morpheus_set_row_indices_at_coo_r64_i32_r_h(A, 0, 0);
  c_morpheus_set_row_indices_at_coo_r64_i32_r_h(A, 1, 1);
  c_morpheus_set_row_indices_at_coo_r64_i32_r_h(A, 2, 2);
  c_morpheus_set_row_indices_at_coo_r64_i32_r_h(A, 3, 0);
  c_morpheus_set_row_indices_at_coo_r64_i32_r_h(A, 4, 2);
  c_morpheus_set_row_indices_at_coo_r64_i32_r_h(A, 5, 1);
  
  c_morpheus_set_column_indices_at_coo_r64_i32_r_h(A, 0, 0);
  c_morpheus_set_column_indices_at_coo_r64_i32_r_h(A, 1, 1);
  c_morpheus_set_column_indices_at_coo_r64_i32_r_h(A, 2, 2);
  c_morpheus_set_column_indices_at_coo_r64_i32_r_h(A, 3, 0);
  c_morpheus_set_column_indices_at_coo_r64_i32_r_h(A, 4, 2);
  c_morpheus_set_column_indices_at_coo_r64_i32_r_h(A, 5, 1);
  
  c_morpheus_set_values_at_coo_r64_i32_r_h(A, 0, 10);
  c_morpheus_set_values_at_coo_r64_i32_r_h(A, 1, 20);
  c_morpheus_set_values_at_coo_r64_i32_r_h(A, 2, 30);
  c_morpheus_set_values_at_coo_r64_i32_r_h(A, 3, 40);
  c_morpheus_set_values_at_coo_r64_i32_r_h(A, 4, 50);
  c_morpheus_set_values_at_coo_r64_i32_r_h(A, 5, 60);
  
  return A;
}

csr* ref_csr(){
  csr *A;
  c_morpheus_create_mat_csr_r64_i32_r_h(&A, 4, 3, 6);
  // CSR Equivalent:
  // Row Offsets: [0, 2, 3, 5, 6]
  // Column Indices: [0, 1, 2, 0, 2, 1]
  // Values: [10, 20, 30, 40, 50, 60]
  c_morpheus_set_row_offsets_at_csr_r64_i32_r_h(A, 0, 0);
  c_morpheus_set_row_offsets_at_csr_r64_i32_r_h(A, 1, 2);
  c_morpheus_set_row_offsets_at_csr_r64_i32_r_h(A, 2, 3);
  c_morpheus_set_row_offsets_at_csr_r64_i32_r_h(A, 3, 5);
  c_morpheus_set_row_offsets_at_csr_r64_i32_r_h(A, 4, 6);
  
  c_morpheus_set_column_indices_at_csr_r64_i32_r_h(A, 0, 0);
  c_morpheus_set_column_indices_at_csr_r64_i32_r_h(A, 1, 1);
  c_morpheus_set_column_indices_at_csr_r64_i32_r_h(A, 2, 2);
  c_morpheus_set_column_indices_at_csr_r64_i32_r_h(A, 3, 0);
  c_morpheus_set_column_indices_at_csr_r64_i32_r_h(A, 4, 2);
  c_morpheus_set_column_indices_at_csr_r64_i32_r_h(A, 5, 1);
  
  c_morpheus_set_values_at_csr_r64_i32_r_h(A, 0, 10);
  c_morpheus_set_values_at_csr_r64_i32_r_h(A, 1, 20);
  c_morpheus_set_values_at_csr_r64_i32_r_h(A, 2, 30);
  c_morpheus_set_values_at_csr_r64_i32_r_h(A, 3, 40);
  c_morpheus_set_values_at_csr_r64_i32_r_h(A, 4, 50);
  c_morpheus_set_values_at_csr_r64_i32_r_h(A, 5, 60);
  
  return A;
}

dia* ref_dia(){
  dia *A;

  c_morpheus_create_mat_dia_r64_i32_r_h(&A, 4, 3, 6, 3);

  // Diagonal offsets
  c_morpheus_set_diagonal_offests_at_dia_r64_i32_r_h(A, 0, -2);
  c_morpheus_set_diagonal_offests_at_dia_r64_i32_r_h(A, 1, 0);
  c_morpheus_set_diagonal_offests_at_dia_r64_i32_r_h(A, 2, 1);
  // First Diagonal
  c_morpheus_set_values_at_dia_r64_i32_r_h(A, 0, 0, -1);
  c_morpheus_set_values_at_dia_r64_i32_r_h(A, 1, 0, -1);
  c_morpheus_set_values_at_dia_r64_i32_r_h(A, 2, 0, 40);
  c_morpheus_set_values_at_dia_r64_i32_r_h(A, 3, 0, 60);
  // Second Diagonal
  c_morpheus_set_values_at_dia_r64_i32_r_h(A, 0, 1, 10);
  c_morpheus_set_values_at_dia_r64_i32_r_h(A, 1, 1, 0);
  c_morpheus_set_values_at_dia_r64_i32_r_h(A, 2, 1, 50);
  c_morpheus_set_values_at_dia_r64_i32_r_h(A, 3, 1, -2);
  // Third Diagonal
  c_morpheus_set_values_at_dia_r64_i32_r_h(A, 0, 2, 20);
  c_morpheus_set_values_at_dia_r64_i32_r_h(A, 1, 2, 30);
  c_morpheus_set_values_at_dia_r64_i32_r_h(A, 2, 2, -3);
  c_morpheus_set_values_at_dia_r64_i32_r_h(A, 3, 2, -3);
  
  return A;
}

int main() {
  c_morpheus_initialize_without_args();
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
      coo *Acoo;
      csr *Acsr;
      dia *Adia;
      c_morpheus_create_default_mat_coo_r64_i32_r_h(&Acoo);
      c_morpheus_create_default_mat_csr_r64_i32_r_h(&Acsr);
      c_morpheus_create_default_mat_dia_r64_i32_r_h(&Adia);
      
      // csr->csr
      c_morpheus_convert_mat_csr_to_mat_csr_r64_i32_r_h_serial(refcsr, Acsr);
      csr_check_same(refcsr,Acsr);

      // csr->coo, coo->dia
      c_morpheus_convert_mat_csr_to_mat_coo_r64_i32_r_h_serial(refcsr, Acoo);
      coo_check_same(refcoo, Acoo);

      c_morpheus_convert_mat_coo_to_mat_dia_r64_i32_r_h_serial(Acoo, Adia);
      dia_check_same(refdia, Adia);

      // csr->dia
      c_morpheus_convert_mat_csr_to_mat_dia_r64_i32_r_h_serial(refcsr, Adia);
      dia_check_same(refdia, Adia);

      c_morpheus_destroy_mat_coo_r64_i32_r_h(&Acoo);
      c_morpheus_destroy_mat_csr_r64_i32_r_h(&Acsr);
      c_morpheus_destroy_mat_dia_r64_i32_r_h(&Adia);
      
    }

    {
      coo *Acoo;
      csr *Acsr;
      dia *Adia;
      c_morpheus_create_default_mat_coo_r64_i32_r_h(&Acoo);
      c_morpheus_create_default_mat_csr_r64_i32_r_h(&Acsr);
      c_morpheus_create_default_mat_dia_r64_i32_r_h(&Adia);
      
      // dia->dia
      c_morpheus_convert_mat_dia_to_mat_dia_r64_i32_r_h_serial(refdia, Adia);
      dia_check_same(refdia,Adia);

      // dia->coo, coo->csr
      c_morpheus_convert_mat_dia_to_mat_coo_r64_i32_r_h_serial(refdia, Acoo);
      coo_check_same(refcoo, Acoo);

      c_morpheus_convert_mat_coo_to_mat_csr_r64_i32_r_h_serial(Acoo, Acsr);
      csr_check_same(refcsr, Acsr);

      // dia->csr
      c_morpheus_convert_mat_dia_to_mat_csr_r64_i32_r_h_serial(refdia, Acsr);
      csr_check_same(refcsr, Acsr);

      c_morpheus_destroy_mat_coo_r64_i32_r_h(&Acoo);
      c_morpheus_destroy_mat_csr_r64_i32_r_h(&Acsr);
      c_morpheus_destroy_mat_dia_r64_i32_r_h(&Adia);
      
    }
  

    c_morpheus_destroy_mat_coo_r64_i32_r_h(&refcoo);
    c_morpheus_destroy_mat_csr_r64_i32_r_h(&refcsr);
    c_morpheus_destroy_mat_dia_r64_i32_r_h(&refdia);
  }
  c_morpheus_finalize();

  return 0;
}
