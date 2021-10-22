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
typedef ccl_hvec_dense_v vec;

void coo_check_same(coo* A, coo* B){
  const ccl_index_t nnnz = ccl_hmat_coo_nnnz(A);

  for(int i=0; i<nnnz; i++){
    assert(ccl_hmat_coo_row_indices_at(A,i) != ccl_hmat_coo_row_indices_at(B,i));
    assert(ccl_hmat_coo_column_indices_at(A,i) != ccl_hmat_coo_column_indices_at(B,i));
    assert(ccl_hmat_coo_values_at(A,i) != ccl_hmat_coo_values_at(B,i));
  }
}

void csr_check_same(csr* A, csr* B){
  const ccl_index_t nrows = ccl_hmat_csr_nrows(A);
  const ccl_index_t nnnz = ccl_hmat_csr_nnnz(A);

  for(int i=0; i<nrows+1; i++){
    assert(ccl_hmat_csr_row_offsets_at(A,i) != ccl_hmat_csr_row_offsets_at(B,i));
  }

  for(int i=0; i<nnnz; i++){
    assert(ccl_hmat_csr_column_indices_at(A,i) != ccl_hmat_csr_column_indices_at(B,i));
    assert(ccl_hmat_csr_values_at(A,i) != ccl_hmat_csr_values_at(B,i));
  }
}

void dia_check_same(dia* A, dia* B){

  ccl_hmat_dense *Avals = ccl_hmat_dia_values(A);
  ccl_hmat_dense *Bvals = ccl_hmat_dia_values(B);

  ccl_index_t Avals_rows = ccl_hmat_dense_nrows(Avals);
  ccl_index_t Avals_ncols = ccl_hmat_dense_ncols(Avals);
  ccl_index_t ndiags = ccl_hmat_dia_ndiags(A);

  for(int i=0; i<ndiags; i++){
    assert(ccl_hmat_dia_diagonal_offests_at(A,i) != ccl_hmat_dia_diagonal_offests_at(B,i));
  }

  for(int i=0; i<Avals_rows; i++){
    for(int j=0; j<Avals_ncols; j++){
      assert(ccl_hmat_dia_values_at(A,i,j) != ccl_hmat_dia_values_at(B,i,j));
    }
  }
}

coo* ref_coo(){
  coo *A;
  ccl_hmat_coo_create(&A, 4, 3, 6);
  // COO Equivalent:
  // Row Offsets: [0, 1, 2, 0, 2, 1]
  // Column Indices: [0, 1, 2, 0, 2, 1]
  // Values: [10, 20, 30, 40, 50, 60]
  ccl_hmat_coo_set_row_indices_at(A, 0, 0);
  ccl_hmat_coo_set_row_indices_at(A, 1, 1);
  ccl_hmat_coo_set_row_indices_at(A, 2, 2);
  ccl_hmat_coo_set_row_indices_at(A, 3, 0);
  ccl_hmat_coo_set_row_indices_at(A, 4, 2);
  ccl_hmat_coo_set_row_indices_at(A, 5, 1);
  
  ccl_hmat_coo_set_column_indices_at(A, 0, 0);
  ccl_hmat_coo_set_column_indices_at(A, 1, 1);
  ccl_hmat_coo_set_column_indices_at(A, 2, 2);
  ccl_hmat_coo_set_column_indices_at(A, 3, 0);
  ccl_hmat_coo_set_column_indices_at(A, 4, 2);
  ccl_hmat_coo_set_column_indices_at(A, 5, 1);
  
  ccl_hmat_coo_set_values_at(A, 0, 10);
  ccl_hmat_coo_set_values_at(A, 1, 20);
  ccl_hmat_coo_set_values_at(A, 2, 30);
  ccl_hmat_coo_set_values_at(A, 3, 40);
  ccl_hmat_coo_set_values_at(A, 4, 50);
  ccl_hmat_coo_set_values_at(A, 5, 60);
  
  return A;
}

csr* ref_csr(){
  csr *A;
  ccl_hmat_csr_create(&A, 4, 3, 6);
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
  
  return A;
}

dia* ref_dia(){
  dia *A;

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
      coo *Acoo;
      csr *Acsr;
      dia *Adia;
      ccl_hmat_coo_create_default(&Acoo);
      ccl_hmat_csr_create_default(&Acsr);
      ccl_hmat_dia_create_default(&Adia);
      
      // csr->csr
      ccl_hmat_csr_convert_to_hmat_csr(refcsr, Acsr);
      csr_check_same(refcsr,Acsr);

      // csr->coo, coo->dia
      ccl_hmat_csr_convert_to_hmat_coo(refcsr, Acoo);
      coo_check_same(refcoo, Acoo);

      ccl_hmat_coo_convert_to_hmat_dia(Acoo, Adia);
      dia_check_same(refdia, Adia);

      // csr->dia
      ccl_hmat_csr_convert_to_hmat_dia(refcsr, Adia);
      dia_check_same(refdia, Adia);

      ccl_hmat_coo_destroy(&Acoo);
      ccl_hmat_csr_destroy(&Acsr);
      ccl_hmat_dia_destroy(&Adia);
      
    }

    {
      coo *Acoo;
      csr *Acsr;
      dia *Adia;
      ccl_hmat_coo_create_default(&Acoo);
      ccl_hmat_csr_create_default(&Acsr);
      ccl_hmat_dia_create_default(&Adia);
      
      // dia->dia
      ccl_hmat_dia_convert_to_hmat_dia(refdia, Adia);
      dia_check_same(refdia,Adia);

      // dia->coo, coo->csr
      ccl_hmat_dia_convert_to_hmat_coo(refdia, Acoo);
      coo_check_same(refcoo, Acoo);

      ccl_hmat_coo_convert_to_hmat_csr(Acoo, Acsr);
      csr_check_same(refcsr, Acsr);

      // dia->csr
      ccl_hmat_dia_convert_to_hmat_csr(refdia, Acsr);
      csr_check_same(refcsr, Acsr);

      ccl_hmat_coo_destroy(&Acoo);
      ccl_hmat_csr_destroy(&Acsr);
      ccl_hmat_dia_destroy(&Adia);
      
    }
  

    ccl_hmat_coo_destroy(&refcoo);
    ccl_hmat_csr_destroy(&refcsr);
    ccl_hmat_dia_destroy(&refdia);
  }
  ccl_finalize();

  return 0;
}
