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

#include <host/fwd/Morpheus_Ccl_Fwd_CooMatrix.hpp>
#include <host/fwd/Morpheus_Ccl_Fwd_CsrMatrix.hpp>
#include <host/fwd/Morpheus_Ccl_Fwd_DiaMatrix.hpp>
#include <host/fwd/Morpheus_Ccl_Fwd_DynamicMatrix.hpp>

#ifdef __cplusplus
extern "C" {
#endif

void ccl_hmat_dyn_create_default(ccl_hmat_dyn** A);

void ccl_hmat_dyn_create_from_hmat(void* src, ccl_formats_e index,
                                   ccl_hmat_dyn** dst);

void ccl_hmat_dyn_assign_from_hmat(void* src, ccl_formats_e index,
                                   ccl_hmat_dyn* dst);

void ccl_hmat_dyn_resize(ccl_hmat_dyn* A, const ccl_index_t num_rows,
                         const ccl_index_t num_cols, const ccl_index_t num_nnz);

void ccl_hmat_dyn_resize_diags(ccl_hmat_dyn* A, const ccl_index_t num_rows,
                               const ccl_index_t num_cols,
                               const ccl_index_t num_nnz,
                               const ccl_index_t num_diags);

void ccl_hmat_dyn_resize_aligned(ccl_hmat_dyn* A, const ccl_index_t num_rows,
                                 const ccl_index_t num_cols,
                                 const ccl_index_t num_nnz,
                                 const ccl_index_t num_diags,
                                 const ccl_index_t alignment);

void ccl_hmat_dyn_allocate_from_hmat_dyn(ccl_hmat_dyn* src, ccl_hmat_dyn* dst);

void ccl_hmat_dyn_destroy(ccl_hmat_dyn** A);

// Base Routines
ccl_index_t ccl_hmat_dyn_nrows(ccl_hmat_dyn* A);
ccl_index_t ccl_hmat_dyn_ncols(ccl_hmat_dyn* A);
ccl_index_t ccl_hmat_dyn_nnnz(ccl_hmat_dyn* A);

void ccl_hmat_dyn_set_nrows(ccl_hmat_dyn* A, ccl_index_t nrows);
void ccl_hmat_dyn_set_ncols(ccl_hmat_dyn* A, ccl_index_t ncols);
void ccl_hmat_dyn_set_nnnz(ccl_hmat_dyn* A, ccl_index_t nnnz);

// Format Specific Routines
void ccl_hmat_dyn_activate(ccl_hmat_dyn* A, const ccl_formats_e index);

void ccl_hmat_dyn_activate_index(ccl_hmat_dyn* A, const int index);

int ccl_hmat_dyn_active_index(ccl_hmat_dyn* A);

ccl_formats_e ccl_hmat_dyn_active_enum(ccl_hmat_dyn* A);

ccl_formats_e ccl_hmat_dyn_format_enum(ccl_hmat_dyn* A);

#ifdef __cplusplus
}
#endif

#endif  // MORPHEUS_CCL_DYNAMICMATRIX_HPP
