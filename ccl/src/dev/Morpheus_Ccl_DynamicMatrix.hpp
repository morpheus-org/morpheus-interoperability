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

#ifndef MORPHEUS_CCL_DEV_DYNAMICMATRIX_HPP
#define MORPHEUS_CCL_DEV_DYNAMICMATRIX_HPP

#include <Morpheus_Ccl_Types.hpp>

#include <fwd/Morpheus_Ccl_Fwd_CooMatrix.hpp>
#include <fwd/Morpheus_Ccl_Fwd_CsrMatrix.hpp>
#include <fwd/Morpheus_Ccl_Fwd_DiaMatrix.hpp>
#include <fwd/Morpheus_Ccl_Fwd_DynamicMatrix.hpp>

#ifdef __cplusplus
extern "C" {
#endif

void ccl_dmat_dyn_create_default(ccl_dmat_dyn** A);

void ccl_dmat_dyn_create_from_dmat(void* src, ccl_formats_e index,
                                   ccl_dmat_dyn** dst);

void ccl_dmat_dyn_assign_from_dmat(void* src, ccl_formats_e index,
                                   ccl_dmat_dyn* dst);

void ccl_dmat_dyn_resize(ccl_dmat_dyn* A, const ccl_index_t num_rows,
                         const ccl_index_t num_cols, const ccl_index_t num_nnz);

void ccl_dmat_dyn_resize_diags(ccl_dmat_dyn* A, const ccl_index_t num_rows,
                               const ccl_index_t num_cols,
                               const ccl_index_t num_nnz,
                               const ccl_index_t num_diags);

void ccl_dmat_dyn_resize_aligned(ccl_dmat_dyn* A, const ccl_index_t num_rows,
                                 const ccl_index_t num_cols,
                                 const ccl_index_t num_nnz,
                                 const ccl_index_t num_diags,
                                 const ccl_index_t alignment);

void ccl_dmat_dyn_allocate_from_dmat_dyn(ccl_dmat_dyn* src, ccl_dmat_dyn* dst);

void ccl_dmat_dyn_destroy(ccl_dmat_dyn** A);

// Base Routines
ccl_index_t ccl_dmat_dyn_nrows(ccl_dmat_dyn* A);
ccl_index_t ccl_dmat_dyn_ncols(ccl_dmat_dyn* A);
ccl_index_t ccl_dmat_dyn_nnnz(ccl_dmat_dyn* A);

void ccl_dmat_dyn_set_nrows(ccl_dmat_dyn* A, ccl_index_t nrows);
void ccl_dmat_dyn_set_ncols(ccl_dmat_dyn* A, ccl_index_t ncols);
void ccl_dmat_dyn_set_nnnz(ccl_dmat_dyn* A, ccl_index_t nnnz);

// Format Specific Routines
void ccl_dmat_dyn_activate(ccl_dmat_dyn* A, const ccl_formats_e index);

void ccl_dmat_dyn_activate_index(ccl_dmat_dyn* A, const int index);

int ccl_dmat_dyn_active_index(ccl_dmat_dyn* A);

ccl_formats_e ccl_dmat_dyn_active_enum(ccl_dmat_dyn* A);

ccl_formats_e ccl_dmat_dyn_format_enum(ccl_dmat_dyn* A);

// HostMirror Interface
void ccl_dmat_dyn_hostmirror_create_default(ccl_dmat_dyn_hostmirror** A);

void ccl_dmat_dyn_hostmirror_create_from_dmat(void* src, ccl_formats_e index,
                                              ccl_dmat_dyn_hostmirror** dst);

void ccl_dmat_dyn_hostmirror_assign_from_dmat(void* src, ccl_formats_e index,
                                              ccl_dmat_dyn_hostmirror* dst);

void ccl_dmat_dyn_hostmirror_resize(ccl_dmat_dyn_hostmirror* A,
                                    const ccl_index_t num_rows,
                                    const ccl_index_t num_cols,
                                    const ccl_index_t num_nnz);

void ccl_dmat_dyn_hostmirror_resize_diags(ccl_dmat_dyn_hostmirror* A,
                                          const ccl_index_t num_rows,
                                          const ccl_index_t num_cols,
                                          const ccl_index_t num_nnz,
                                          const ccl_index_t num_diags);

void ccl_dmat_dyn_hostmirror_resize_aligned(ccl_dmat_dyn_hostmirror* A,
                                            const ccl_index_t num_rows,
                                            const ccl_index_t num_cols,
                                            const ccl_index_t num_nnz,
                                            const ccl_index_t num_diags,
                                            const ccl_index_t alignment);

void ccl_dmat_dyn_hostmirror_allocate_from_dmat_dyn_hostmirror(
    ccl_dmat_dyn_hostmirror* src, ccl_dmat_dyn_hostmirror* dst);

void ccl_dmat_dyn_hostmirror_destroy(ccl_dmat_dyn_hostmirror** A);

// Base Routines
ccl_index_t ccl_dmat_dyn_hostmirror_nrows(ccl_dmat_dyn_hostmirror* A);
ccl_index_t ccl_dmat_dyn_hostmirror_ncols(ccl_dmat_dyn_hostmirror* A);
ccl_index_t ccl_dmat_dyn_hostmirror_nnnz(ccl_dmat_dyn_hostmirror* A);

void ccl_dmat_dyn_hostmirror_set_nrows(ccl_dmat_dyn_hostmirror* A,
                                       ccl_index_t nrows);
void ccl_dmat_dyn_hostmirror_set_ncols(ccl_dmat_dyn_hostmirror* A,
                                       ccl_index_t ncols);
void ccl_dmat_dyn_hostmirror_set_nnnz(ccl_dmat_dyn_hostmirror* A,
                                      ccl_index_t nnnz);

// Format Specific Routines
void ccl_dmat_dyn_hostmirror_activate(ccl_dmat_dyn_hostmirror* A,
                                      const ccl_formats_e index);

void ccl_dmat_dyn_hostmirror_activate_index(ccl_dmat_dyn_hostmirror* A,
                                            const int index);

int ccl_dmat_dyn_hostmirror_active_index(ccl_dmat_dyn_hostmirror* A);

ccl_formats_e ccl_dmat_dyn_hostmirror_active_enum(ccl_dmat_dyn_hostmirror* A);

ccl_formats_e ccl_dmat_dyn_hostmirror_format_enum(ccl_dmat_dyn_hostmirror* A);

#ifdef __cplusplus
}
#endif

#endif  // MORPHEUS_CCL_DEV_DYNAMICMATRIX_HPP
