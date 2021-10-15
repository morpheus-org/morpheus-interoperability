/**
 * Morpheus_Ccl_DenseMatrix.cpp
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

#include <Morpheus_Ccl_DenseMatrix.hpp>

void morpheus_ccl_create_default_mat_dense_r64_i32_r_h(
    fcl_mat_dense_r64_i32_r_h** A) {
  *A = (new fcl_mat_dense_r64_i32_r_h());
}

void morpheus_ccl_create_mat_dense_r64_i32_r_h(fcl_mat_dense_r64_i32_r_h** A,
                                               fcl_i32_t num_rows,
                                               fcl_i32_t num_cols,
                                               ccl_value_t val) {
  *A = (new fcl_mat_dense_r64_i32_r_h("fcl_mat_dense_r64_i32_r_h::", num_rows,
                                      num_cols, val));
}

void morpheus_ccl_create_mat_dense_from_mat_dense_r64_i32_r_h(
    fcl_mat_dense_r64_i32_r_h* src, fcl_mat_dense_r64_i32_r_h** dst) {
  *dst = (new fcl_mat_dense_r64_i32_r_h(*src));
}

void morpheus_ccl_allocate_mat_dense_from_mat_dense_r64_i32_r_h(
    fcl_mat_dense_r64_i32_r_h* src, fcl_mat_dense_r64_i32_r_h* dst) {
  dst->allocate("fcl_mat_dense_r64_i32_r_h::allocate::", *src);
}

void morpheus_ccl_assign_mat_dense_r64_i32_r_h(fcl_mat_dense_r64_i32_r_h* A,
                                               fcl_i32_t num_rows,
                                               fcl_i32_t num_cols,
                                               ccl_value_t val) {
  A->assign(num_rows, num_cols, val);
}

void morpheus_ccl_resize_mat_dense_r64_i32_r_h(fcl_mat_dense_r64_i32_r_h* A,
                                               fcl_i32_t num_rows,
                                               fcl_i32_t num_cols) {
  A->resize(num_rows, num_cols);
}

void morpheus_ccl_destroy_mat_dense_r64_i32_r_h(fcl_mat_dense_r64_i32_r_h** A) {
  delete (*A);
}

fcl_i32_t morpheus_ccl_nrows_mat_dense_r64_i32_r_h(
    fcl_mat_dense_r64_i32_r_h* A) {
  return A->nrows();
}

fcl_i32_t morpheus_ccl_ncols_mat_dense_r64_i32_r_h(
    fcl_mat_dense_r64_i32_r_h* A) {
  return A->ncols();
}

fcl_i32_t morpheus_ccl_nnnz_mat_dense_r64_i32_r_h(
    fcl_mat_dense_r64_i32_r_h* A) {
  return A->nnnz();
}

void morpheus_ccl_set_nrows_mat_dense_r64_i32_r_h(fcl_mat_dense_r64_i32_r_h* A,
                                                  fcl_i32_t nrows) {
  A->set_nrows(nrows);
}

void morpheus_ccl_set_ncols_mat_dense_r64_i32_r_h(fcl_mat_dense_r64_i32_r_h* A,
                                                  fcl_i32_t ncols) {
  A->set_ncols(ncols);
}

void morpheus_ccl_set_nnnz_mat_dense_r64_i32_r_h(fcl_mat_dense_r64_i32_r_h* A,
                                                 fcl_i32_t nnnz) {
  A->set_nnnz(nnnz);
}

ccl_value_t* morpheus_ccl_data_mat_dense_r64_i32_r_h(
    fcl_mat_dense_r64_i32_r_h* A) {
  return A->data();
}

ccl_value_t morpheus_ccl_values_at_mat_dense_r64_i32_r_h(
    fcl_mat_dense_r64_i32_r_h* A, fcl_i32_t i, fcl_i32_t j) {
  return (*A)(i, j);
}

void morpheus_ccl_set_values_at_mat_dense_r64_i32_r_h(
    fcl_mat_dense_r64_i32_r_h* A, fcl_i32_t i, fcl_i32_t j, fcl_i32_t val) {
  (*A)(i, j) = val;
}
