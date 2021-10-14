/**
 * Morpheus_Ccl_DenseMatrix.hpp
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

#ifndef MORPHEUS_CCL_DENSEMATRIX_HPP
#define MORPHEUS_CCL_DENSEMATRIX_HPP

#include <Morpheus_Ccl_Types.hpp>
#include <fwd/Morpheus_Ccl_Fwd_DenseMatrix.hpp>

#ifdef __cplusplus
extern "C" {
#endif

void morpheus_ccl_create_default_mat_dense_r64_i32_r_h(
    fcl_mat_dense_r64_i32_r_h** A);

void morpheus_ccl_create_mat_dense_r64_i32_r_h(fcl_mat_dense_r64_i32_r_h** A,
                                               fcl_i32_t num_rows,
                                               fcl_i32_t num_cols,
                                               fcl_r64_t val);

void morpheus_ccl_create_mat_dense_from_mat_dense_r64_i32_r_h(
    fcl_mat_dense_r64_i32_r_h* src, fcl_mat_dense_r64_i32_r_h** dst);

void morpheus_ccl_allocate_mat_dense_from_mat_dense_r64_i32_r_h(
    fcl_mat_dense_r64_i32_r_h* src, fcl_mat_dense_r64_i32_r_h* dst);

void morpheus_ccl_assign_mat_dense_r64_i32_r_h(fcl_mat_dense_r64_i32_r_h* A,
                                               fcl_i32_t num_rows,
                                               fcl_i32_t num_cols,
                                               fcl_r64_t val);

void morpheus_ccl_resize_mat_dense_r64_i32_r_h(fcl_mat_dense_r64_i32_r_h* A,
                                               fcl_i32_t num_rows,
                                               fcl_i32_t num_cols);

void morpheus_ccl_destroy_mat_dense_r64_i32_r_h(fcl_mat_dense_r64_i32_r_h** A);

// Base Routines
fcl_i32_t morpheus_ccl_nrows_mat_dense_r64_i32_r_h(
    fcl_mat_dense_r64_i32_r_h* A);
fcl_i32_t morpheus_ccl_ncols_mat_dense_r64_i32_r_h(
    fcl_mat_dense_r64_i32_r_h* A);
fcl_i32_t morpheus_ccl_nnnz_mat_dense_r64_i32_r_h(fcl_mat_dense_r64_i32_r_h* A);

void morpheus_ccl_set_nrows_mat_dense_r64_i32_r_h(fcl_mat_dense_r64_i32_r_h* A,
                                                  fcl_i32_t nrows);
void morpheus_ccl_set_ncols_mat_dense_r64_i32_r_h(fcl_mat_dense_r64_i32_r_h* A,
                                                  fcl_i32_t ncols);
void morpheus_ccl_set_nnnz_mat_dense_r64_i32_r_h(fcl_mat_dense_r64_i32_r_h* A,
                                                 fcl_i32_t nnnz);

// Format Specific Routines
fcl_r64_t* morpheus_ccl_data_mat_dense_r64_i32_r_h(
    fcl_mat_dense_r64_i32_r_h* A);

fcl_r64_t morpheus_ccl_values_at_mat_dense_r64_i32_r_h(
    fcl_mat_dense_r64_i32_r_h* A, fcl_i32_t i, fcl_i32_t j);

void morpheus_ccl_set_values_at_mat_dense_r64_i32_r_h(
    fcl_mat_dense_r64_i32_r_h* A, fcl_i32_t i, fcl_i32_t j, fcl_i32_t val);

#ifdef __cplusplus
}
#endif

#endif  // MORPHEUS_CCL_DENSEMATRIX_HPP