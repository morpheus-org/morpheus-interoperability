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

#ifndef MORPHEUS_CCL_PHOST_DYNAMICMATRIX_HPP
#define MORPHEUS_CCL_PHOST_DYNAMICMATRIX_HPP

#include <Morpheus_Ccl_Types.hpp>

#include <phost/fwd/Morpheus_Ccl_Fwd_CooMatrix.hpp>
#include <phost/fwd/Morpheus_Ccl_Fwd_CsrMatrix.hpp>
#include <phost/fwd/Morpheus_Ccl_Fwd_DiaMatrix.hpp>
#include <phost/fwd/Morpheus_Ccl_Fwd_DynamicMatrix.hpp>

#ifdef __cplusplus
extern "C" {
#endif

void ccl_phmat_dyn_create_default(ccl_phmat_dyn** A);

void ccl_phmat_dyn_create_from_phmat(void* src, ccl_formats_e index,
                                     ccl_phmat_dyn** dst);

void ccl_phmat_dyn_assign_from_phmat(void* src, ccl_formats_e index,
                                     ccl_phmat_dyn* dst);

void ccl_phmat_dyn_resize(ccl_phmat_dyn* A, const ccl_index_t num_rows,
                          const ccl_index_t num_cols,
                          const ccl_index_t num_nnz);

void ccl_phmat_dyn_resize_diags(ccl_phmat_dyn* A, const ccl_index_t num_rows,
                                const ccl_index_t num_cols,
                                const ccl_index_t num_nnz,
                                const ccl_index_t num_diags);

void ccl_phmat_dyn_resize_aligned(ccl_phmat_dyn* A, const ccl_index_t num_rows,
                                  const ccl_index_t num_cols,
                                  const ccl_index_t num_nnz,
                                  const ccl_index_t num_diags,
                                  const ccl_index_t alignment);

void ccl_phmat_dyn_allocate_from_phmat_dyn(ccl_phmat_dyn* src,
                                           ccl_phmat_dyn* dst);

void ccl_phmat_dyn_destroy(ccl_phmat_dyn** A);

// Base Routines
ccl_index_t ccl_phmat_dyn_nrows(ccl_phmat_dyn* A);
ccl_index_t ccl_phmat_dyn_ncols(ccl_phmat_dyn* A);
ccl_index_t ccl_phmat_dyn_nnnz(ccl_phmat_dyn* A);

void ccl_phmat_dyn_set_nrows(ccl_phmat_dyn* A, ccl_index_t nrows);
void ccl_phmat_dyn_set_ncols(ccl_phmat_dyn* A, ccl_index_t ncols);
void ccl_phmat_dyn_set_nnnz(ccl_phmat_dyn* A, ccl_index_t nnnz);

// Format Specific Routines
void ccl_phmat_dyn_activate(ccl_phmat_dyn* A, const ccl_formats_e index);

void ccl_phmat_dyn_activate_index(ccl_phmat_dyn* A, const int index);

int ccl_phmat_dyn_active_index(ccl_phmat_dyn* A);

ccl_formats_e ccl_phmat_dyn_active_enum(ccl_phmat_dyn* A);

ccl_formats_e ccl_phmat_dyn_format_enum(ccl_phmat_dyn* A);

// HostMirror Interface
void ccl_phmat_dyn_hostmirror_create_default(ccl_phmat_dyn_hostmirror** A);

void ccl_phmat_dyn_hostmirror_create_from_phmat(void* src, ccl_formats_e index,
                                                ccl_phmat_dyn_hostmirror** dst);

void ccl_phmat_dyn_hostmirror_assign_from_phmat(void* src, ccl_formats_e index,
                                                ccl_phmat_dyn_hostmirror* dst);

void ccl_phmat_dyn_hostmirror_resize(ccl_phmat_dyn_hostmirror* A,
                                     const ccl_index_t num_rows,
                                     const ccl_index_t num_cols,
                                     const ccl_index_t num_nnz);

void ccl_phmat_dyn_hostmirror_resize_diags(ccl_phmat_dyn_hostmirror* A,
                                           const ccl_index_t num_rows,
                                           const ccl_index_t num_cols,
                                           const ccl_index_t num_nnz,
                                           const ccl_index_t num_diags);

void ccl_phmat_dyn_hostmirror_resize_aligned(ccl_phmat_dyn_hostmirror* A,
                                             const ccl_index_t num_rows,
                                             const ccl_index_t num_cols,
                                             const ccl_index_t num_nnz,
                                             const ccl_index_t num_diags,
                                             const ccl_index_t alignment);

void ccl_phmat_dyn_hostmirror_allocate_from_phmat_dyn_hostmirror(
    ccl_phmat_dyn_hostmirror* src, ccl_phmat_dyn_hostmirror* dst);

void ccl_phmat_dyn_hostmirror_destroy(ccl_phmat_dyn_hostmirror** A);

// Base Routines
ccl_index_t ccl_phmat_dyn_hostmirror_nrows(ccl_phmat_dyn_hostmirror* A);
ccl_index_t ccl_phmat_dyn_hostmirror_ncols(ccl_phmat_dyn_hostmirror* A);
ccl_index_t ccl_phmat_dyn_hostmirror_nnnz(ccl_phmat_dyn_hostmirror* A);

void ccl_phmat_dyn_hostmirror_set_nrows(ccl_phmat_dyn_hostmirror* A,
                                        ccl_index_t nrows);
void ccl_phmat_dyn_hostmirror_set_ncols(ccl_phmat_dyn_hostmirror* A,
                                        ccl_index_t ncols);
void ccl_phmat_dyn_hostmirror_set_nnnz(ccl_phmat_dyn_hostmirror* A,
                                       ccl_index_t nnnz);

// Format Specific Routines
void ccl_phmat_dyn_hostmirror_activate(ccl_phmat_dyn_hostmirror* A,
                                       const ccl_formats_e index);

void ccl_phmat_dyn_hostmirror_activate_index(ccl_phmat_dyn_hostmirror* A,
                                             const int index);

int ccl_phmat_dyn_hostmirror_active_index(ccl_phmat_dyn_hostmirror* A);

ccl_formats_e ccl_phmat_dyn_hostmirror_active_enum(ccl_phmat_dyn_hostmirror* A);

ccl_formats_e ccl_phmat_dyn_hostmirror_format_enum(ccl_phmat_dyn_hostmirror* A);

#ifdef __cplusplus
}
#endif

#endif  // MORPHEUS_CCL_PHOST_DYNAMICMATRIX_HPP
