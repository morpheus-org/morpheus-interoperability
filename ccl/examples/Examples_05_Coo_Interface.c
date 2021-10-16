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
typedef ccl_hvec_dense vec;

int main() {
  morpheus_ccl_initialize_without_args();
  {
    coo *A, *B;
    vec *x, *y;

    morpheus_ccl_create_hmat_coo(&A, 5, 3, 3);

    int i;
    for(i=0; i<3; i++){
      morpheus_ccl_set_row_indices_at_coo(A, i, i);
      morpheus_ccl_set_column_indices_at_coo(A, i, i);
      morpheus_ccl_set_values_at_coo(A, i, i);
    }
    morpheus_ccl_set_row_indices_at_coo(A, 0, 15);

    morpheus_ccl_create_hvec_dense(&x, 3, 3);
    morpheus_ccl_create_hvec_dense(&y, 5, 0);

    morpheus_ccl_multiply_hmat_coo_hvec_dense_hvec_dense(A, x,
                                                                       y);

    morpheus_ccl_resize_hmat_coo(A, 10, 10, 64);

    morpheus_ccl_create_hmat_coo(&B, 0,0,0);
    morpheus_ccl_allocate_hmat_coo_from_hmat_coo(A, B);

    for(i=0; i<64; i++){
      morpheus_ccl_set_row_indices_at_coo(B, i, i);
      morpheus_ccl_set_column_indices_at_coo(B, i, i);
      morpheus_ccl_set_values_at_coo(B, i, i);
    }
    morpheus_ccl_set_values_at_coo(B, 63, -55);

    morpheus_ccl_print_hmat_coo(B);
    morpheus_ccl_print_hmat_coo(A);
    
    morpheus_ccl_set_nrows_hmat_coo(A, 15);
    morpheus_ccl_set_ncols_hmat_coo(A, 22);
    morpheus_ccl_set_nnnz_hmat_coo(A, 111);

    printf("Coo Enum: %d\n", morpheus_ccl_format_enum_hmat_coo(A));

    printf("Coo Index: %d\n", morpheus_ccl_format_index_hmat_coo(A));

    morpheus_ccl_destroy_hmat_coo(&A);
    morpheus_ccl_destroy_hmat_coo(&B);
    morpheus_ccl_destroy_hvec_dense(&x);
    morpheus_ccl_destroy_hvec_dense(&y);
  }
  morpheus_ccl_finalize();

  return 0;
}
