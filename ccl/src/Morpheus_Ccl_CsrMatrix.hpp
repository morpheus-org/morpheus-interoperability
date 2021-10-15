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

#ifndef MORPHEUS_CCL_CSRMATRIX_HPP
#define MORPHEUS_CCL_CSRMATRIX_HPP

#include <Morpheus_Ccl_Types.hpp>
#include <fwd/Morpheus_Ccl_Fwd_CsrMatrix.hpp>
#include <fwd/Morpheus_Ccl_Fwd_DynamicMatrix.hpp>
#include <fwd/Morpheus_Ccl_Fwd_DenseVector.hpp>

#ifdef __cplusplus
extern "C" {
#endif

void morpheus_ccl_create_default_mat_csr_r64_i32_r_h(
    fcl_mat_csr_r64_i32_r_h** A);

void morpheus_ccl_create_mat_csr_r64_i32_r_h(fcl_mat_csr_r64_i32_r_h** A,
                                             ccl_index_t nrows,
                                             ccl_index_t ncols,
                                             ccl_index_t nnnz);

void morpheus_ccl_create_mat_csr_from_mat_csr_r64_i32_r_h(
    fcl_mat_csr_r64_i32_r_h* src, fcl_mat_csr_r64_i32_r_h** dst);

void morpheus_ccl_create_mat_csr_from_mat_dyn_r64_i32_r_h(
    fcl_mat_dyn_r64_i32_r_h* src, fcl_mat_csr_r64_i32_r_h** dst);

void morpheus_ccl_resize_mat_csr_r64_i32_r_h(fcl_mat_csr_r64_i32_r_h* A,
                                             const ccl_index_t num_rows,
                                             const ccl_index_t num_cols,
                                             const ccl_index_t num_nnz);

void morpheus_ccl_allocate_mat_csr_from_mat_csr_r64_i32_r_h(
    fcl_mat_csr_r64_i32_r_h* src, fcl_mat_csr_r64_i32_r_h* dst);

void morpheus_ccl_destroy_mat_csr_r64_i32_r_h(fcl_mat_csr_r64_i32_r_h** A);

// Base Routines
ccl_index_t morpheus_ccl_nrows_mat_csr_r64_i32_r_h(fcl_mat_csr_r64_i32_r_h* A);
ccl_index_t morpheus_ccl_ncols_mat_csr_r64_i32_r_h(fcl_mat_csr_r64_i32_r_h* A);
ccl_index_t morpheus_ccl_nnnz_mat_csr_r64_i32_r_h(fcl_mat_csr_r64_i32_r_h* A);

void morpheus_ccl_set_nrows_mat_csr_r64_i32_r_h(fcl_mat_csr_r64_i32_r_h* A,
                                                ccl_index_t nrows);
void morpheus_ccl_set_ncols_mat_csr_r64_i32_r_h(fcl_mat_csr_r64_i32_r_h* A,
                                                ccl_index_t ncols);
void morpheus_ccl_set_nnnz_mat_csr_r64_i32_r_h(fcl_mat_csr_r64_i32_r_h* A,
                                               ccl_index_t nnnz);

// Format Specific Routines
ccl_index_t morpheus_ccl_row_offsets_at_csr_r64_i32_r_h(
    fcl_mat_csr_r64_i32_r_h* A, ccl_index_t i);
ccl_index_t morpheus_ccl_column_indices_at_csr_r64_i32_r_h(
    fcl_mat_csr_r64_i32_r_h* A, ccl_index_t i);
ccl_value_t morpheus_ccl_values_at_csr_r64_i32_r_h(fcl_mat_csr_r64_i32_r_h* A,
                                                   ccl_index_t i);

fcl_vec_dense_i32_i32_r_h* morpheus_ccl_row_offsets_csr_r64_i32_r_h(
    fcl_mat_csr_r64_i32_r_h* A);
fcl_vec_dense_i32_i32_r_h* morpheus_ccl_column_indices_csr_r64_i32_r_h(
    fcl_mat_csr_r64_i32_r_h* A);
fcl_vec_dense_r64_i32_r_h* morpheus_ccl_values_csr_r64_i32_r_h(
    fcl_mat_csr_r64_i32_r_h* A);

void morpheus_ccl_set_row_offsets_at_csr_r64_i32_r_h(fcl_mat_csr_r64_i32_r_h* A,
                                                     ccl_index_t i,
                                                     ccl_index_t val);
void morpheus_ccl_set_column_indices_at_csr_r64_i32_r_h(
    fcl_mat_csr_r64_i32_r_h* A, ccl_index_t i, ccl_index_t val);
void morpheus_ccl_set_values_at_csr_r64_i32_r_h(fcl_mat_csr_r64_i32_r_h* A,
                                                ccl_index_t i, ccl_value_t val);

// Other Routines
ccl_formats_e morpheus_ccl_format_enum_mat_csr_r64_i32_r_h(
    fcl_mat_csr_r64_i32_r_h* A);
int morpheus_ccl_format_index_mat_csr_r64_i32_r_h(fcl_mat_csr_r64_i32_r_h* A);

#ifdef __cplusplus
}
#endif

#endif  // MORPHEUS_CCL_CSRMATRIX_HPP
