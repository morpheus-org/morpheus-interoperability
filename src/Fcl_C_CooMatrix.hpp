/**
 * Fcl_C_CooMatrix.hpp
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

#ifndef FCL_C_COOMATRIX_HPP
#define FCL_C_COOMATRIX_HPP

#include "Fcl_C_Types.hpp"
#include "fwd/Fcl_Fwd_C_CooMatrix.hpp"
#include "fwd/Fcl_Fwd_C_DynamicMatrix.hpp"

#ifdef __cplusplus
extern "C" {
#endif

void c_morpheus_create_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h** A,
                                           fcl_i32_t** A_row_indices,
                                           fcl_i32_t** A_column_indices,
                                           fcl_r64_t** A_values,
                                           fcl_i32_t nrows, fcl_i32_t ncols,
                                           fcl_i32_t nnnz);

void c_morpheus_create_mat_coo_from_mat_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* src, fcl_mat_coo_r64_i32_r_h** dst,
    fcl_i32_t** dst_row_indices, fcl_i32_t** dst_column_indices,
    fcl_r64_t** dst_values);

void c_morpheus_create_mat_coo_from_mat_dyn_r64_i32_r_h(
    fcl_mat_dyn_r64_i32_r_h* src, fcl_mat_coo_r64_i32_r_h** dst,
    fcl_i32_t** dst_row_indices, fcl_i32_t** dst_column_indices,
    fcl_r64_t** dst_values);

void c_morpheus_resize_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A,
                                           fcl_i32_t** A_row_indices,
                                           fcl_i32_t** A_column_indices,
                                           fcl_r64_t** A_values,
                                           const fcl_i32_t num_rows,
                                           const fcl_i32_t num_cols,
                                           const fcl_i32_t num_nnz);

void c_morpheus_allocate_mat_coo_from_mat_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* src, fcl_mat_coo_r64_i32_r_h* dst,
    fcl_i32_t** dst_row_indices, fcl_i32_t** dst_column_indices,
    fcl_r64_t** dst_values);

void c_morpheus_destroy_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h** A);

// Base Routines
fcl_i32_t c_morpheus_nrows_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A);
fcl_i32_t c_morpheus_ncols_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A);
fcl_i32_t c_morpheus_nnnz_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A);

void c_morpheus_set_nrows_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A,
                                              fcl_i32_t nrows);
void c_morpheus_set_ncols_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A,
                                              fcl_i32_t ncols);
void c_morpheus_set_nnnz_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A,
                                             fcl_i32_t nnnz);
// Format Specific Routines
void c_morpheus_sort_by_row_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A);
void c_morpheus_sort_by_row_and_column_mat_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* A);
fcl_bool_t c_morpheus_is_sorted_by_row_mat_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* A);
fcl_bool_t c_morpheus_is_sorted_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A);

#ifdef __cplusplus
}
#endif

#endif  // FCL_C_COOMATRIX_HPP