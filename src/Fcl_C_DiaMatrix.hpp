/**
 * Fcl_C_DiaMatrix.hpp
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

#ifndef FCL_C_DIAMATRIX_HPP
#define FCL_C_DIAMATRIX_HPP

#include "Fcl_C_Types.hpp"
#include "fwd/Fcl_Fwd_C_DiaMatrix.hpp"
#include "fwd/Fcl_Fwd_C_DynamicMatrix.hpp"

#ifdef __cplusplus
extern "C" {
#endif

void c_morpheus_create_default_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h** A);

void c_morpheus_create_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h** A,
                                           fcl_i32_t nrows, fcl_i32_t ncols,
                                           fcl_i32_t nnnz, fcl_i32_t ndiags);

void c_morpheus_create_aligned_mat_dia_r64_i32_r_h(
    fcl_mat_dia_r64_i32_r_h** A, fcl_i32_t nrows, fcl_i32_t ncols,
    fcl_i32_t nnnz, fcl_i32_t ndiags, fcl_i32_t alginment);

void c_morpheus_create_mat_dia_from_mat_dia_r64_i32_r_h(
    fcl_mat_dia_r64_i32_r_h* src, fcl_mat_dia_r64_i32_r_h** dst);

void c_morpheus_create_mat_dia_from_mat_dyn_r64_i32_r_h(
    fcl_mat_dyn_r64_i32_r_h* src, fcl_mat_dia_r64_i32_r_h** dst);

void c_morpheus_resize_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A,
                                           const fcl_i32_t num_rows,
                                           const fcl_i32_t num_cols,
                                           const fcl_i32_t num_nnz,
                                           const fcl_i32_t num_diagonals);

void c_morpheus_resize_aligned_mat_dia_r64_i32_r_h(
    fcl_mat_dia_r64_i32_r_h* A, const fcl_i32_t num_rows,
    const fcl_i32_t num_cols, const fcl_i32_t num_nnz,
    const fcl_i32_t num_diagonals, const fcl_i32_t alginment);

void c_morpheus_allocate_mat_dia_from_mat_dia_r64_i32_r_h(
    fcl_mat_dia_r64_i32_r_h* src, fcl_mat_dia_r64_i32_r_h* dst);

void c_morpheus_destroy_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h** A);

// Base Routines
fcl_i32_t c_morpheus_nrows_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A);
fcl_i32_t c_morpheus_ncols_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A);
fcl_i32_t c_morpheus_nnnz_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A);

void c_morpheus_set_nrows_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A,
                                              fcl_i32_t nrows);
void c_morpheus_set_ncols_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A,
                                              fcl_i32_t ncols);
void c_morpheus_set_nnnz_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A,
                                             fcl_i32_t nnnz);

// Format Specific Routines
fcl_i32_t c_morpheus_ndiags_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A);
fcl_i32_t c_morpheus_alignment_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A);

void c_morpheus_set_ndiags_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A,
                                               fcl_i32_t ndiags);
void c_morpheus_set_alignment_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A,
                                                  fcl_i32_t alignment);

fcl_i32_t c_morpheus_diagonal_offests_at_dia_r64_i32_r_h(
    fcl_mat_dia_r64_i32_r_h* A, fcl_i32_t i);
fcl_r64_t c_morpheus_values_at_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A,
                                               fcl_i32_t i, fcl_i32_t j);

void c_morpheus_set_diagonal_offests_at_dia_r64_i32_r_h(
    fcl_mat_dia_r64_i32_r_h* A, fcl_i32_t i, fcl_i32_t val);
void c_morpheus_set_values_at_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A,
                                              fcl_i32_t i, fcl_i32_t j,
                                              fcl_r64_t val);

fcl_bool_t c_morpheus_exceeds_tolerance_mat_dia_r64_i32_r_h(
    fcl_mat_dia_r64_i32_r_h* A, const fcl_i32_t num_rows,
    const fcl_i32_t num_entries, const fcl_i32_t num_diagonals);

// Other Routines
fcl_formats_e c_morpheus_format_enum_mat_dia_r64_i32_r_h(
    fcl_mat_dia_r64_i32_r_h* A);
int c_morpheus_format_index_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A);

#ifdef __cplusplus
}
#endif

#endif  // FCL_C_DIAMATRIX_HPP