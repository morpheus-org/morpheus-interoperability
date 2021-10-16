/**
 * Examples_05_Coo_Interface.c
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
typedef ccl_hvec_dense_v vec;

int main() {
  ccl_initialize_without_args();
  {
    coo *A, *B;
    vec *x, *y;

    ccl_hmat_coo_create(&A, 5, 3, 3);

    int i;
    for(i=0; i<3; i++){
      ccl_hmat_coo_set_row_indices_at(A, i, i);
      ccl_hmat_coo_set_column_indices_at(A, i, i);
      ccl_hmat_coo_set_values_at(A, i, i);
    }
    ccl_hmat_coo_set_row_indices_at(A, 0, 15);

    ccl_hvec_dense_v_create(&x, 3, 3);
    ccl_hvec_dense_v_create(&y, 5, 0);

    ccl_hmat_coo_hvec_dense_v_multiply(A, x, y);

    ccl_hmat_coo_resize(A, 10, 10, 64);

    ccl_hmat_coo_create(&B, 0,0,0);
    ccl_hmat_coo_allocate_from_hmat_coo(A, B);

    for(i=0; i<64; i++){
      ccl_hmat_coo_set_row_indices_at(B, i, i);
      ccl_hmat_coo_set_column_indices_at(B, i, i);
      ccl_hmat_coo_set_values_at(B, i, i);
    }
    ccl_hmat_coo_set_values_at(B, 63, -55);

    ccl_hmat_coo_print(B);
    ccl_hmat_coo_print(A);
    
    ccl_hmat_coo_set_nrows(A, 15);
    ccl_hmat_coo_set_ncols(A, 22);
    ccl_hmat_coo_set_nnnz(A, 111);

    printf("Coo Enum: %d\n", ccl_hmat_coo_format_enum(A));

    printf("Coo Index: %d\n", ccl_hmat_coo_format_index(A));

    ccl_hmat_coo_destroy(&A);
    ccl_hmat_coo_destroy(&B);
    ccl_hvec_dense_v_destroy(&x);
    ccl_hvec_dense_v_destroy(&y);
  }
  ccl_finalize();

  return 0;
}
