/**
 * Morpheus_Ccl_DiaMatrix.cpp
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

#include <phost/Morpheus_Ccl_DiaMatrix.hpp>

void ccl_phmat_dia_create_default(ccl_phmat_dia** A) {
  *A = (new ccl_phmat_dia());
}

void ccl_phmat_dia_create(ccl_phmat_dia** A, ccl_index_t nrows,
                          ccl_index_t ncols, ccl_index_t nnnz,
                          ccl_index_t ndiags) {
  *A = (new ccl_phmat_dia("ccl_phmat_dia::", nrows, ncols, nnnz, ndiags));
}

void ccl_phmat_dia_create_aligned(ccl_phmat_dia** A, ccl_index_t nrows,
                                  ccl_index_t ncols, ccl_index_t nnnz,
                                  ccl_index_t ndiags, ccl_index_t alginment) {
  *A = (new ccl_phmat_dia("ccl_phmat_dia::", nrows, ncols, nnnz, ndiags,
                          alginment));
}

void ccl_phmat_dia_create_from_phmat_dia(ccl_phmat_dia* src,
                                         ccl_phmat_dia** dst) {
  *dst = (new ccl_phmat_dia(*src));
}

void ccl_phmat_dia_create_from_phmat_dyn(ccl_phmat_dyn* src,
                                         ccl_phmat_dia** dst) {
  *dst = (new ccl_phmat_dia(*src));
}

void ccl_phmat_dia_resize(ccl_phmat_dia* A, const ccl_index_t num_rows,
                          const ccl_index_t num_cols, const ccl_index_t num_nnz,
                          const ccl_index_t num_diagonals) {
  A->resize(num_rows, num_cols, num_nnz, num_diagonals);
}

void ccl_phmat_dia_resize_aligned(ccl_phmat_dia* A, const ccl_index_t num_rows,
                                  const ccl_index_t num_cols,
                                  const ccl_index_t num_nnz,
                                  const ccl_index_t num_diagonals,
                                  const ccl_index_t alginment) {
  A->resize(num_rows, num_cols, num_nnz, num_diagonals, alginment);
}

// Assumes dst matrix is always created
void ccl_phmat_dia_allocate_from_phmat_dia(ccl_phmat_dia* src,
                                           ccl_phmat_dia* dst) {
  dst->allocate("ccl_phmat_dia::allocate::", *src);
}

void ccl_phmat_dia_destroy(ccl_phmat_dia** A) { delete (*A); }

ccl_index_t ccl_phmat_dia_nrows(ccl_phmat_dia* A) { return A->nrows(); }

ccl_index_t ccl_phmat_dia_ncols(ccl_phmat_dia* A) { return A->ncols(); }

ccl_index_t ccl_phmat_dia_nnnz(ccl_phmat_dia* A) { return A->nnnz(); }

ccl_index_t ccl_phmat_dia_ndiags(ccl_phmat_dia* A) { return A->ndiags(); }

ccl_index_t ccl_phmat_dia_alignment(ccl_phmat_dia* A) { return A->alignment(); }

void ccl_phmat_dia_set_nrows(ccl_phmat_dia* A, ccl_index_t nrows) {
  A->set_nrows(nrows);
}

void ccl_phmat_dia_set_ncols(ccl_phmat_dia* A, ccl_index_t ncols) {
  A->set_ncols(ncols);
}

void ccl_phmat_dia_set_nnnz(ccl_phmat_dia* A, ccl_index_t nnnz) {
  A->set_nnnz(nnnz);
}

void ccl_phmat_dia_set_ndiags(ccl_phmat_dia* A, ccl_index_t ndiags) {
  A->set_ndiags(ndiags);
}

void ccl_phmat_dia_set_alignment(ccl_phmat_dia* A, ccl_index_t alignment) {
  A->set_alignment(alignment);
}

ccl_index_t ccl_phmat_dia_diagonal_offests_at(ccl_phmat_dia* A, ccl_index_t i) {
  return A->diagonal_offsets(i);
}

ccl_value_t ccl_phmat_dia_values_at(ccl_phmat_dia* A, ccl_index_t i,
                                    ccl_index_t j) {
  return A->values(i, j);
}

ccl_phvec_dense_i* ccl_phmat_dia_diagonal_offsets(ccl_phmat_dia* A) {
  return &(A->diagonal_offsets());
}

ccl_phmat_dense* ccl_phmat_dia_values(ccl_phmat_dia* A) {
  return &(A->values());
}

void ccl_phmat_dia_set_diagonal_offests_at(ccl_phmat_dia* A, ccl_index_t i,
                                           ccl_index_t val) {
  A->diagonal_offsets(i) = val;
}

void ccl_phmat_dia_set_values_at(ccl_phmat_dia* A, ccl_index_t i, ccl_index_t j,
                                 ccl_value_t val) {
  A->values(i, j) = val;
}

// ccl_formats_e ccl_phmat_dia_exceeds_tolerance(
//     ccl_phmat_dia* A, const ccl_index_t num_rows,
//     const ccl_index_t num_entries, const ccl_index_t num_diagonals) {
//   return (*A).exceeds_tolerance(num_rows, num_entries, num_diagonals);
// }

ccl_formats_e ccl_phmat_dia_format_enum(ccl_phmat_dia* A) {
  return A->format_enum();
}

int ccl_phmat_dia_format_index(ccl_phmat_dia* A) { return A->format_index(); }

// HostMirror Interface
void ccl_phmat_dia_hostmirror_create_default(ccl_phmat_dia_hostmirror** A) {
  *A = (new ccl_phmat_dia_hostmirror());
}

void ccl_phmat_dia_hostmirror_create(ccl_phmat_dia_hostmirror** A,
                                     ccl_index_t nrows, ccl_index_t ncols,
                                     ccl_index_t nnnz, ccl_index_t ndiags) {
  *A = (new ccl_phmat_dia_hostmirror("ccl_phmat_dia_hostmirror::", nrows, ncols,
                                     nnnz, ndiags));
}

void ccl_phmat_dia_hostmirror_create_aligned(
    ccl_phmat_dia_hostmirror** A, ccl_index_t nrows, ccl_index_t ncols,
    ccl_index_t nnnz, ccl_index_t ndiags, ccl_index_t alginment) {
  *A = (new ccl_phmat_dia_hostmirror("ccl_phmat_dia_hostmirror::", nrows, ncols,
                                     nnnz, ndiags, alginment));
}

void ccl_phmat_dia_hostmirror_create_from_phmat_dia(
    ccl_phmat_dia_hostmirror* src, ccl_phmat_dia_hostmirror** dst) {
  *dst = (new ccl_phmat_dia_hostmirror(*src));
}

void ccl_phmat_dia_hostmirror_create_from_phmat_dyn_hostmirror(
    ccl_phmat_dyn_hostmirror* src, ccl_phmat_dia_hostmirror** dst) {
  *dst = (new ccl_phmat_dia_hostmirror(*src));
}

void ccl_phmat_dia_hostmirror_resize(ccl_phmat_dia_hostmirror* A,
                                     const ccl_index_t num_rows,
                                     const ccl_index_t num_cols,
                                     const ccl_index_t num_nnz,
                                     const ccl_index_t num_diagonals) {
  A->resize(num_rows, num_cols, num_nnz, num_diagonals);
}

void ccl_phmat_dia_hostmirror_resize_aligned(ccl_phmat_dia_hostmirror* A,
                                             const ccl_index_t num_rows,
                                             const ccl_index_t num_cols,
                                             const ccl_index_t num_nnz,
                                             const ccl_index_t num_diagonals,
                                             const ccl_index_t alginment) {
  A->resize(num_rows, num_cols, num_nnz, num_diagonals, alginment);
}

// Assumes dst matrix is always created
void ccl_phmat_dia_hostmirror_allocate_from_phmat_dia(
    ccl_phmat_dia_hostmirror* src, ccl_phmat_dia_hostmirror* dst) {
  dst->allocate("ccl_phmat_dia_hostmirror::allocate::", *src);
}

void ccl_phmat_dia_hostmirror_destroy(ccl_phmat_dia_hostmirror** A) {
  delete (*A);
}

ccl_index_t ccl_phmat_dia_hostmirror_nrows(ccl_phmat_dia_hostmirror* A) {
  return A->nrows();
}

ccl_index_t ccl_phmat_dia_hostmirror_ncols(ccl_phmat_dia_hostmirror* A) {
  return A->ncols();
}

ccl_index_t ccl_phmat_dia_hostmirror_nnnz(ccl_phmat_dia_hostmirror* A) {
  return A->nnnz();
}

ccl_index_t ccl_phmat_dia_hostmirror_ndiags(ccl_phmat_dia_hostmirror* A) {
  return A->ndiags();
}

ccl_index_t ccl_phmat_dia_hostmirror_alignment(ccl_phmat_dia_hostmirror* A) {
  return A->alignment();
}

void ccl_phmat_dia_hostmirror_set_nrows(ccl_phmat_dia_hostmirror* A,
                                        ccl_index_t nrows) {
  A->set_nrows(nrows);
}

void ccl_phmat_dia_hostmirror_set_ncols(ccl_phmat_dia_hostmirror* A,
                                        ccl_index_t ncols) {
  A->set_ncols(ncols);
}

void ccl_phmat_dia_hostmirror_set_nnnz(ccl_phmat_dia_hostmirror* A,
                                       ccl_index_t nnnz) {
  A->set_nnnz(nnnz);
}

void ccl_phmat_dia_hostmirror_set_ndiags(ccl_phmat_dia_hostmirror* A,
                                         ccl_index_t ndiags) {
  A->set_ndiags(ndiags);
}

void ccl_phmat_dia_hostmirror_set_alignment(ccl_phmat_dia_hostmirror* A,
                                            ccl_index_t alignment) {
  A->set_alignment(alignment);
}

ccl_index_t ccl_phmat_dia_hostmirror_diagonal_offests_at(
    ccl_phmat_dia_hostmirror* A, ccl_index_t i) {
  return A->diagonal_offsets(i);
}

ccl_value_t ccl_phmat_dia_hostmirror_values_at(ccl_phmat_dia_hostmirror* A,
                                               ccl_index_t i, ccl_index_t j) {
  return A->values(i, j);
}

ccl_phvec_dense_i_hostmirror* ccl_phmat_dia_hostmirror_diagonal_offsets(
    ccl_phmat_dia_hostmirror* A) {
  return &(A->diagonal_offsets());
}

ccl_phmat_dense_hostmirror* ccl_phmat_dia_hostmirror_values(
    ccl_phmat_dia_hostmirror* A) {
  return &(A->values());
}

void ccl_phmat_dia_hostmirror_set_diagonal_offests_at(
    ccl_phmat_dia_hostmirror* A, ccl_index_t i, ccl_index_t val) {
  A->diagonal_offsets(i) = val;
}

void ccl_phmat_dia_hostmirror_set_values_at(ccl_phmat_dia_hostmirror* A,
                                            ccl_index_t i, ccl_index_t j,
                                            ccl_value_t val) {
  A->values(i, j) = val;
}

// ccl_formats_e ccl_phmat_dia_hostmirror_exceeds_tolerance(
//     ccl_phmat_dia_hostmirror* A, const ccl_index_t num_rows,
//     const ccl_index_t num_entries, const ccl_index_t num_diagonals) {
//   return (*A).exceeds_tolerance(num_rows, num_entries, num_diagonals);
// }

ccl_formats_e ccl_phmat_dia_hostmirror_format_enum(
    ccl_phmat_dia_hostmirror* A) {
  return A->format_enum();
}

int ccl_phmat_dia_hostmirror_format_index(ccl_phmat_dia_hostmirror* A) {
  return A->format_index();
}
