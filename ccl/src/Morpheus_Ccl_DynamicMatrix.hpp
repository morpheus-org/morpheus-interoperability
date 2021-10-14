/**
 * Morpheus_Ccl_DynamicMatrix.hpp
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

#ifndef MORPHEUS_CCL_DYNAMICMATRIX_HPP
#define MORPHEUS_CCL_DYNAMICMATRIX_HPP

#include <Morpheus_Ccl_Types.hpp>
#include <fwd/Morpheus_Ccl_Fwd_CooMatrix.hpp>
#include <fwd/Morpheus_Ccl_Fwd_CsrMatrix.hpp>
#include <fwd/Morpheus_Ccl_Fwd_DiaMatrix.hpp>
#include <fwd/Morpheus_Ccl_Fwd_DynamicMatrix.hpp>

#ifdef __cplusplus
extern "C" {
#endif

void morpheus_ccl_create_default_mat_dyn_r64_i32_r_h(
    fcl_mat_dyn_r64_i32_r_h** A);

void morpheus_ccl_create_mat_dyn_from_mat_r64_i32_r_h(
    void* src, fcl_formats_e index, fcl_mat_dyn_r64_i32_r_h** dst);

void morpheus_ccl_assign_mat_dyn_from_mat_r64_i32_r_h(
    void* src, fcl_formats_e index, fcl_mat_dyn_r64_i32_r_h* dst);

void morpheus_ccl_resize_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A,
                                             const fcl_i32_t num_rows,
                                             const fcl_i32_t num_cols,
                                             const fcl_i32_t num_nnz);

void morpheus_ccl_resize_diags_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A,
                                                   const fcl_i32_t num_rows,
                                                   const fcl_i32_t num_cols,
                                                   const fcl_i32_t num_nnz,
                                                   const fcl_i32_t num_diags);

void morpheus_ccl_resize_aligned_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A,
                                                     const fcl_i32_t num_rows,
                                                     const fcl_i32_t num_cols,
                                                     const fcl_i32_t num_nnz,
                                                     const fcl_i32_t num_diags,
                                                     const fcl_i32_t alignment);

void morpheus_ccl_allocate_mat_dyn_from_mat_dyn_r64_i32_r_h(
    fcl_mat_dyn_r64_i32_r_h* src, fcl_mat_dyn_r64_i32_r_h* dst);

void morpheus_ccl_destroy_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h** A);

// Base Routines
fcl_i32_t morpheus_ccl_nrows_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A);
fcl_i32_t morpheus_ccl_ncols_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A);
fcl_i32_t morpheus_ccl_nnnz_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A);

void morpheus_ccl_set_nrows_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A,
                                                fcl_i32_t nrows);
void morpheus_ccl_set_ncols_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A,
                                                fcl_i32_t ncols);
void morpheus_ccl_set_nnnz_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A,
                                               fcl_i32_t nnnz);

// Format Specific Routines
void morpheus_ccl_activate_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A,
                                               const fcl_formats_e index);

void morpheus_ccl_activate_index_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A,
                                                     const int index);

int morpheus_ccl_active_index_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A);

fcl_formats_e morpheus_ccl_active_enum_mat_dyn_r64_i32_r_h(
    fcl_mat_dyn_r64_i32_r_h* A);

fcl_formats_e morpheus_ccl_format_enum_mat_dyn_r64_i32_r_h(
    fcl_mat_dyn_r64_i32_r_h* A);

#ifdef __cplusplus
}
#endif

#endif  // MORPHEUS_CCL_DYNAMICMATRIX_HPP