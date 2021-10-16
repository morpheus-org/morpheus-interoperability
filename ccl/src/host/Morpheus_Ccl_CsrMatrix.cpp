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

#include <host/Morpheus_Ccl_CsrMatrix.hpp>

void ccl_hmat_csr_create_default(ccl_hmat_csr** A) {
  *A = (new ccl_hmat_csr());
}

void ccl_hmat_csr_create(ccl_hmat_csr** A, ccl_index_t nrows, ccl_index_t ncols,
                         ccl_index_t nnnz) {
  *A = (new ccl_hmat_csr("ccl_hmat_csr::", nrows, ncols, nnnz));
}

void ccl_hmat_csr_create_from_hmat_csr(ccl_hmat_csr* src, ccl_hmat_csr** dst) {
  *dst = (new ccl_hmat_csr(*src));
}

void ccl_hmat_csr_create_from_hmat_dyn(ccl_hmat_dyn* src, ccl_hmat_csr** dst) {
  *dst = (new ccl_hmat_csr(*src));
}

void ccl_hmat_csr_resize(ccl_hmat_csr* A, const ccl_index_t num_rows,
                         const ccl_index_t num_cols,
                         const ccl_index_t num_nnz) {
  A->resize(num_rows, num_cols, num_nnz);
}

// Assumes dst matrix is always created
void ccl_hmat_csr_allocate_from_hmat_csr(ccl_hmat_csr* src, ccl_hmat_csr* dst) {
  dst->allocate("ccl_hmat_csr::allocate::", *src);
}

void ccl_hmat_csr_destroy(ccl_hmat_csr** A) { delete (*A); }

ccl_index_t ccl_hmat_csr_nrows(ccl_hmat_csr* A) { return A->nrows(); }

ccl_index_t ccl_hmat_csr_ncols(ccl_hmat_csr* A) { return A->ncols(); }

ccl_index_t ccl_hmat_csr_nnnz(ccl_hmat_csr* A) { return A->nnnz(); }

void ccl_hmat_csr_set_nrows(ccl_hmat_csr* A, ccl_index_t nrows) {
  A->set_nrows(nrows);
}

void ccl_hmat_csr_set_ncols(ccl_hmat_csr* A, ccl_index_t ncols) {
  A->set_ncols(ncols);
}

void ccl_hmat_csr_set_nnnz(ccl_hmat_csr* A, ccl_index_t nnnz) {
  A->set_nnnz(nnnz);
}

ccl_index_t ccl_hmat_csr_row_offsets_at(ccl_hmat_csr* A, ccl_index_t i) {
  return A->row_offsets(i);
}

ccl_index_t ccl_hmat_csr_column_indices_at(ccl_hmat_csr* A, ccl_index_t i) {
  return A->column_indices(i);
}

ccl_value_t ccl_hmat_csr_values_at(ccl_hmat_csr* A, ccl_index_t i) {
  return A->values(i);
}

ccl_hvec_dense_i* ccl_hmat_csr_row_offsets(ccl_hmat_csr* A) {
  return &(A->row_offsets());
}

ccl_hvec_dense_i* ccl_hmat_csr_column_indices(ccl_hmat_csr* A) {
  return &(A->column_indices());
}

ccl_hvec_dense_v* ccl_hmat_csr_values(ccl_hmat_csr* A) {
  return &(A->values());
}

void ccl_hmat_csr_set_row_offsets_at(ccl_hmat_csr* A, ccl_index_t i,
                                     ccl_index_t val) {
  A->row_offsets(i) = val;
}

void ccl_hmat_csr_set_column_indices_at(ccl_hmat_csr* A, ccl_index_t i,
                                        ccl_index_t val) {
  A->column_indices(i) = val;
}

void ccl_hmat_csr_set_values_at(ccl_hmat_csr* A, ccl_index_t i,
                                ccl_value_t val) {
  A->values(i) = val;
}

ccl_formats_e ccl_hmat_csr_format_enum(ccl_hmat_csr* A) {
  return A->format_enum();
}

int ccl_hmat_csr_format_index(ccl_hmat_csr* A) { return A->format_index(); }
