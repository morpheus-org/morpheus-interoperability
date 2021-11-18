/**
 * Morpheus_Ccl_CsrMatrix.hpp
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

#ifndef MORPHEUS_CCL_DEV_CSRMATRIX_HPP
#define MORPHEUS_CCL_DEV_CSRMATRIX_HPP

#include <Morpheus_Ccl_Types.hpp>

#include <dev/fwd/Morpheus_Ccl_Fwd_CsrMatrix.hpp>
#include <dev/fwd/Morpheus_Ccl_Fwd_DynamicMatrix.hpp>
#include <dev/fwd/Morpheus_Ccl_Fwd_DenseVector.hpp>

#ifdef __cplusplus
extern "C" {
#endif

void ccl_dmat_csr_create_default(ccl_dmat_csr** A);

void ccl_dmat_csr_create(ccl_dmat_csr** A, ccl_index_t nrows, ccl_index_t ncols,
                         ccl_index_t nnnz);

void ccl_dmat_csr_create_from_dmat_csr(ccl_dmat_csr* src, ccl_dmat_csr** dst);

void ccl_dmat_csr_create_from_dmat_dyn(ccl_dmat_dyn* src, ccl_dmat_csr** dst);

void ccl_dmat_csr_resize(ccl_dmat_csr* A, const ccl_index_t num_rows,
                         const ccl_index_t num_cols, const ccl_index_t num_nnz);

void ccl_dmat_csr_allocate_from_dmat_csr(ccl_dmat_csr* src, ccl_dmat_csr* dst);

void ccl_dmat_csr_destroy(ccl_dmat_csr** A);

// Base Routines
ccl_index_t ccl_dmat_csr_nrows(ccl_dmat_csr* A);
ccl_index_t ccl_dmat_csr_ncols(ccl_dmat_csr* A);
ccl_index_t ccl_dmat_csr_nnnz(ccl_dmat_csr* A);

void ccl_dmat_csr_set_nrows(ccl_dmat_csr* A, ccl_index_t nrows);
void ccl_dmat_csr_set_ncols(ccl_dmat_csr* A, ccl_index_t ncols);
void ccl_dmat_csr_set_nnnz(ccl_dmat_csr* A, ccl_index_t nnnz);

// Format Specific Routines
ccl_dvec_dense_i* ccl_dmat_csr_row_offsets(ccl_dmat_csr* A);
ccl_dvec_dense_i* ccl_dmat_csr_column_indices(ccl_dmat_csr* A);
ccl_dvec_dense_v* ccl_dmat_csr_values(ccl_dmat_csr* A);

// Other Routines
ccl_formats_e ccl_dmat_csr_format_enum(ccl_dmat_csr* A);
int ccl_dmat_csr_format_index(ccl_dmat_csr* A);

// HostMirror Interface
void ccl_dmat_csr_hostmirror_create_default(ccl_dmat_csr_hostmirror** A);

void ccl_dmat_csr_hostmirror_create(ccl_dmat_csr_hostmirror** A,
                                    ccl_index_t nrows, ccl_index_t ncols,
                                    ccl_index_t nnnz);

void ccl_dmat_csr_hostmirror_create_from_dmat_csr_hostmirror(
    ccl_dmat_csr_hostmirror* src, ccl_dmat_csr_hostmirror** dst);

void ccl_dmat_csr_hostmirror_create_from_dmat_dyn_hostmirror(
    ccl_dmat_dyn_hostmirror* src, ccl_dmat_csr_hostmirror** dst);

void ccl_dmat_csr_hostmirror_resize(ccl_dmat_csr_hostmirror* A,
                                    const ccl_index_t num_rows,
                                    const ccl_index_t num_cols,
                                    const ccl_index_t num_nnz);

void ccl_dmat_csr_hostmirror_allocate_from_dmat_csr_hostmirror(
    ccl_dmat_csr_hostmirror* src, ccl_dmat_csr_hostmirror* dst);

void ccl_dmat_csr_hostmirror_destroy(ccl_dmat_csr_hostmirror** A);

// Base Routines
ccl_index_t ccl_dmat_csr_hostmirror_nrows(ccl_dmat_csr_hostmirror* A);
ccl_index_t ccl_dmat_csr_hostmirror_ncols(ccl_dmat_csr_hostmirror* A);
ccl_index_t ccl_dmat_csr_hostmirror_nnnz(ccl_dmat_csr_hostmirror* A);

void ccl_dmat_csr_hostmirror_set_nrows(ccl_dmat_csr_hostmirror* A,
                                       ccl_index_t nrows);
void ccl_dmat_csr_hostmirror_set_ncols(ccl_dmat_csr_hostmirror* A,
                                       ccl_index_t ncols);
void ccl_dmat_csr_hostmirror_set_nnnz(ccl_dmat_csr_hostmirror* A,
                                      ccl_index_t nnnz);

// Format Specific Routines
ccl_index_t ccl_dmat_csr_hostmirror_row_offsets_at(ccl_dmat_csr_hostmirror* A,
                                                   ccl_index_t i);
ccl_index_t ccl_dmat_csr_hostmirror_column_indices_at(
    ccl_dmat_csr_hostmirror* A, ccl_index_t i);
ccl_value_t ccl_dmat_csr_hostmirror_values_at(ccl_dmat_csr_hostmirror* A,
                                              ccl_index_t i);

ccl_dvec_dense_i_hostmirror* ccl_dmat_csr_hostmirror_row_offsets(
    ccl_dmat_csr_hostmirror* A);
ccl_dvec_dense_i_hostmirror* ccl_dmat_csr_hostmirror_column_indices(
    ccl_dmat_csr_hostmirror* A);
ccl_dvec_dense_v_hostmirror* ccl_dmat_csr_hostmirror_values(
    ccl_dmat_csr_hostmirror* A);

void ccl_dmat_csr_hostmirror_set_row_offsets_at(ccl_dmat_csr_hostmirror* A,
                                                ccl_index_t i, ccl_index_t val);
void ccl_dmat_csr_hostmirror_set_column_indices_at(ccl_dmat_csr_hostmirror* A,
                                                   ccl_index_t i,
                                                   ccl_index_t val);
void ccl_dmat_csr_hostmirror_set_values_at(ccl_dmat_csr_hostmirror* A,
                                           ccl_index_t i, ccl_value_t val);

// Other Routines
ccl_formats_e ccl_dmat_csr_hostmirror_format_enum(ccl_dmat_csr_hostmirror* A);
int ccl_dmat_csr_hostmirror_format_index(ccl_dmat_csr_hostmirror* A);

#ifdef __cplusplus
}
#endif

#endif  // MORPHEUS_CCL_DEV_CSRMATRIX_HPP
