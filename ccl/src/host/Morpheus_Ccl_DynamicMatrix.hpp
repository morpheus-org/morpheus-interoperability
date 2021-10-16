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

void morpheus_ccl_create_default_hmat_dyn(ccl_hmat_dyn** A);

void morpheus_ccl_create_hmat_dyn_from_hmat(void* src, ccl_formats_e index,
                                            ccl_hmat_dyn** dst);

void morpheus_ccl_assign_hmat_dyn_from_hmat(void* src, ccl_formats_e index,
                                            ccl_hmat_dyn* dst);

void morpheus_ccl_resize_hmat_dyn(ccl_hmat_dyn* A, const ccl_index_t num_rows,
                                  const ccl_index_t num_cols,
                                  const ccl_index_t num_nnz);

void morpheus_ccl_resize_diags_hmat_dyn(ccl_hmat_dyn* A,
                                        const ccl_index_t num_rows,
                                        const ccl_index_t num_cols,
                                        const ccl_index_t num_nnz,
                                        const ccl_index_t num_diags);

void morpheus_ccl_resize_aligned_hmat_dyn(ccl_hmat_dyn* A,
                                          const ccl_index_t num_rows,
                                          const ccl_index_t num_cols,
                                          const ccl_index_t num_nnz,
                                          const ccl_index_t num_diags,
                                          const ccl_index_t alignment);

void morpheus_ccl_allocate_hmat_dyn_from_hmat_dyn(ccl_hmat_dyn* src,
                                                  ccl_hmat_dyn* dst);

void morpheus_ccl_destroy_hmat_dyn(ccl_hmat_dyn** A);

// Base Routines
ccl_index_t morpheus_ccl_nrows_hmat_dyn(ccl_hmat_dyn* A);
ccl_index_t morpheus_ccl_ncols_hmat_dyn(ccl_hmat_dyn* A);
ccl_index_t morpheus_ccl_nnnz_hmat_dyn(ccl_hmat_dyn* A);

void morpheus_ccl_set_nrows_hmat_dyn(ccl_hmat_dyn* A, ccl_index_t nrows);
void morpheus_ccl_set_ncols_hmat_dyn(ccl_hmat_dyn* A, ccl_index_t ncols);
void morpheus_ccl_set_nnnz_hmat_dyn(ccl_hmat_dyn* A, ccl_index_t nnnz);

// Format Specific Routines
void morpheus_ccl_activate_hmat_dyn(ccl_hmat_dyn* A, const ccl_formats_e index);

void morpheus_ccl_activate_index_hmat_dyn(ccl_hmat_dyn* A, const int index);

int morpheus_ccl_active_index_hmat_dyn(ccl_hmat_dyn* A);

ccl_formats_e morpheus_ccl_active_enum_hmat_dyn(ccl_hmat_dyn* A);

ccl_formats_e morpheus_ccl_format_enum_hmat_dyn(ccl_hmat_dyn* A);

#ifdef __cplusplus
}
#endif

#endif  // MORPHEUS_CCL_DYNAMICMATRIX_HPP
