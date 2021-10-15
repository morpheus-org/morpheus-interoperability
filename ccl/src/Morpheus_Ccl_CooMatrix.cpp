/**
 * Morpheus_Ccl_CooMatrix.cpp
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

#include <Morpheus_Ccl_CooMatrix.hpp>

void morpheus_ccl_create_default_mat_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h** A) {
  *A = (new fcl_mat_coo_r64_i32_r_h());
}

void morpheus_ccl_create_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h** A,
                                             fcl_i32_t nrows, fcl_i32_t ncols,
                                             fcl_i32_t nnnz) {
  *A = (new fcl_mat_coo_r64_i32_r_h("fcl_mat_coo_r64_i32_r_h::", nrows, ncols,
                                    nnnz));
}

void morpheus_ccl_create_mat_coo_from_mat_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* src, fcl_mat_coo_r64_i32_r_h** dst) {
  *dst = (new fcl_mat_coo_r64_i32_r_h(*src));
}

void morpheus_ccl_create_mat_coo_from_mat_dyn_r64_i32_r_h(
    fcl_mat_dyn_r64_i32_r_h* src, fcl_mat_coo_r64_i32_r_h** dst) {
  *dst = (new fcl_mat_coo_r64_i32_r_h(*src));
}

void morpheus_ccl_resize_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A,
                                             const fcl_i32_t num_rows,
                                             const fcl_i32_t num_cols,
                                             const fcl_i32_t num_nnz) {
  A->resize(num_rows, num_cols, num_nnz);
}

// Assumes dst matrix is always created
void morpheus_ccl_allocate_mat_coo_from_mat_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* src, fcl_mat_coo_r64_i32_r_h* dst) {
  dst->allocate("fcl_mat_coo_r64_i32_r_h::allocate::", *src);
}

void morpheus_ccl_destroy_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h** A) {
  delete (*A);
}

fcl_i32_t morpheus_ccl_nrows_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A) {
  return A->nrows();
}

fcl_i32_t morpheus_ccl_ncols_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A) {
  return A->ncols();
}

fcl_i32_t morpheus_ccl_nnnz_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A) {
  return A->nnnz();
}

void morpheus_ccl_set_nrows_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A,
                                                fcl_i32_t nrows) {
  A->set_nrows(nrows);
}

void morpheus_ccl_set_ncols_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A,
                                                fcl_i32_t ncols) {
  A->set_ncols(ncols);
}

void morpheus_ccl_set_nnnz_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A,
                                               fcl_i32_t nnnz) {
  A->set_nnnz(nnnz);
}

fcl_i32_t morpheus_ccl_row_indices_at_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* A, fcl_i32_t i) {
  return A->row_indices(i);
}

fcl_i32_t morpheus_ccl_column_indices_at_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* A, fcl_i32_t i) {
  return A->column_indices(i);
}

ccl_value_t morpheus_ccl_values_at_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A,
                                                   fcl_i32_t i) {
  return A->values(i);
}

fcl_vec_dense_i32_i32_r_h* morpheus_ccl_row_indices_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* A) {
  return &(A->row_indices());
}

fcl_vec_dense_i32_i32_r_h* morpheus_ccl_column_indices_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* A) {
  return &(A->column_indices());
}

fcl_vec_dense_r64_i32_r_h* morpheus_ccl_values_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* A) {
  return &(A->values());
}

void morpheus_ccl_set_row_indices_at_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A,
                                                     fcl_i32_t i,
                                                     fcl_i32_t val) {
  A->row_indices(i) = val;
}

void morpheus_ccl_set_column_indices_at_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* A, fcl_i32_t i, fcl_i32_t val) {
  A->column_indices(i) = val;
}

void morpheus_ccl_set_values_at_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A,
                                                fcl_i32_t i, ccl_value_t val) {
  A->values(i) = val;
}

void morpheus_ccl_sort_by_row_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A) {
  A->sort_by_row();
}

void morpheus_ccl_sort_by_row_and_column_mat_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* A) {
  A->sort_by_row_and_column();
}

fcl_bool_t morpheus_ccl_is_sorted_by_row_mat_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* A) {
  return A->is_sorted_by_row();
}

fcl_bool_t morpheus_ccl_is_sorted_mat_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* A) {
  return A->is_sorted();
}

fcl_formats_e morpheus_ccl_format_enum_mat_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* A) {
  return A->format_enum();
}

int morpheus_ccl_format_index_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A) {
  return A->format_index();
}
