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

#ifndef MORPHEUS_CCL_HOST_DENSEMATRIX_HPP
#define MORPHEUS_CCL_HOST_DENSEMATRIX_HPP

#include <Morpheus_Ccl_Types.hpp>

#include <host/fwd/Morpheus_Ccl_Fwd_DenseMatrix.hpp>

#ifdef __cplusplus
extern "C" {
#endif

void ccl_hmat_dense_create_default(ccl_hmat_dense** A);

void ccl_hmat_dense_create(ccl_hmat_dense** A, ccl_index_t num_rows,
                           ccl_index_t num_cols, ccl_value_t val);

void ccl_hmat_dense_create_from_hmat_dense(ccl_hmat_dense* src,
                                           ccl_hmat_dense** dst);

void ccl_hmat_dense_allocate_from_hmat_dense(ccl_hmat_dense* src,
                                             ccl_hmat_dense* dst);

void ccl_hmat_dense_assign(ccl_hmat_dense* A, ccl_index_t num_rows,
                           ccl_index_t num_cols, ccl_value_t val);

void ccl_hmat_dense_resize(ccl_hmat_dense* A, ccl_index_t num_rows,
                           ccl_index_t num_cols);

void ccl_hmat_dense_destroy(ccl_hmat_dense** A);

// Base Routines
ccl_index_t ccl_hmat_dense_nrows(ccl_hmat_dense* A);
ccl_index_t ccl_hmat_dense_ncols(ccl_hmat_dense* A);
ccl_index_t ccl_hmat_dense_nnnz(ccl_hmat_dense* A);

void ccl_hmat_dense_set_nrows(ccl_hmat_dense* A, ccl_index_t nrows);
void ccl_hmat_dense_set_ncols(ccl_hmat_dense* A, ccl_index_t ncols);
void ccl_hmat_dense_set_nnnz(ccl_hmat_dense* A, ccl_index_t nnnz);

// Format Specific Routines
ccl_value_t* ccl_hmat_dense_data(ccl_hmat_dense* A);

ccl_value_t ccl_hmat_dense_values_at(ccl_hmat_dense* A, ccl_index_t i,
                                     ccl_index_t j);

void ccl_hmat_dense_set_values_at(ccl_hmat_dense* A, ccl_index_t i,
                                  ccl_index_t j, ccl_index_t val);

// HostMirror Interface
void ccl_hmat_dense_hostmirror_create_default(ccl_hmat_dense_hostmirror** A);

void ccl_hmat_dense_hostmirror_create(ccl_hmat_dense_hostmirror** A,
                                      ccl_index_t num_rows,
                                      ccl_index_t num_cols, ccl_value_t val);

void ccl_hmat_dense_hostmirror_create_from_hmat_dense_hostmirror(
    ccl_hmat_dense_hostmirror* src, ccl_hmat_dense_hostmirror** dst);

void ccl_hmat_dense_hostmirror_allocate_from_hmat_dense_hostmirror(
    ccl_hmat_dense_hostmirror* src, ccl_hmat_dense_hostmirror* dst);

void ccl_hmat_dense_hostmirror_assign(ccl_hmat_dense_hostmirror* A,
                                      ccl_index_t num_rows,
                                      ccl_index_t num_cols, ccl_value_t val);

void ccl_hmat_dense_hostmirror_resize(ccl_hmat_dense_hostmirror* A,
                                      ccl_index_t num_rows,
                                      ccl_index_t num_cols);

void ccl_hmat_dense_hostmirror_destroy(ccl_hmat_dense_hostmirror** A);

// Base Routines
ccl_index_t ccl_hmat_dense_hostmirror_nrows(ccl_hmat_dense_hostmirror* A);
ccl_index_t ccl_hmat_dense_hostmirror_ncols(ccl_hmat_dense_hostmirror* A);
ccl_index_t ccl_hmat_dense_hostmirror_nnnz(ccl_hmat_dense_hostmirror* A);

void ccl_hmat_dense_hostmirror_set_nrows(ccl_hmat_dense_hostmirror* A,
                                         ccl_index_t nrows);
void ccl_hmat_dense_hostmirror_set_ncols(ccl_hmat_dense_hostmirror* A,
                                         ccl_index_t ncols);
void ccl_hmat_dense_hostmirror_set_nnnz(ccl_hmat_dense_hostmirror* A,
                                        ccl_index_t nnnz);

// Format Specific Routines
ccl_value_t* ccl_hmat_dense_hostmirror_data(ccl_hmat_dense_hostmirror* A);

ccl_value_t ccl_hmat_dense_hostmirror_values_at(ccl_hmat_dense_hostmirror* A,
                                                ccl_index_t i, ccl_index_t j);

void ccl_hmat_dense_hostmirror_set_values_at(ccl_hmat_dense_hostmirror* A,
                                             ccl_index_t i, ccl_index_t j,
                                             ccl_index_t val);

#ifdef __cplusplus
}
#endif

#endif  // MORPHEUS_CCL_HOST_DENSEMATRIX_HPP
