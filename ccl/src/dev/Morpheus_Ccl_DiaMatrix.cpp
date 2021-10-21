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

#include <dev/Morpheus_Ccl_DiaMatrix.hpp>

void ccl_dmat_dia_create_default(ccl_dmat_dia** A) {
  *A = (new ccl_dmat_dia());
}

void ccl_dmat_dia_create(ccl_dmat_dia** A, ccl_index_t nrows, ccl_index_t ncols,
                         ccl_index_t nnnz, ccl_index_t ndiags) {
  *A = (new ccl_dmat_dia("ccl_dmat_dia::", nrows, ncols, nnnz, ndiags));
}

void ccl_dmat_dia_create_aligned(ccl_dmat_dia** A, ccl_index_t nrows,
                                 ccl_index_t ncols, ccl_index_t nnnz,
                                 ccl_index_t ndiags, ccl_index_t alginment) {
  *A = (new ccl_dmat_dia("ccl_dmat_dia::", nrows, ncols, nnnz, ndiags,
                         alginment));
}

void ccl_dmat_dia_create_from_dmat_dia(ccl_dmat_dia* src, ccl_dmat_dia** dst) {
  *dst = (new ccl_dmat_dia(*src));
}

void ccl_dmat_dia_create_from_dmat_dyn(ccl_dmat_dyn* src, ccl_dmat_dia** dst) {
  *dst = (new ccl_dmat_dia(*src));
}

void ccl_dmat_dia_resize(ccl_dmat_dia* A, const ccl_index_t num_rows,
                         const ccl_index_t num_cols, const ccl_index_t num_nnz,
                         const ccl_index_t num_diagonals) {
  A->resize(num_rows, num_cols, num_nnz, num_diagonals);
}

void ccl_dmat_dia_resize_aligned(ccl_dmat_dia* A, const ccl_index_t num_rows,
                                 const ccl_index_t num_cols,
                                 const ccl_index_t num_nnz,
                                 const ccl_index_t num_diagonals,
                                 const ccl_index_t alginment) {
  A->resize(num_rows, num_cols, num_nnz, num_diagonals, alginment);
}

// Assumes dst matrix is always created
void ccl_dmat_dia_allocate_from_dmat_dia(ccl_dmat_dia* src, ccl_dmat_dia* dst) {
  dst->allocate("ccl_dmat_dia::allocate::", *src);
}

void ccl_dmat_dia_destroy(ccl_dmat_dia** A) { delete (*A); }

ccl_index_t ccl_dmat_dia_nrows(ccl_dmat_dia* A) { return A->nrows(); }

ccl_index_t ccl_dmat_dia_ncols(ccl_dmat_dia* A) { return A->ncols(); }

ccl_index_t ccl_dmat_dia_nnnz(ccl_dmat_dia* A) { return A->nnnz(); }

ccl_index_t ccl_dmat_dia_ndiags(ccl_dmat_dia* A) { return A->ndiags(); }

ccl_index_t ccl_dmat_dia_alignment(ccl_dmat_dia* A) { return A->alignment(); }

void ccl_dmat_dia_set_nrows(ccl_dmat_dia* A, ccl_index_t nrows) {
  A->set_nrows(nrows);
}

void ccl_dmat_dia_set_ncols(ccl_dmat_dia* A, ccl_index_t ncols) {
  A->set_ncols(ncols);
}

void ccl_dmat_dia_set_nnnz(ccl_dmat_dia* A, ccl_index_t nnnz) {
  A->set_nnnz(nnnz);
}

void ccl_dmat_dia_set_ndiags(ccl_dmat_dia* A, ccl_index_t ndiags) {
  A->set_ndiags(ndiags);
}

void ccl_dmat_dia_set_alignment(ccl_dmat_dia* A, ccl_index_t alignment) {
  A->set_alignment(alignment);
}

ccl_dvec_dense_i* ccl_dmat_dia_diagonal_offsets(ccl_dmat_dia* A) {
  return &(A->diagonal_offsets());
}

ccl_dmat_dense* ccl_dmat_dia_values(ccl_dmat_dia* A) { return &(A->values()); }

// ccl_formats_e ccl_dmat_dia_exceeds_tolerance(
//     ccl_dmat_dia* A, const ccl_index_t num_rows,
//     const ccl_index_t num_entries, const ccl_index_t num_diagonals) {
//   return (*A).exceeds_tolerance(num_rows, num_entries, num_diagonals);
// }

ccl_formats_e ccl_dmat_dia_format_enum(ccl_dmat_dia* A) {
  return A->format_enum();
}

int ccl_dmat_dia_format_index(ccl_dmat_dia* A) { return A->format_index(); }

// HostMirror Interface
void ccl_dmat_dia_hostmirror_create_default(ccl_dmat_dia_hostmirror** A) {
  *A = (new ccl_dmat_dia_hostmirror());
}

void ccl_dmat_dia_hostmirror_create(ccl_dmat_dia_hostmirror** A,
                                    ccl_index_t nrows, ccl_index_t ncols,
                                    ccl_index_t nnnz, ccl_index_t ndiags) {
  *A = (new ccl_dmat_dia_hostmirror("ccl_dmat_dia_hostmirror::", nrows, ncols,
                                    nnnz, ndiags));
}

void ccl_dmat_dia_hostmirror_create_aligned(ccl_dmat_dia_hostmirror** A,
                                            ccl_index_t nrows,
                                            ccl_index_t ncols, ccl_index_t nnnz,
                                            ccl_index_t ndiags,
                                            ccl_index_t alginment) {
  *A = (new ccl_dmat_dia_hostmirror("ccl_dmat_dia_hostmirror::", nrows, ncols,
                                    nnnz, ndiags, alginment));
}

void ccl_dmat_dia_hostmirror_create_from_dmat_dia(
    ccl_dmat_dia_hostmirror* src, ccl_dmat_dia_hostmirror** dst) {
  *dst = (new ccl_dmat_dia_hostmirror(*src));
}

void ccl_dmat_dia_hostmirror_create_from_dmat_dyn(
    ccl_dmat_dyn* src, ccl_dmat_dia_hostmirror** dst) {
  *dst = (new ccl_dmat_dia_hostmirror(*src));
}

void ccl_dmat_dia_hostmirror_resize(ccl_dmat_dia_hostmirror* A,
                                    const ccl_index_t num_rows,
                                    const ccl_index_t num_cols,
                                    const ccl_index_t num_nnz,
                                    const ccl_index_t num_diagonals) {
  A->resize(num_rows, num_cols, num_nnz, num_diagonals);
}

void ccl_dmat_dia_hostmirror_resize_aligned(ccl_dmat_dia_hostmirror* A,
                                            const ccl_index_t num_rows,
                                            const ccl_index_t num_cols,
                                            const ccl_index_t num_nnz,
                                            const ccl_index_t num_diagonals,
                                            const ccl_index_t alginment) {
  A->resize(num_rows, num_cols, num_nnz, num_diagonals, alginment);
}

// Assumes dst matrix is always created
void ccl_dmat_dia_hostmirror_allocate_from_dmat_dia(
    ccl_dmat_dia_hostmirror* src, ccl_dmat_dia_hostmirror* dst) {
  dst->allocate("ccl_dmat_dia_hostmirror::allocate::", *src);
}

void ccl_dmat_dia_hostmirror_destroy(ccl_dmat_dia_hostmirror** A) {
  delete (*A);
}

ccl_index_t ccl_dmat_dia_hostmirror_nrows(ccl_dmat_dia_hostmirror* A) {
  return A->nrows();
}

ccl_index_t ccl_dmat_dia_hostmirror_ncols(ccl_dmat_dia_hostmirror* A) {
  return A->ncols();
}

ccl_index_t ccl_dmat_dia_hostmirror_nnnz(ccl_dmat_dia_hostmirror* A) {
  return A->nnnz();
}

ccl_index_t ccl_dmat_dia_hostmirror_ndiags(ccl_dmat_dia_hostmirror* A) {
  return A->ndiags();
}

ccl_index_t ccl_dmat_dia_hostmirror_alignment(ccl_dmat_dia_hostmirror* A) {
  return A->alignment();
}

void ccl_dmat_dia_hostmirror_set_nrows(ccl_dmat_dia_hostmirror* A,
                                       ccl_index_t nrows) {
  A->set_nrows(nrows);
}

void ccl_dmat_dia_hostmirror_set_ncols(ccl_dmat_dia_hostmirror* A,
                                       ccl_index_t ncols) {
  A->set_ncols(ncols);
}

void ccl_dmat_dia_hostmirror_set_nnnz(ccl_dmat_dia_hostmirror* A,
                                      ccl_index_t nnnz) {
  A->set_nnnz(nnnz);
}

void ccl_dmat_dia_hostmirror_set_ndiags(ccl_dmat_dia_hostmirror* A,
                                        ccl_index_t ndiags) {
  A->set_ndiags(ndiags);
}

void ccl_dmat_dia_hostmirror_set_alignment(ccl_dmat_dia_hostmirror* A,
                                           ccl_index_t alignment) {
  A->set_alignment(alignment);
}

ccl_index_t ccl_dmat_dia_hostmirror_diagonal_offests_at(
    ccl_dmat_dia_hostmirror* A, ccl_index_t i) {
  return A->diagonal_offsets(i);
}

ccl_value_t ccl_dmat_dia_hostmirror_values_at(ccl_dmat_dia_hostmirror* A,
                                              ccl_index_t i, ccl_index_t j) {
  return A->values(i, j);
}

ccl_dvec_dense_i_hostmirror* ccl_dmat_dia_hostmirror_diagonal_offsets(
    ccl_dmat_dia_hostmirror* A) {
  return &(A->diagonal_offsets());
}

ccl_dmat_dense_hostmirror* ccl_dmat_dia_hostmirror_values(
    ccl_dmat_dia_hostmirror* A) {
  return &(A->values());
}

void ccl_dmat_dia_hostmirror_set_diagonal_offests_at(ccl_dmat_dia_hostmirror* A,
                                                     ccl_index_t i,
                                                     ccl_index_t val) {
  A->diagonal_offsets(i) = val;
}

void ccl_dmat_dia_hostmirror_set_values_at(ccl_dmat_dia_hostmirror* A,
                                           ccl_index_t i, ccl_index_t j,
                                           ccl_value_t val) {
  A->values(i, j) = val;
}

// ccl_formats_e ccl_dmat_dia_hostmirror_exceeds_tolerance(
//     ccl_dmat_dia_hostmirror* A, const ccl_index_t num_rows,
//     const ccl_index_t num_entries, const ccl_index_t num_diagonals) {
//   return (*A).exceeds_tolerance(num_rows, num_entries, num_diagonals);
// }

ccl_formats_e ccl_dmat_dia_hostmirror_format_enum(ccl_dmat_dia_hostmirror* A) {
  return A->format_enum();
}

int ccl_dmat_dia_hostmirror_format_index(ccl_dmat_dia_hostmirror* A) {
  return A->format_index();
}
