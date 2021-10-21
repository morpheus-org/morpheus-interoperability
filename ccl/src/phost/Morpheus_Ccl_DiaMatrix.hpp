/**
 * Morpheus_Ccl_DiaMatrix.hpp
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

#ifndef MORPHEUS_CCL_PHOST_DIAMATRIX_HPP
#define MORPHEUS_CCL_PHOST_DIAMATRIX_HPP

#include <Morpheus_Ccl_Types.hpp>

#include <fwd/Morpheus_Ccl_Fwd_DiaMatrix.hpp>
#include <fwd/Morpheus_Ccl_Fwd_DynamicMatrix.hpp>
#include <fwd/Morpheus_Ccl_Fwd_DenseVector.hpp>
#include <fwd/Morpheus_Ccl_Fwd_DenseMatrix.hpp>

#ifdef __cplusplus
extern "C" {
#endif

void ccl_phmat_dia_create_default(ccl_phmat_dia** A);

void ccl_phmat_dia_create(ccl_phmat_dia** A, ccl_index_t nrows,
                          ccl_index_t ncols, ccl_index_t nnnz,
                          ccl_index_t ndiags);

void ccl_phmat_dia_create_aligned(ccl_phmat_dia** A, ccl_index_t nrows,
                                  ccl_index_t ncols, ccl_index_t nnnz,
                                  ccl_index_t ndiags, ccl_index_t alginment);

void ccl_phmat_dia_create_from_phmat_dia(ccl_phmat_dia* src,
                                         ccl_phmat_dia** dst);

void ccl_phmat_dia_create_from_phmat_dyn(ccl_phmat_dyn* src,
                                         ccl_phmat_dia** dst);

void ccl_phmat_dia_resize(ccl_phmat_dia* A, const ccl_index_t num_rows,
                          const ccl_index_t num_cols, const ccl_index_t num_nnz,
                          const ccl_index_t num_diagonals);

void ccl_phmat_dia_resize_aligned(ccl_phmat_dia* A, const ccl_index_t num_rows,
                                  const ccl_index_t num_cols,
                                  const ccl_index_t num_nnz,
                                  const ccl_index_t num_diagonals,
                                  const ccl_index_t alginment);

void ccl_phmat_dia_allocate_from_phmat_dia(ccl_phmat_dia* src,
                                           ccl_phmat_dia* dst);

void ccl_phmat_dia_destroy(ccl_phmat_dia** A);

// Base Routines
ccl_index_t ccl_phmat_dia_nrows(ccl_phmat_dia* A);
ccl_index_t ccl_phmat_dia_ncols(ccl_phmat_dia* A);
ccl_index_t ccl_phmat_dia_nnnz(ccl_phmat_dia* A);

void ccl_phmat_dia_set_nrows(ccl_phmat_dia* A, ccl_index_t nrows);
void ccl_phmat_dia_set_ncols(ccl_phmat_dia* A, ccl_index_t ncols);
void ccl_phmat_dia_set_nnnz(ccl_phmat_dia* A, ccl_index_t nnnz);

// Format Specific Routines
ccl_index_t ccl_phmat_dia_ndiags(ccl_phmat_dia* A);
ccl_index_t ccl_phmat_dia_alignment(ccl_phmat_dia* A);

void ccl_phmat_dia_set_ndiags(ccl_phmat_dia* A, ccl_index_t ndiags);
void ccl_phmat_dia_set_alignment(ccl_phmat_dia* A, ccl_index_t alignment);

ccl_index_t ccl_phmat_dia_diagonal_offests_at(ccl_phmat_dia* A, ccl_index_t i);
ccl_value_t ccl_phmat_dia_values_at(ccl_phmat_dia* A, ccl_index_t i,
                                    ccl_index_t j);

ccl_phvec_dense_i* ccl_phmat_dia_diagonal_offsets(ccl_phmat_dia* A);
ccl_phmat_dense* ccl_phmat_dia_values(ccl_phmat_dia* A);

void ccl_phmat_dia_set_diagonal_offests_at(ccl_phmat_dia* A, ccl_index_t i,
                                           ccl_index_t val);
void ccl_phmat_dia_set_values_at(ccl_phmat_dia* A, ccl_index_t i, ccl_index_t j,
                                 ccl_value_t val);

ccl_bool_t ccl_phmat_dia_exceeds_tolerance(ccl_phmat_dia* A,
                                           const ccl_index_t num_rows,
                                           const ccl_index_t num_entries,
                                           const ccl_index_t num_diagonals);

// Other Routines
ccl_formats_e ccl_phmat_dia_format_enum(ccl_phmat_dia* A);
int ccl_phmat_dia_format_index(ccl_phmat_dia* A);

// HostMirror Interface
void ccl_phmat_dia_hostmirror_create_default(ccl_phmat_dia_hostmirror** A);

void ccl_phmat_dia_hostmirror_create(ccl_phmat_dia_hostmirror** A,
                                     ccl_index_t nrows, ccl_index_t ncols,
                                     ccl_index_t nnnz, ccl_index_t ndiags);

void ccl_phmat_dia_hostmirror_create_aligned(
    ccl_phmat_dia_hostmirror** A, ccl_index_t nrows, ccl_index_t ncols,
    ccl_index_t nnnz, ccl_index_t ndiags, ccl_index_t alginment);

void ccl_phmat_dia_hostmirror_create_from_phmat_dia(
    ccl_phmat_dia_hostmirror* src, ccl_phmat_dia_hostmirror** dst);

void ccl_phmat_dia_hostmirror_create_from_phmat_dyn_hostmirror(
    ccl_phmat_dyn_hostmirror* src, ccl_phmat_dia_hostmirror** dst);

void ccl_phmat_dia_hostmirror_resize(ccl_phmat_dia_hostmirror* A,
                                     const ccl_index_t num_rows,
                                     const ccl_index_t num_cols,
                                     const ccl_index_t num_nnz,
                                     const ccl_index_t num_diagonals);

void ccl_phmat_dia_hostmirror_resize_aligned(ccl_phmat_dia_hostmirror* A,
                                             const ccl_index_t num_rows,
                                             const ccl_index_t num_cols,
                                             const ccl_index_t num_nnz,
                                             const ccl_index_t num_diagonals,
                                             const ccl_index_t alginment);

void ccl_phmat_dia_hostmirror_allocate_from_phmat_dia(
    ccl_phmat_dia_hostmirror* src, ccl_phmat_dia_hostmirror* dst);

void ccl_phmat_dia_hostmirror_destroy(ccl_phmat_dia_hostmirror** A);

// Base Routines
ccl_index_t ccl_phmat_dia_hostmirror_nrows(ccl_phmat_dia_hostmirror* A);
ccl_index_t ccl_phmat_dia_hostmirror_ncols(ccl_phmat_dia_hostmirror* A);
ccl_index_t ccl_phmat_dia_hostmirror_nnnz(ccl_phmat_dia_hostmirror* A);

void ccl_phmat_dia_hostmirror_set_nrows(ccl_phmat_dia_hostmirror* A,
                                        ccl_index_t nrows);
void ccl_phmat_dia_hostmirror_set_ncols(ccl_phmat_dia_hostmirror* A,
                                        ccl_index_t ncols);
void ccl_phmat_dia_hostmirror_set_nnnz(ccl_phmat_dia_hostmirror* A,
                                       ccl_index_t nnnz);

// Format Specific Routines
ccl_index_t ccl_phmat_dia_hostmirror_ndiags(ccl_phmat_dia_hostmirror* A);
ccl_index_t ccl_phmat_dia_hostmirror_alignment(ccl_phmat_dia_hostmirror* A);

void ccl_phmat_dia_hostmirror_set_ndiags(ccl_phmat_dia_hostmirror* A,
                                         ccl_index_t ndiags);
void ccl_phmat_dia_hostmirror_set_alignment(ccl_phmat_dia_hostmirror* A,
                                            ccl_index_t alignment);

ccl_index_t ccl_phmat_dia_hostmirror_diagonal_offests_at(
    ccl_phmat_dia_hostmirror* A, ccl_index_t i);
ccl_value_t ccl_phmat_dia_hostmirror_values_at(ccl_phmat_dia_hostmirror* A,
                                               ccl_index_t i, ccl_index_t j);

ccl_phvec_dense_i_hostmirror* ccl_phmat_dia_hostmirror_diagonal_offsets(
    ccl_phmat_dia_hostmirror* A);
ccl_phmat_dense_hostmirror* ccl_phmat_dia_hostmirror_values(
    ccl_phmat_dia_hostmirror* A);

void ccl_phmat_dia_hostmirror_set_diagonal_offests_at(
    ccl_phmat_dia_hostmirror* A, ccl_index_t i, ccl_index_t val);
void ccl_phmat_dia_hostmirror_set_values_at(ccl_phmat_dia_hostmirror* A,
                                            ccl_index_t i, ccl_index_t j,
                                            ccl_value_t val);

ccl_bool_t ccl_phmat_dia_hostmirror_exceeds_tolerance(
    ccl_phmat_dia_hostmirror* A, const ccl_index_t num_rows,
    const ccl_index_t num_entries, const ccl_index_t num_diagonals);

// Other Routines
ccl_formats_e ccl_phmat_dia_hostmirror_format_enum(ccl_phmat_dia_hostmirror* A);
int ccl_phmat_dia_hostmirror_format_index(ccl_phmat_dia_hostmirror* A);

#ifdef __cplusplus
}
#endif

#endif  // MORPHEUS_CCL_PHOST_DIAMATRIX_HPP
