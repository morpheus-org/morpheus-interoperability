/**
 * Examples_04_c_compatibility.cpp
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

typedef fcl_mat_dyn_r64_i32_r_h dyn;
typedef fcl_mat_coo_r64_i32_r_h coo;
typedef fcl_vec_dense_r64_i32_r_h vec;

int main() {
  morpheus_ccl_initialize_without_args();
  {
    dyn *Adyn;
    coo *A;
    vec *x, *y;

    morpheus_ccl_create_mat_coo_r64_i32_r_h(&A, 5, 3, 3);
    morpheus_ccl_set_row_indices_at_coo_r64_i32_r_h(A, 0, 0);
    morpheus_ccl_set_column_indices_at_coo_r64_i32_r_h(A, 0, 0);
    morpheus_ccl_set_values_at_coo_r64_i32_r_h(A, 0, 4);

    morpheus_ccl_set_row_indices_at_coo_r64_i32_r_h(A, 1, 2);
    morpheus_ccl_set_column_indices_at_coo_r64_i32_r_h(A, 1, 1);
    morpheus_ccl_set_values_at_coo_r64_i32_r_h(A, 1, -2);

    morpheus_ccl_set_row_indices_at_coo_r64_i32_r_h(A, 2, 4);
    morpheus_ccl_set_column_indices_at_coo_r64_i32_r_h(A, 2, 2);
    morpheus_ccl_set_values_at_coo_r64_i32_r_h(A, 2, 2.5);

    morpheus_ccl_create_vec_dense_r64_i32_r_h(&x, 3, 3);
    morpheus_ccl_create_vec_dense_r64_i32_r_h(&y, 5, 0);

    morpheus_ccl_create_mat_dyn_from_mat_r64_i32_r_h(A, COO_FORMAT, &Adyn);
    morpheus_ccl_print_mat_dyn_r64_i32_r_h(Adyn);

    morpheus_ccl_multiply_mat_dyn_vec_dense_vec_dense_r64_i32_r_h_serial(Adyn, x,
                                                                       y);

    morpheus_ccl_print_mat_dyn_r64_i32_r_h(Adyn);
    morpheus_ccl_print_vec_dense_r64_i32_r_h(x);
    morpheus_ccl_print_vec_dense_r64_i32_r_h(y);

    coo *Afromdyn;
    ccl_index_t *Adrind, *Adcind;
    ccl_value_t *Adval;

    morpheus_ccl_create_mat_coo_from_mat_dyn_r64_i32_r_h(Adyn, &Afromdyn);
    morpheus_ccl_print_mat_coo_r64_i32_r_h(Afromdyn);
    morpheus_ccl_set_values_at_coo_r64_i32_r_h(A, 2, -22.5);
    morpheus_ccl_print_mat_dyn_r64_i32_r_h(Adyn);

    morpheus_ccl_activate_mat_dyn_r64_i32_r_h(Adyn, CSR_FORMAT);
    morpheus_ccl_print_mat_dyn_r64_i32_r_h(Adyn);

    morpheus_ccl_destroy_mat_dyn_r64_i32_r_h(&Adyn);
    morpheus_ccl_destroy_mat_coo_r64_i32_r_h(&A);
    morpheus_ccl_destroy_vec_dense_r64_i32_r_h(&x);
    morpheus_ccl_destroy_vec_dense_r64_i32_r_h(&y);
  }
  morpheus_ccl_finalize();

  return 0;
}
