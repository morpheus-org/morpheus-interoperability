/**
 * Morpheus_Ccl_DenseVector.hpp
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

#ifndef MORPHEUS_CCL_DENSEVECTOR_HPP
#define MORPHEUS_CCL_DENSEVECTOR_HPP

#include <Morpheus_Ccl_Types.hpp>
#include <fwd/Morpheus_Ccl_Fwd_DenseVector.hpp>

#ifdef __cplusplus
extern "C" {
#endif

void morpheus_ccl_create_default_hvec_dense(ccl_hvec_dense** v);

void morpheus_ccl_create_hvec_dense(ccl_hvec_dense** v, ccl_index_t n,
                                    ccl_value_t val);

void morpheus_ccl_create_hvec_dense_from_hvec_dense(ccl_hvec_dense* src,
                                                    ccl_hvec_dense** dst);

void morpheus_ccl_allocate_hvec_dense_from_hvec_dense(ccl_hvec_dense* src,
                                                      ccl_hvec_dense* dst);

void morpheus_ccl_assign_hvec_dense(ccl_hvec_dense* v, ccl_index_t n,
                                    ccl_value_t val);

// TODO: Assign Random
// void morpheus_ccl_assign_random_hvec_dense(
//     ccl_hvec_dense* v, ccl_value_t range_low, ccl_value_t
//     range_high);

void morpheus_ccl_resize_hvec_dense(ccl_hvec_dense* v, ccl_index_t n);

void morpheus_ccl_resize_fill_hvec_dense(ccl_hvec_dense* v, ccl_index_t n,
                                         ccl_value_t val);

void morpheus_ccl_destroy_hvec_dense(ccl_hvec_dense** v);

ccl_index_t morpheus_ccl_size_hvec_dense(ccl_hvec_dense* v);

ccl_value_t* morpheus_ccl_data_hvec_dense(ccl_hvec_dense* v);

ccl_value_t morpheus_ccl_values_at_hvec_dense(ccl_hvec_dense* v, ccl_index_t i);

void morpheus_ccl_set_values_at_hvec_dense(ccl_hvec_dense* v, ccl_index_t i,
                                           ccl_index_t val);

#ifdef __cplusplus
}
#endif

#endif  // MORPHEUS_CCL_DENSEVECTOR_HPP
