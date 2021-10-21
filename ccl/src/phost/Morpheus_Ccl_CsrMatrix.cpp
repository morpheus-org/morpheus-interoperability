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

#include <phost/Morpheus_Ccl_CsrMatrix.hpp>

void ccl_phmat_csr_create_default(ccl_phmat_csr** A) {
  *A = (new ccl_phmat_csr());
}

void ccl_phmat_csr_create(ccl_phmat_csr** A, ccl_index_t nrows,
                          ccl_index_t ncols, ccl_index_t nnnz) {
  *A = (new ccl_phmat_csr("ccl_phmat_csr::", nrows, ncols, nnnz));
}

void ccl_phmat_csr_create_from_phmat_csr(ccl_phmat_csr* src,
                                         ccl_phmat_csr** dst) {
  *dst = (new ccl_phmat_csr(*src));
}

void ccl_phmat_csr_create_from_phmat_dyn(ccl_phmat_dyn* src,
                                         ccl_phmat_csr** dst) {
  *dst = (new ccl_phmat_csr(*src));
}

void ccl_phmat_csr_resize(ccl_phmat_csr* A, const ccl_index_t num_rows,
                          const ccl_index_t num_cols,
                          const ccl_index_t num_nnz) {
  A->resize(num_rows, num_cols, num_nnz);
}

// Assumes dst matrix is always created
void ccl_phmat_csr_allocate_from_phmat_csr(ccl_phmat_csr* src,
                                           ccl_phmat_csr* dst) {
  dst->allocate("ccl_phmat_csr::allocate::", *src);
}

void ccl_phmat_csr_destroy(ccl_phmat_csr** A) { delete (*A); }

ccl_index_t ccl_phmat_csr_nrows(ccl_phmat_csr* A) { return A->nrows(); }

ccl_index_t ccl_phmat_csr_ncols(ccl_phmat_csr* A) { return A->ncols(); }

ccl_index_t ccl_phmat_csr_nnnz(ccl_phmat_csr* A) { return A->nnnz(); }

void ccl_phmat_csr_set_nrows(ccl_phmat_csr* A, ccl_index_t nrows) {
  A->set_nrows(nrows);
}

void ccl_phmat_csr_set_ncols(ccl_phmat_csr* A, ccl_index_t ncols) {
  A->set_ncols(ncols);
}

void ccl_phmat_csr_set_nnnz(ccl_phmat_csr* A, ccl_index_t nnnz) {
  A->set_nnnz(nnnz);
}

ccl_index_t ccl_phmat_csr_row_offsets_at(ccl_phmat_csr* A, ccl_index_t i) {
  return A->row_offsets(i);
}

ccl_index_t ccl_phmat_csr_column_indices_at(ccl_phmat_csr* A, ccl_index_t i) {
  return A->column_indices(i);
}

ccl_value_t ccl_phmat_csr_values_at(ccl_phmat_csr* A, ccl_index_t i) {
  return A->values(i);
}

ccl_phvec_dense_i* ccl_phmat_csr_row_offsets(ccl_phmat_csr* A) {
  return &(A->row_offsets());
}

ccl_phvec_dense_i* ccl_phmat_csr_column_indices(ccl_phmat_csr* A) {
  return &(A->column_indices());
}

ccl_phvec_dense_v* ccl_phmat_csr_values(ccl_phmat_csr* A) {
  return &(A->values());
}

void ccl_phmat_csr_set_row_offsets_at(ccl_phmat_csr* A, ccl_index_t i,
                                      ccl_index_t val) {
  A->row_offsets(i) = val;
}

void ccl_phmat_csr_set_column_indices_at(ccl_phmat_csr* A, ccl_index_t i,
                                         ccl_index_t val) {
  A->column_indices(i) = val;
}

void ccl_phmat_csr_set_values_at(ccl_phmat_csr* A, ccl_index_t i,
                                 ccl_value_t val) {
  A->values(i) = val;
}

ccl_formats_e ccl_phmat_csr_format_enum(ccl_phmat_csr* A) {
  return A->format_enum();
}

int ccl_phmat_csr_format_index(ccl_phmat_csr* A) { return A->format_index(); }

void ccl_phmat_csr_hostmirror_create_default(ccl_phmat_csr_hostmirror** A) {
  *A = (new ccl_phmat_csr_hostmirror());
}

void ccl_phmat_csr_hostmirror_create(ccl_phmat_csr_hostmirror** A,
                                     ccl_index_t nrows, ccl_index_t ncols,
                                     ccl_index_t nnnz) {
  *A = (new ccl_phmat_csr_hostmirror("ccl_phmat_csr_hostmirror::", nrows, ncols,
                                     nnnz));
}

void ccl_phmat_csr_hostmirror_create_from_phmat_csr_hostmirror(
    ccl_phmat_csr_hostmirror* src, ccl_phmat_csr_hostmirror** dst) {
  *dst = (new ccl_phmat_csr_hostmirror(*src));
}

void ccl_phmat_csr_hostmirror_create_from_phmat_dyn(
    ccl_phmat_dyn* src, ccl_phmat_csr_hostmirror** dst) {
  *dst = (new ccl_phmat_csr_hostmirror(*src));
}

void ccl_phmat_csr_hostmirror_resize(ccl_phmat_csr_hostmirror* A,
                                     const ccl_index_t num_rows,
                                     const ccl_index_t num_cols,
                                     const ccl_index_t num_nnz) {
  A->resize(num_rows, num_cols, num_nnz);
}

// Assumes dst matrix is always created
void ccl_phmat_csr_hostmirror_allocate_from_phmat_csr_hostmirror(
    ccl_phmat_csr_hostmirror* src, ccl_phmat_csr_hostmirror* dst) {
  dst->allocate("ccl_phmat_csr_hostmirror::allocate::", *src);
}

void ccl_phmat_csr_hostmirror_destroy(ccl_phmat_csr_hostmirror** A) {
  delete (*A);
}

ccl_index_t ccl_phmat_csr_hostmirror_nrows(ccl_phmat_csr_hostmirror* A) {
  return A->nrows();
}

ccl_index_t ccl_phmat_csr_hostmirror_ncols(ccl_phmat_csr_hostmirror* A) {
  return A->ncols();
}

ccl_index_t ccl_phmat_csr_hostmirror_nnnz(ccl_phmat_csr_hostmirror* A) {
  return A->nnnz();
}

void ccl_phmat_csr_hostmirror_set_nrows(ccl_phmat_csr_hostmirror* A,
                                        ccl_index_t nrows) {
  A->set_nrows(nrows);
}

void ccl_phmat_csr_hostmirror_set_ncols(ccl_phmat_csr_hostmirror* A,
                                        ccl_index_t ncols) {
  A->set_ncols(ncols);
}

void ccl_phmat_csr_hostmirror_set_nnnz(ccl_phmat_csr_hostmirror* A,
                                       ccl_index_t nnnz) {
  A->set_nnnz(nnnz);
}

ccl_index_t ccl_phmat_csr_hostmirror_row_offsets_at(ccl_phmat_csr_hostmirror* A,
                                                    ccl_index_t i) {
  return A->row_offsets(i);
}

ccl_index_t ccl_phmat_csr_hostmirror_column_indices_at(
    ccl_phmat_csr_hostmirror* A, ccl_index_t i) {
  return A->column_indices(i);
}

ccl_value_t ccl_phmat_csr_hostmirror_values_at(ccl_phmat_csr_hostmirror* A,
                                               ccl_index_t i) {
  return A->values(i);
}

ccl_phvec_dense_i_hostmirror* ccl_phmat_csr_hostmirror_row_offsets(
    ccl_phmat_csr_hostmirror* A) {
  return &(A->row_offsets());
}

ccl_phvec_dense_i_hostmirror* ccl_phmat_csr_hostmirror_column_indices(
    ccl_phmat_csr_hostmirror* A) {
  return &(A->column_indices());
}

ccl_phvec_dense_v_hostmirror* ccl_phmat_csr_hostmirror_values(
    ccl_phmat_csr_hostmirror* A) {
  return &(A->values());
}

void ccl_phmat_csr_hostmirror_set_row_offsets_at(ccl_phmat_csr_hostmirror* A,
                                                 ccl_index_t i,
                                                 ccl_index_t val) {
  A->row_offsets(i) = val;
}

void ccl_phmat_csr_hostmirror_set_column_indices_at(ccl_phmat_csr_hostmirror* A,
                                                    ccl_index_t i,
                                                    ccl_index_t val) {
  A->column_indices(i) = val;
}

void ccl_phmat_csr_hostmirror_set_values_at(ccl_phmat_csr_hostmirror* A,
                                            ccl_index_t i, ccl_value_t val) {
  A->values(i) = val;
}

ccl_formats_e ccl_phmat_csr_hostmirror_format_enum(
    ccl_phmat_csr_hostmirror* A) {
  return A->format_enum();
}

int ccl_phmat_csr_hostmirror_format_index(ccl_phmat_csr_hostmirror* A) {
  return A->format_index();
}
