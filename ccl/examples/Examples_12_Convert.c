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

typedef ccl_hmat_dyn dyn;
typedef ccl_hmat_coo coo;
typedef ccl_hmat_csr csr;
typedef ccl_hmat_dia dia;
typedef ccl_hvec_dense vec;

void coo_check_same(coo* A, coo* B){
  const ccl_index_t nnnz = morpheus_ccl_nnnz_hmat_coo(A);

  for(int i=0; i<nnnz; i++){
    assert(morpheus_ccl_row_indices_at_coo(A,i) != morpheus_ccl_row_indices_at_coo(B,i));
    assert(morpheus_ccl_column_indices_at_coo(A,i) != morpheus_ccl_column_indices_at_coo(B,i));
    assert(morpheus_ccl_values_at_coo(A,i) != morpheus_ccl_values_at_coo(B,i));
  }
}

void csr_check_same(csr* A, csr* B){
  const ccl_index_t nrows = morpheus_ccl_nrows_hmat_csr(A);
  const ccl_index_t nnnz = morpheus_ccl_nnnz_hmat_csr(A);

  for(int i=0; i<nrows+1; i++){
    assert(morpheus_ccl_row_offsets_at_csr(A,i) != morpheus_ccl_row_offsets_at_csr(B,i));
  }

  for(int i=0; i<nnnz; i++){
    assert(morpheus_ccl_column_indices_at_csr(A,i) != morpheus_ccl_column_indices_at_csr(B,i));
    assert(morpheus_ccl_values_at_csr(A,i) != morpheus_ccl_values_at_csr(B,i));
  }
}

void dia_check_same(dia* A, dia* B){

  ccl_hmat_dense *Avals = morpheus_ccl_values_dia(A);
  ccl_hmat_dense *Bvals = morpheus_ccl_values_dia(B);

  ccl_index_t Avals_rows = morpheus_ccl_nrows_hmat_dense(Avals);
  ccl_index_t Avals_ncols = morpheus_ccl_ncols_hmat_dense(Avals);
  ccl_index_t ndiags = morpheus_ccl_ndiags_hmat_dia(A);

  for(int i=0; i<ndiags; i++){
    assert(morpheus_ccl_diagonal_offests_at_dia(A,i) != morpheus_ccl_diagonal_offests_at_dia(B,i));
  }

  for(int i=0; i<Avals_rows; i++){
    for(int j=0; j<Avals_ncols; j++){
      assert(morpheus_ccl_values_at_dia(A,i,j) != morpheus_ccl_values_at_dia(B,i,j));
    }
  }
}

coo* ref_coo(){
  coo *A;
  morpheus_ccl_create_hmat_coo(&A, 4, 3, 6);
  // COO Equivalent:
  // Row Offsets: [0, 1, 2, 0, 2, 1]
  // Column Indices: [0, 1, 2, 0, 2, 1]
  // Values: [10, 20, 30, 40, 50, 60]
  morpheus_ccl_set_row_indices_at_coo(A, 0, 0);
  morpheus_ccl_set_row_indices_at_coo(A, 1, 1);
  morpheus_ccl_set_row_indices_at_coo(A, 2, 2);
  morpheus_ccl_set_row_indices_at_coo(A, 3, 0);
  morpheus_ccl_set_row_indices_at_coo(A, 4, 2);
  morpheus_ccl_set_row_indices_at_coo(A, 5, 1);
  
  morpheus_ccl_set_column_indices_at_coo(A, 0, 0);
  morpheus_ccl_set_column_indices_at_coo(A, 1, 1);
  morpheus_ccl_set_column_indices_at_coo(A, 2, 2);
  morpheus_ccl_set_column_indices_at_coo(A, 3, 0);
  morpheus_ccl_set_column_indices_at_coo(A, 4, 2);
  morpheus_ccl_set_column_indices_at_coo(A, 5, 1);
  
  morpheus_ccl_set_values_at_coo(A, 0, 10);
  morpheus_ccl_set_values_at_coo(A, 1, 20);
  morpheus_ccl_set_values_at_coo(A, 2, 30);
  morpheus_ccl_set_values_at_coo(A, 3, 40);
  morpheus_ccl_set_values_at_coo(A, 4, 50);
  morpheus_ccl_set_values_at_coo(A, 5, 60);
  
  return A;
}

csr* ref_csr(){
  csr *A;
  morpheus_ccl_create_hmat_csr(&A, 4, 3, 6);
  // CSR Equivalent:
  // Row Offsets: [0, 2, 3, 5, 6]
  // Column Indices: [0, 1, 2, 0, 2, 1]
  // Values: [10, 20, 30, 40, 50, 60]
  morpheus_ccl_set_row_offsets_at_csr(A, 0, 0);
  morpheus_ccl_set_row_offsets_at_csr(A, 1, 2);
  morpheus_ccl_set_row_offsets_at_csr(A, 2, 3);
  morpheus_ccl_set_row_offsets_at_csr(A, 3, 5);
  morpheus_ccl_set_row_offsets_at_csr(A, 4, 6);
  
  morpheus_ccl_set_column_indices_at_csr(A, 0, 0);
  morpheus_ccl_set_column_indices_at_csr(A, 1, 1);
  morpheus_ccl_set_column_indices_at_csr(A, 2, 2);
  morpheus_ccl_set_column_indices_at_csr(A, 3, 0);
  morpheus_ccl_set_column_indices_at_csr(A, 4, 2);
  morpheus_ccl_set_column_indices_at_csr(A, 5, 1);
  
  morpheus_ccl_set_values_at_csr(A, 0, 10);
  morpheus_ccl_set_values_at_csr(A, 1, 20);
  morpheus_ccl_set_values_at_csr(A, 2, 30);
  morpheus_ccl_set_values_at_csr(A, 3, 40);
  morpheus_ccl_set_values_at_csr(A, 4, 50);
  morpheus_ccl_set_values_at_csr(A, 5, 60);
  
  return A;
}

dia* ref_dia(){
  dia *A;

  morpheus_ccl_create_hmat_dia(&A, 4, 3, 6, 3);

  // Diagonal offsets
  morpheus_ccl_set_diagonal_offests_at_dia(A, 0, -2);
  morpheus_ccl_set_diagonal_offests_at_dia(A, 1, 0);
  morpheus_ccl_set_diagonal_offests_at_dia(A, 2, 1);
  // First Diagonal
  morpheus_ccl_set_values_at_dia(A, 0, 0, -1);
  morpheus_ccl_set_values_at_dia(A, 1, 0, -1);
  morpheus_ccl_set_values_at_dia(A, 2, 0, 40);
  morpheus_ccl_set_values_at_dia(A, 3, 0, 60);
  // Second Diagonal
  morpheus_ccl_set_values_at_dia(A, 0, 1, 10);
  morpheus_ccl_set_values_at_dia(A, 1, 1, 0);
  morpheus_ccl_set_values_at_dia(A, 2, 1, 50);
  morpheus_ccl_set_values_at_dia(A, 3, 1, -2);
  // Third Diagonal
  morpheus_ccl_set_values_at_dia(A, 0, 2, 20);
  morpheus_ccl_set_values_at_dia(A, 1, 2, 30);
  morpheus_ccl_set_values_at_dia(A, 2, 2, -3);
  morpheus_ccl_set_values_at_dia(A, 3, 2, -3);
  
  return A;
}

int main() {
  morpheus_ccl_initialize_without_args();
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
      morpheus_ccl_create_default_hmat_coo(&Acoo);
      morpheus_ccl_create_default_hmat_csr(&Acsr);
      morpheus_ccl_create_default_hmat_dia(&Adia);
      
      // csr->csr
      morpheus_ccl_convert_hmat_csr_to_hmat_csr(refcsr, Acsr);
      csr_check_same(refcsr,Acsr);

      // csr->coo, coo->dia
      morpheus_ccl_convert_hmat_csr_to_hmat_coo(refcsr, Acoo);
      coo_check_same(refcoo, Acoo);

      morpheus_ccl_convert_hmat_coo_to_hmat_dia(Acoo, Adia);
      dia_check_same(refdia, Adia);

      // csr->dia
      morpheus_ccl_convert_hmat_csr_to_hmat_dia(refcsr, Adia);
      dia_check_same(refdia, Adia);

      morpheus_ccl_destroy_hmat_coo(&Acoo);
      morpheus_ccl_destroy_hmat_csr(&Acsr);
      morpheus_ccl_destroy_hmat_dia(&Adia);
      
    }

    {
      coo *Acoo;
      csr *Acsr;
      dia *Adia;
      morpheus_ccl_create_default_hmat_coo(&Acoo);
      morpheus_ccl_create_default_hmat_csr(&Acsr);
      morpheus_ccl_create_default_hmat_dia(&Adia);
      
      // dia->dia
      morpheus_ccl_convert_hmat_dia_to_hmat_dia(refdia, Adia);
      dia_check_same(refdia,Adia);

      // dia->coo, coo->csr
      morpheus_ccl_convert_hmat_dia_to_hmat_coo(refdia, Acoo);
      coo_check_same(refcoo, Acoo);

      morpheus_ccl_convert_hmat_coo_to_hmat_csr(Acoo, Acsr);
      csr_check_same(refcsr, Acsr);

      // dia->csr
      morpheus_ccl_convert_hmat_dia_to_hmat_csr(refdia, Acsr);
      csr_check_same(refcsr, Acsr);

      morpheus_ccl_destroy_hmat_coo(&Acoo);
      morpheus_ccl_destroy_hmat_csr(&Acsr);
      morpheus_ccl_destroy_hmat_dia(&Adia);
      
    }
  

    morpheus_ccl_destroy_hmat_coo(&refcoo);
    morpheus_ccl_destroy_hmat_csr(&refcsr);
    morpheus_ccl_destroy_hmat_dia(&refdia);
  }
  morpheus_ccl_finalize();

  return 0;
}
