/**
 * Morpheus_Ccl_CooMatrix.hpp
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

#ifndef MORPHEUS_CCL_COOMATRIX_HPP
#define MORPHEUS_CCL_COOMATRIX_HPP

#include <Morpheus_Ccl_Types.hpp>
#include <fwd/Morpheus_Ccl_Fwd_CooMatrix.hpp>
#include <fwd/Morpheus_Ccl_Fwd_DynamicMatrix.hpp>
#include <fwd/Morpheus_Ccl_Fwd_DenseVector.hpp>

#ifdef __cplusplus
extern "C" {
#endif

void c_morpheus_create_default_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h** A);

void c_morpheus_create_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h** A,
                                           fcl_i32_t nrows, fcl_i32_t ncols,
                                           fcl_i32_t nnnz);

void c_morpheus_create_mat_coo_from_mat_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* src, fcl_mat_coo_r64_i32_r_h** dst);

void c_morpheus_create_mat_coo_from_mat_dyn_r64_i32_r_h(
    fcl_mat_dyn_r64_i32_r_h* src, fcl_mat_coo_r64_i32_r_h** dst);

void c_morpheus_resize_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A,
                                           const fcl_i32_t num_rows,
                                           const fcl_i32_t num_cols,
                                           const fcl_i32_t num_nnz);

void c_morpheus_allocate_mat_coo_from_mat_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* src, fcl_mat_coo_r64_i32_r_h* dst);

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
fcl_i32_t c_morpheus_row_indices_at_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A,
                                                    fcl_i32_t i);
fcl_i32_t c_morpheus_column_indices_at_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* A, fcl_i32_t i);
fcl_r64_t c_morpheus_values_at_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A,
                                               fcl_i32_t i);

fcl_vec_dense_i32_i32_r_h* c_morpheus_row_indices_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* A);
fcl_vec_dense_i32_i32_r_h* c_morpheus_column_indices_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* A);
fcl_vec_dense_r64_i32_r_h* c_morpheus_values_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* A);

void c_morpheus_set_row_indices_at_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A,
                                                   fcl_i32_t i, fcl_i32_t val);
void c_morpheus_set_column_indices_at_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* A, fcl_i32_t i, fcl_i32_t val);
void c_morpheus_set_values_at_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A,
                                              fcl_i32_t i, fcl_r64_t val);

void c_morpheus_sort_by_row_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A);
void c_morpheus_sort_by_row_and_column_mat_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* A);
fcl_bool_t c_morpheus_is_sorted_by_row_mat_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* A);
fcl_bool_t c_morpheus_is_sorted_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A);

// Other Routines
fcl_formats_e c_morpheus_format_enum_mat_coo_r64_i32_r_h(
    fcl_mat_coo_r64_i32_r_h* A);
int c_morpheus_format_index_mat_coo_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h* A);

#ifdef __cplusplus
}
#endif

#endif  // MORPHEUS_CCL_COOMATRIX_HPP