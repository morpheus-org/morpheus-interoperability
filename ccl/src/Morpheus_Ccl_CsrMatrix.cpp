/**
 * Morpheus_Ccl_CsrMatrix.cpp
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

#include <Morpheus_Ccl_CsrMatrix.hpp>

void morpheus_ccl_create_default_hmat_csr(ccl_hmat_csr** A) {
  *A = (new ccl_hmat_csr());
}

void morpheus_ccl_create_hmat_csr(ccl_hmat_csr** A, ccl_index_t nrows,
                                  ccl_index_t ncols, ccl_index_t nnnz) {
  *A = (new ccl_hmat_csr("ccl_hmat_csr::", nrows, ncols, nnnz));
}

void morpheus_ccl_create_hmat_csr_from_hmat_csr(ccl_hmat_csr* src,
                                                ccl_hmat_csr** dst) {
  *dst = (new ccl_hmat_csr(*src));
}

void morpheus_ccl_create_hmat_csr_from_hmat_dyn(ccl_hmat_dyn* src,
                                                ccl_hmat_csr** dst) {
  *dst = (new ccl_hmat_csr(*src));
}

void morpheus_ccl_resize_hmat_csr(ccl_hmat_csr* A, const ccl_index_t num_rows,
                                  const ccl_index_t num_cols,
                                  const ccl_index_t num_nnz) {
  A->resize(num_rows, num_cols, num_nnz);
}

// Assumes dst matrix is always created
void morpheus_ccl_allocate_hmat_csr_from_hmat_csr(ccl_hmat_csr* src,
                                                  ccl_hmat_csr* dst) {
  dst->allocate("ccl_hmat_csr::allocate::", *src);
}

void morpheus_ccl_destroy_hmat_csr(ccl_hmat_csr** A) { delete (*A); }

ccl_index_t morpheus_ccl_nrows_hmat_csr(ccl_hmat_csr* A) { return A->nrows(); }

ccl_index_t morpheus_ccl_ncols_hmat_csr(ccl_hmat_csr* A) { return A->ncols(); }

ccl_index_t morpheus_ccl_nnnz_hmat_csr(ccl_hmat_csr* A) { return A->nnnz(); }

void morpheus_ccl_set_nrows_hmat_csr(ccl_hmat_csr* A, ccl_index_t nrows) {
  A->set_nrows(nrows);
}

void morpheus_ccl_set_ncols_hmat_csr(ccl_hmat_csr* A, ccl_index_t ncols) {
  A->set_ncols(ncols);
}

void morpheus_ccl_set_nnnz_hmat_csr(ccl_hmat_csr* A, ccl_index_t nnnz) {
  A->set_nnnz(nnnz);
}

ccl_index_t morpheus_ccl_row_offsets_at_csr(ccl_hmat_csr* A, ccl_index_t i) {
  return A->row_offsets(i);
}

ccl_index_t morpheus_ccl_column_indices_at_csr(ccl_hmat_csr* A, ccl_index_t i) {
  return A->column_indices(i);
}

ccl_value_t morpheus_ccl_values_at_csr(ccl_hmat_csr* A, ccl_index_t i) {
  return A->values(i);
}

ccl_hvec_dense_i32_i32_r_h* morpheus_ccl_row_offsets_csr(ccl_hmat_csr* A) {
  return &(A->row_offsets());
}

ccl_hvec_dense_i32_i32_r_h* morpheus_ccl_column_indices_csr(ccl_hmat_csr* A) {
  return &(A->column_indices());
}

ccl_hvec_dense* morpheus_ccl_values_csr(ccl_hmat_csr* A) {
  return &(A->values());
}

void morpheus_ccl_set_row_offsets_at_csr(ccl_hmat_csr* A, ccl_index_t i,
                                         ccl_index_t val) {
  A->row_offsets(i) = val;
}

void morpheus_ccl_set_column_indices_at_csr(ccl_hmat_csr* A, ccl_index_t i,
                                            ccl_index_t val) {
  A->column_indices(i) = val;
}

void morpheus_ccl_set_values_at_csr(ccl_hmat_csr* A, ccl_index_t i,
                                    ccl_value_t val) {
  A->values(i) = val;
}

ccl_formats_e morpheus_ccl_format_enum_hmat_csr(ccl_hmat_csr* A) {
  return A->format_enum();
}

int morpheus_ccl_format_index_hmat_csr(ccl_hmat_csr* A) {
  return A->format_index();
}
