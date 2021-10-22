/**
 * Examples_02_coomat.cpp
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

using coo = ccl_hmat_coo;
using vec = ccl_hvec_dense_v;


int main() {
  ccl_initialize_without_args();
  {
    coo *A;
    vec *x, *y;

    ccl_hmat_coo_create(&A, 5, 3, 3);

    ccl_hmat_coo_set_row_indices_at(A, 0, 0);
    ccl_hmat_coo_set_column_indices_at(A, 0, 0);
    ccl_hmat_coo_set_values_at(A, 0, 4);

    ccl_hmat_coo_set_row_indices_at(A, 1, 2);
    ccl_hmat_coo_set_column_indices_at(A, 1, 1);
    ccl_hmat_coo_set_values_at(A, 1, -2);

    ccl_hmat_coo_set_row_indices_at(A, 2, 4);
    ccl_hmat_coo_set_column_indices_at(A, 2, 2);
    ccl_hmat_coo_set_values_at(A, 2, 2.5);

    ccl_hvec_dense_v_create(&x, 3, 3);
    ccl_hvec_dense_v_create(&y, 5, 0);

    ccl_hmat_coo_hvec_dense_v_multiply(A, x, y);

    ccl_hmat_coo_print(A);
    ccl_hvec_dense_v_print(x);
    ccl_hvec_dense_v_print(y);

    // shallow copy matrix
    coo *A_shallow;
    ccl_hmat_coo_create_from_hmat_coo(A, &A_shallow);
    // Change value to ensure shallow copy was made
    ccl_hmat_coo_set_values_at(A, 2, -2.5);

    ccl_hmat_coo_print(A_shallow);

    ccl_hmat_coo_destroy(&A);
    ccl_hmat_coo_destroy(&A_shallow);
    ccl_hvec_dense_v_destroy(&x);
    ccl_hvec_dense_v_destroy(&y);
  }
  ccl_finalize();

  return 0;
}
