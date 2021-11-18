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

#ifndef MORPHEUS_CCL_HOST_CSRMATRIX_HPP
#define MORPHEUS_CCL_HOST_CSRMATRIX_HPP

#include <Morpheus_Ccl_Types.hpp>

#include <host/fwd/Morpheus_Ccl_Fwd_CsrMatrix.hpp>
#include <host/fwd/Morpheus_Ccl_Fwd_DynamicMatrix.hpp>
#include <host/fwd/Morpheus_Ccl_Fwd_DenseVector.hpp>

#ifdef __cplusplus
extern "C" {
#endif

void ccl_hmat_csr_create_default(ccl_hmat_csr** A);

void ccl_hmat_csr_create(ccl_hmat_csr** A, ccl_index_t nrows, ccl_index_t ncols,
                         ccl_index_t nnnz);

void ccl_hmat_csr_create_from_hmat_csr(ccl_hmat_csr* src, ccl_hmat_csr** dst);

void ccl_hmat_csr_create_from_hmat_dyn(ccl_hmat_dyn* src, ccl_hmat_csr** dst);

void ccl_hmat_csr_resize(ccl_hmat_csr* A, const ccl_index_t num_rows,
                         const ccl_index_t num_cols, const ccl_index_t num_nnz);

void ccl_hmat_csr_allocate_from_hmat_csr(ccl_hmat_csr* src, ccl_hmat_csr* dst);

void ccl_hmat_csr_destroy(ccl_hmat_csr** A);

// Base Routines
ccl_index_t ccl_hmat_csr_nrows(ccl_hmat_csr* A);
ccl_index_t ccl_hmat_csr_ncols(ccl_hmat_csr* A);
ccl_index_t ccl_hmat_csr_nnnz(ccl_hmat_csr* A);

void ccl_hmat_csr_set_nrows(ccl_hmat_csr* A, ccl_index_t nrows);
void ccl_hmat_csr_set_ncols(ccl_hmat_csr* A, ccl_index_t ncols);
void ccl_hmat_csr_set_nnnz(ccl_hmat_csr* A, ccl_index_t nnnz);

// Format Specific Routines
ccl_index_t ccl_hmat_csr_row_offsets_at(ccl_hmat_csr* A, ccl_index_t i);
ccl_index_t ccl_hmat_csr_column_indices_at(ccl_hmat_csr* A, ccl_index_t i);
ccl_value_t ccl_hmat_csr_values_at(ccl_hmat_csr* A, ccl_index_t i);

ccl_hvec_dense_i* ccl_hmat_csr_row_offsets(ccl_hmat_csr* A);
ccl_hvec_dense_i* ccl_hmat_csr_column_indices(ccl_hmat_csr* A);
ccl_hvec_dense_v* ccl_hmat_csr_values(ccl_hmat_csr* A);

void ccl_hmat_csr_set_row_offsets_at(ccl_hmat_csr* A, ccl_index_t i,
                                     ccl_index_t val);
void ccl_hmat_csr_set_column_indices_at(ccl_hmat_csr* A, ccl_index_t i,
                                        ccl_index_t val);
void ccl_hmat_csr_set_values_at(ccl_hmat_csr* A, ccl_index_t i,
                                ccl_value_t val);

// Other Routines
ccl_formats_e ccl_hmat_csr_format_enum(ccl_hmat_csr* A);
int ccl_hmat_csr_format_index(ccl_hmat_csr* A);

// HostMirror Interface
void ccl_hmat_csr_hostmirror_create_default(ccl_hmat_csr_hostmirror** A);

void ccl_hmat_csr_hostmirror_create(ccl_hmat_csr_hostmirror** A,
                                    ccl_index_t nrows, ccl_index_t ncols,
                                    ccl_index_t nnnz);

void ccl_hmat_csr_hostmirror_create_from_hmat_csr_hostmirror(
    ccl_hmat_csr_hostmirror* src, ccl_hmat_csr_hostmirror** dst);

void ccl_hmat_csr_hostmirror_create_from_hmat_dyn_hostmirror(
    ccl_hmat_dyn_hostmirror* src, ccl_hmat_csr_hostmirror** dst);

void ccl_hmat_csr_hostmirror_resize(ccl_hmat_csr_hostmirror* A,
                                    const ccl_index_t num_rows,
                                    const ccl_index_t num_cols,
                                    const ccl_index_t num_nnz);

void ccl_hmat_csr_hostmirror_allocate_from_hmat_csr_hostmirror(
    ccl_hmat_csr_hostmirror* src, ccl_hmat_csr_hostmirror* dst);

void ccl_hmat_csr_hostmirror_destroy(ccl_hmat_csr_hostmirror** A);

// Base Routines
ccl_index_t ccl_hmat_csr_hostmirror_nrows(ccl_hmat_csr_hostmirror* A);
ccl_index_t ccl_hmat_csr_hostmirror_ncols(ccl_hmat_csr_hostmirror* A);
ccl_index_t ccl_hmat_csr_hostmirror_nnnz(ccl_hmat_csr_hostmirror* A);

void ccl_hmat_csr_hostmirror_set_nrows(ccl_hmat_csr_hostmirror* A,
                                       ccl_index_t nrows);
void ccl_hmat_csr_hostmirror_set_ncols(ccl_hmat_csr_hostmirror* A,
                                       ccl_index_t ncols);
void ccl_hmat_csr_hostmirror_set_nnnz(ccl_hmat_csr_hostmirror* A,
                                      ccl_index_t nnnz);

// Format Specific Routines
ccl_index_t ccl_hmat_csr_hostmirror_row_offsets_at(ccl_hmat_csr_hostmirror* A,
                                                   ccl_index_t i);
ccl_index_t ccl_hmat_csr_hostmirror_column_indices_at(
    ccl_hmat_csr_hostmirror* A, ccl_index_t i);
ccl_value_t ccl_hmat_csr_hostmirror_values_at(ccl_hmat_csr_hostmirror* A,
                                              ccl_index_t i);

ccl_hvec_dense_i_hostmirror* ccl_hmat_csr_hostmirror_row_offsets(
    ccl_hmat_csr_hostmirror* A);
ccl_hvec_dense_i_hostmirror* ccl_hmat_csr_hostmirror_column_indices(
    ccl_hmat_csr_hostmirror* A);
ccl_hvec_dense_v_hostmirror* ccl_hmat_csr_hostmirror_values(
    ccl_hmat_csr_hostmirror* A);

void ccl_hmat_csr_hostmirror_set_row_offsets_at(ccl_hmat_csr_hostmirror* A,
                                                ccl_index_t i, ccl_index_t val);
void ccl_hmat_csr_hostmirror_set_column_indices_at(ccl_hmat_csr_hostmirror* A,
                                                   ccl_index_t i,
                                                   ccl_index_t val);
void ccl_hmat_csr_hostmirror_set_values_at(ccl_hmat_csr_hostmirror* A,
                                           ccl_index_t i, ccl_value_t val);

// Other Routines
ccl_formats_e ccl_hmat_csr_hostmirror_format_enum(ccl_hmat_csr_hostmirror* A);
int ccl_hmat_csr_hostmirror_format_index(ccl_hmat_csr_hostmirror* A);

#ifdef __cplusplus
}
#endif

#endif  // MORPHEUS_CCL_HOST_CSRMATRIX_HPP
