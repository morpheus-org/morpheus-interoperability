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

#include <host/Morpheus_Ccl_CooMatrix.hpp>

void morpheus_ccl_create_default_hmat_coo(ccl_hmat_coo** A) {
  *A = (new ccl_hmat_coo());
}

void morpheus_ccl_create_hmat_coo(ccl_hmat_coo** A, ccl_index_t nrows,
                                  ccl_index_t ncols, ccl_index_t nnnz) {
  *A = (new ccl_hmat_coo("ccl_hmat_coo::", nrows, ncols, nnnz));
}

void morpheus_ccl_create_hmat_coo_from_hmat_coo(ccl_hmat_coo* src,
                                                ccl_hmat_coo** dst) {
  *dst = (new ccl_hmat_coo(*src));
}

void morpheus_ccl_create_hmat_coo_from_hmat_dyn(ccl_hmat_dyn* src,
                                                ccl_hmat_coo** dst) {
  *dst = (new ccl_hmat_coo(*src));
}

void morpheus_ccl_resize_hmat_coo(ccl_hmat_coo* A, const ccl_index_t num_rows,
                                  const ccl_index_t num_cols,
                                  const ccl_index_t num_nnz) {
  A->resize(num_rows, num_cols, num_nnz);
}

// Assumes dst matrix is always created
void morpheus_ccl_allocate_hmat_coo_from_hmat_coo(ccl_hmat_coo* src,
                                                  ccl_hmat_coo* dst) {
  dst->allocate("ccl_hmat_coo::allocate::", *src);
}

void morpheus_ccl_destroy_hmat_coo(ccl_hmat_coo** A) { delete (*A); }

ccl_index_t morpheus_ccl_nrows_hmat_coo(ccl_hmat_coo* A) { return A->nrows(); }

ccl_index_t morpheus_ccl_ncols_hmat_coo(ccl_hmat_coo* A) { return A->ncols(); }

ccl_index_t morpheus_ccl_nnnz_hmat_coo(ccl_hmat_coo* A) { return A->nnnz(); }

void morpheus_ccl_set_nrows_hmat_coo(ccl_hmat_coo* A, ccl_index_t nrows) {
  A->set_nrows(nrows);
}

void morpheus_ccl_set_ncols_hmat_coo(ccl_hmat_coo* A, ccl_index_t ncols) {
  A->set_ncols(ncols);
}

void morpheus_ccl_set_nnnz_hmat_coo(ccl_hmat_coo* A, ccl_index_t nnnz) {
  A->set_nnnz(nnnz);
}

ccl_index_t morpheus_ccl_row_indices_at_coo(ccl_hmat_coo* A, ccl_index_t i) {
  return A->row_indices(i);
}

ccl_index_t morpheus_ccl_column_indices_at_coo(ccl_hmat_coo* A, ccl_index_t i) {
  return A->column_indices(i);
}

ccl_value_t morpheus_ccl_values_at_coo(ccl_hmat_coo* A, ccl_index_t i) {
  return A->values(i);
}

ccl_hvec_dense_i32_i32_r_h* morpheus_ccl_row_indices_coo(ccl_hmat_coo* A) {
  return &(A->row_indices());
}

ccl_hvec_dense_i32_i32_r_h* morpheus_ccl_column_indices_coo(ccl_hmat_coo* A) {
  return &(A->column_indices());
}

ccl_hvec_dense* morpheus_ccl_values_coo(ccl_hmat_coo* A) {
  return &(A->values());
}

void morpheus_ccl_set_row_indices_at_coo(ccl_hmat_coo* A, ccl_index_t i,
                                         ccl_index_t val) {
  A->row_indices(i) = val;
}

void morpheus_ccl_set_column_indices_at_coo(ccl_hmat_coo* A, ccl_index_t i,
                                            ccl_index_t val) {
  A->column_indices(i) = val;
}

void morpheus_ccl_set_values_at_coo(ccl_hmat_coo* A, ccl_index_t i,
                                    ccl_value_t val) {
  A->values(i) = val;
}

void morpheus_ccl_sort_by_row_hmat_coo(ccl_hmat_coo* A) { A->sort_by_row(); }

void morpheus_ccl_sort_by_row_and_column_hmat_coo(ccl_hmat_coo* A) {
  A->sort_by_row_and_column();
}

ccl_bool_t morpheus_ccl_is_sorted_by_row_hmat_coo(ccl_hmat_coo* A) {
  return A->is_sorted_by_row();
}

ccl_bool_t morpheus_ccl_is_sorted_hmat_coo(ccl_hmat_coo* A) {
  return A->is_sorted();
}

ccl_formats_e morpheus_ccl_format_enum_hmat_coo(ccl_hmat_coo* A) {
  return A->format_enum();
}

int morpheus_ccl_format_index_hmat_coo(ccl_hmat_coo* A) {
  return A->format_index();
}
