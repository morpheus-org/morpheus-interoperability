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

#ifndef MORPHEUS_CCL_PHOST_DENSEMATRIX_HPP
#define MORPHEUS_CCL_PHOST_DENSEMATRIX_HPP

#include <Morpheus_Ccl_Types.hpp>

#include <phost/fwd/Morpheus_Ccl_Fwd_DenseMatrix.hpp>

#ifdef __cplusplus
extern "C" {
#endif

void ccl_phmat_dense_create_default(ccl_phmat_dense** A);

void ccl_phmat_dense_create(ccl_phmat_dense** A, ccl_index_t num_rows,
                            ccl_index_t num_cols, ccl_value_t val);

void ccl_phmat_dense_create_from_phmat_dense(ccl_phmat_dense* src,
                                             ccl_phmat_dense** dst);

void ccl_phmat_dense_allocate_from_phmat_dense(ccl_phmat_dense* src,
                                               ccl_phmat_dense* dst);

void ccl_phmat_dense_assign(ccl_phmat_dense* A, ccl_index_t num_rows,
                            ccl_index_t num_cols, ccl_value_t val);

void ccl_phmat_dense_resize(ccl_phmat_dense* A, ccl_index_t num_rows,
                            ccl_index_t num_cols);

void ccl_phmat_dense_destroy(ccl_phmat_dense** A);

// Base Routines
ccl_index_t ccl_phmat_dense_nrows(ccl_phmat_dense* A);
ccl_index_t ccl_phmat_dense_ncols(ccl_phmat_dense* A);
ccl_index_t ccl_phmat_dense_nnnz(ccl_phmat_dense* A);

void ccl_phmat_dense_set_nrows(ccl_phmat_dense* A, ccl_index_t nrows);
void ccl_phmat_dense_set_ncols(ccl_phmat_dense* A, ccl_index_t ncols);
void ccl_phmat_dense_set_nnnz(ccl_phmat_dense* A, ccl_index_t nnnz);

// Format Specific Routines
ccl_value_t* ccl_phmat_dense_data(ccl_phmat_dense* A);

ccl_value_t ccl_phmat_dense_values_at(ccl_phmat_dense* A, ccl_index_t i,
                                      ccl_index_t j);

void ccl_phmat_dense_set_values_at(ccl_phmat_dense* A, ccl_index_t i,
                                   ccl_index_t j, ccl_index_t val);

#ifdef __cplusplus
}
#endif

#endif  // MORPHEUS_CCL_PHOST_DENSEMATRIX_HPP
