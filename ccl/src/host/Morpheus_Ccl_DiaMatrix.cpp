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

#include <host/Morpheus_Ccl_DiaMatrix.hpp>

void morpheus_ccl_create_default_hmat_dia(ccl_hmat_dia** A) {
  *A = (new ccl_hmat_dia());
}

void morpheus_ccl_create_hmat_dia(ccl_hmat_dia** A, ccl_index_t nrows,
                                  ccl_index_t ncols, ccl_index_t nnnz,
                                  ccl_index_t ndiags) {
  *A = (new ccl_hmat_dia("ccl_hmat_dia::", nrows, ncols, nnnz, ndiags));
}

void morpheus_ccl_create_aligned_hmat_dia(ccl_hmat_dia** A, ccl_index_t nrows,
                                          ccl_index_t ncols, ccl_index_t nnnz,
                                          ccl_index_t ndiags,
                                          ccl_index_t alginment) {
  *A = (new ccl_hmat_dia("ccl_hmat_dia::", nrows, ncols, nnnz, ndiags,
                         alginment));
}

void morpheus_ccl_create_hmat_dia_from_hmat_dia(ccl_hmat_dia* src,
                                                ccl_hmat_dia** dst) {
  *dst = (new ccl_hmat_dia(*src));
}

void morpheus_ccl_create_hmat_dia_from_hmat_dyn(ccl_hmat_dyn* src,
                                                ccl_hmat_dia** dst) {
  *dst = (new ccl_hmat_dia(*src));
}

void morpheus_ccl_resize_hmat_dia(ccl_hmat_dia* A, const ccl_index_t num_rows,
                                  const ccl_index_t num_cols,
                                  const ccl_index_t num_nnz,
                                  const ccl_index_t num_diagonals) {
  A->resize(num_rows, num_cols, num_nnz, num_diagonals);
}

void morpheus_ccl_resize_aligned_hmat_dia(ccl_hmat_dia* A,
                                          const ccl_index_t num_rows,
                                          const ccl_index_t num_cols,
                                          const ccl_index_t num_nnz,
                                          const ccl_index_t num_diagonals,
                                          const ccl_index_t alginment) {
  A->resize(num_rows, num_cols, num_nnz, num_diagonals, alginment);
}

// Assumes dst matrix is always created
void morpheus_ccl_allocate_hmat_dia_from_hmat_dia(ccl_hmat_dia* src,
                                                  ccl_hmat_dia* dst) {
  dst->allocate("ccl_hmat_dia::allocate::", *src);
}

void morpheus_ccl_destroy_hmat_dia(ccl_hmat_dia** A) { delete (*A); }

ccl_index_t morpheus_ccl_nrows_hmat_dia(ccl_hmat_dia* A) { return A->nrows(); }

ccl_index_t morpheus_ccl_ncols_hmat_dia(ccl_hmat_dia* A) { return A->ncols(); }

ccl_index_t morpheus_ccl_nnnz_hmat_dia(ccl_hmat_dia* A) { return A->nnnz(); }

ccl_index_t morpheus_ccl_ndiags_hmat_dia(ccl_hmat_dia* A) {
  return A->ndiags();
}

ccl_index_t morpheus_ccl_alignment_hmat_dia(ccl_hmat_dia* A) {
  return A->alignment();
}

void morpheus_ccl_set_nrows_hmat_dia(ccl_hmat_dia* A, ccl_index_t nrows) {
  A->set_nrows(nrows);
}

void morpheus_ccl_set_ncols_hmat_dia(ccl_hmat_dia* A, ccl_index_t ncols) {
  A->set_ncols(ncols);
}

void morpheus_ccl_set_nnnz_hmat_dia(ccl_hmat_dia* A, ccl_index_t nnnz) {
  A->set_nnnz(nnnz);
}

void morpheus_ccl_set_ndiags_hmat_dia(ccl_hmat_dia* A, ccl_index_t ndiags) {
  A->set_ndiags(ndiags);
}

void morpheus_ccl_set_alignment_hmat_dia(ccl_hmat_dia* A,
                                         ccl_index_t alignment) {
  A->set_alignment(alignment);
}

ccl_index_t morpheus_ccl_diagonal_offests_at_dia(ccl_hmat_dia* A,
                                                 ccl_index_t i) {
  return A->diagonal_offsets(i);
}

ccl_value_t morpheus_ccl_values_at_dia(ccl_hmat_dia* A, ccl_index_t i,
                                       ccl_index_t j) {
  return A->values(i, j);
}

ccl_hvec_dense_i32_i32_r_h* morpheus_ccl_diagonal_offsets_dia(ccl_hmat_dia* A) {
  return &(A->diagonal_offsets());
}

ccl_hmat_dense* morpheus_ccl_values_dia(ccl_hmat_dia* A) {
  return &(A->values());
}

void morpheus_ccl_set_diagonal_offests_at_dia(ccl_hmat_dia* A, ccl_index_t i,
                                              ccl_index_t val) {
  A->diagonal_offsets(i) = val;
}

void morpheus_ccl_set_values_at_dia(ccl_hmat_dia* A, ccl_index_t i,
                                    ccl_index_t j, ccl_value_t val) {
  A->values(i, j) = val;
}

// ccl_formats_e morpheus_ccl_exceeds_tolerance_hmat_dia(
//     ccl_hmat_dia* A, const ccl_index_t num_rows,
//     const ccl_index_t num_entries, const ccl_index_t num_diagonals) {
//   return (*A).exceeds_tolerance(num_rows, num_entries, num_diagonals);
// }

ccl_formats_e morpheus_ccl_format_enum_hmat_dia(ccl_hmat_dia* A) {
  return A->format_enum();
}

int morpheus_ccl_format_index_hmat_dia(ccl_hmat_dia* A) {
  return A->format_index();
}
