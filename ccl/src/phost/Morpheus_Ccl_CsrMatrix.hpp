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

#ifndef MORPHEUS_CCL_PHOST_CSRMATRIX_HPP
#define MORPHEUS_CCL_PHOST_CSRMATRIX_HPP

#include <Morpheus_Ccl_Types.hpp>

#include <phost/fwd/Morpheus_Ccl_Fwd_CsrMatrix.hpp>
#include <phost/fwd/Morpheus_Ccl_Fwd_DynamicMatrix.hpp>
#include <phost/fwd/Morpheus_Ccl_Fwd_DenseVector.hpp>

#ifdef __cplusplus
extern "C" {
#endif

void ccl_phmat_csr_create_default(ccl_phmat_csr** A);

void ccl_phmat_csr_create(ccl_phmat_csr** A, ccl_index_t nrows,
                          ccl_index_t ncols, ccl_index_t nnnz);

void ccl_phmat_csr_create_from_phmat_csr(ccl_phmat_csr* src,
                                         ccl_phmat_csr** dst);

void ccl_phmat_csr_create_from_phmat_dyn(ccl_phmat_dyn* src,
                                         ccl_phmat_csr** dst);

void ccl_phmat_csr_resize(ccl_phmat_csr* A, const ccl_index_t num_rows,
                          const ccl_index_t num_cols,
                          const ccl_index_t num_nnz);

void ccl_phmat_csr_allocate_from_phmat_csr(ccl_phmat_csr* src,
                                           ccl_phmat_csr* dst);

void ccl_phmat_csr_destroy(ccl_phmat_csr** A);

// Base Routines
ccl_index_t ccl_phmat_csr_nrows(ccl_phmat_csr* A);
ccl_index_t ccl_phmat_csr_ncols(ccl_phmat_csr* A);
ccl_index_t ccl_phmat_csr_nnnz(ccl_phmat_csr* A);

void ccl_phmat_csr_set_nrows(ccl_phmat_csr* A, ccl_index_t nrows);
void ccl_phmat_csr_set_ncols(ccl_phmat_csr* A, ccl_index_t ncols);
void ccl_phmat_csr_set_nnnz(ccl_phmat_csr* A, ccl_index_t nnnz);

// Format Specific Routines
ccl_index_t ccl_phmat_csr_row_offsets_at(ccl_phmat_csr* A, ccl_index_t i);
ccl_index_t ccl_phmat_csr_column_indices_at(ccl_phmat_csr* A, ccl_index_t i);
ccl_value_t ccl_phmat_csr_values_at(ccl_phmat_csr* A, ccl_index_t i);

ccl_phvec_dense_i* ccl_phmat_csr_row_offsets(ccl_phmat_csr* A);
ccl_phvec_dense_i* ccl_phmat_csr_column_indices(ccl_phmat_csr* A);
ccl_phvec_dense_v* ccl_phmat_csr_values(ccl_phmat_csr* A);

void ccl_phmat_csr_set_row_offsets_at(ccl_phmat_csr* A, ccl_index_t i,
                                      ccl_index_t val);
void ccl_phmat_csr_set_column_indices_at(ccl_phmat_csr* A, ccl_index_t i,
                                         ccl_index_t val);
void ccl_phmat_csr_set_values_at(ccl_phmat_csr* A, ccl_index_t i,
                                 ccl_value_t val);

// Other Routines
ccl_formats_e ccl_phmat_csr_format_enum(ccl_phmat_csr* A);
int ccl_phmat_csr_format_index(ccl_phmat_csr* A);

#ifdef __cplusplus
}
#endif

#endif  // MORPHEUS_CCL_PHOST_CSRMATRIX_HPP
