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

#include "Fcl_C.hpp"

typedef fcl_mat_dyn_r64_i32_r_h dyn;
typedef fcl_mat_coo_r64_i32_r_h coo;
typedef fcl_vec_dense_r64_i32_r_h vec;

int main() {
  c_morpheus_initialize_without_args();
  {
    dyn *Adyn;
    coo *A;
    vec *x, *y;

    c_morpheus_create_mat_coo_r64_i32_r_h(&A, 5, 3, 3);
    c_morpheus_set_row_indices_at_coo_r64_i32_r_h(A, 0, 0);
    c_morpheus_set_column_indices_at_coo_r64_i32_r_h(A, 0, 0);
    c_morpheus_set_values_at_coo_r64_i32_r_h(A, 0, 4);

    c_morpheus_set_row_indices_at_coo_r64_i32_r_h(A, 1, 2);
    c_morpheus_set_column_indices_at_coo_r64_i32_r_h(A, 1, 1);
    c_morpheus_set_values_at_coo_r64_i32_r_h(A, 1, -2);

    c_morpheus_set_row_indices_at_coo_r64_i32_r_h(A, 2, 4);
    c_morpheus_set_column_indices_at_coo_r64_i32_r_h(A, 2, 2);
    c_morpheus_set_values_at_coo_r64_i32_r_h(A, 2, 2.5);

    c_morpheus_create_vec_dense_r64_i32_r_h(&x, 3, 3);
    c_morpheus_create_vec_dense_r64_i32_r_h(&y, 5, 0);

    c_morpheus_create_mat_dyn_from_mat_r64_i32_r_h(A, COO_FORMAT, &Adyn);
    c_morpheus_print_mat_dyn_r64_i32_r_h(Adyn);

    c_morpheus_multiply_mat_dyn_vec_dense_vec_dense_r64_i32_r_h_serial(Adyn, x,
                                                                       y);

    c_morpheus_print_mat_dyn_r64_i32_r_h(Adyn);
    c_morpheus_print_vec_dense_r64_i32_r_h(x);
    c_morpheus_print_vec_dense_r64_i32_r_h(y);

    coo *Afromdyn;
    fcl_i32_t *Adrind, *Adcind;
    fcl_r64_t *Adval;

    c_morpheus_create_mat_coo_from_mat_dyn_r64_i32_r_h(Adyn, &Afromdyn);
    c_morpheus_print_mat_coo_r64_i32_r_h(Afromdyn);
    c_morpheus_set_values_at_coo_r64_i32_r_h(A, 2, -22.5);
    c_morpheus_print_mat_dyn_r64_i32_r_h(Adyn);

    c_morpheus_activate_mat_dyn_r64_i32_r_h(Adyn, CSR_FORMAT);
    c_morpheus_print_mat_dyn_r64_i32_r_h(Adyn);

    c_morpheus_destroy_mat_dyn_r64_i32_r_h(&Adyn);
    c_morpheus_destroy_mat_coo_r64_i32_r_h(&A);
    c_morpheus_destroy_vec_dense_r64_i32_r_h(&x);
    c_morpheus_destroy_vec_dense_r64_i32_r_h(&y);
  }
  c_morpheus_finalize();

  return 0;
}