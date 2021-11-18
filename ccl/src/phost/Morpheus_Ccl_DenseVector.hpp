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

#ifndef MORPHEUS_CCL_PHOST_DENSEVECTOR_HPP
#define MORPHEUS_CCL_PHOST_DENSEVECTOR_HPP

#include <Morpheus_Ccl_Types.hpp>

#include <phost/fwd/Morpheus_Ccl_Fwd_DenseVector.hpp>

#ifdef __cplusplus
extern "C" {
#endif

void ccl_phvec_dense_v_create_default(ccl_phvec_dense_v** v);

void ccl_phvec_dense_v_create(ccl_phvec_dense_v** v, ccl_index_t n,
                              ccl_value_t val);

void ccl_phvec_dense_v_create_from_phvec_dense_v(ccl_phvec_dense_v* src,
                                                 ccl_phvec_dense_v** dst);

void ccl_phvec_dense_v_allocate_from_phvec_dense_v(ccl_phvec_dense_v* src,
                                                   ccl_phvec_dense_v* dst);

void ccl_phvec_dense_v_assign(ccl_phvec_dense_v* v, ccl_index_t n,
                              ccl_value_t val);

// TODO: Assign Random
// void ccl_phvec_dense_v_assign_random(
//     ccl_phvec_dense_v* v, ccl_value_t range_low, ccl_value_t
//     range_high);

void ccl_phvec_dense_v_resize(ccl_phvec_dense_v* v, ccl_index_t n);

void ccl_phvec_dense_v_resize_fill(ccl_phvec_dense_v* v, ccl_index_t n,
                                   ccl_value_t val);

void ccl_phvec_dense_v_destroy(ccl_phvec_dense_v** v);

ccl_index_t ccl_phvec_dense_v_size(ccl_phvec_dense_v* v);

ccl_value_t* ccl_phvec_dense_v_data(ccl_phvec_dense_v* v);

ccl_value_t ccl_phvec_dense_v_values_at(ccl_phvec_dense_v* v, ccl_index_t i);

void ccl_phvec_dense_v_set_values_at(ccl_phvec_dense_v* v, ccl_index_t i,
                                     ccl_value_t val);

void ccl_phvec_dense_i_create_default(ccl_phvec_dense_i** v);

void ccl_phvec_dense_i_create(ccl_phvec_dense_i** v, ccl_index_t n,
                              ccl_index_t val);

void ccl_phvec_dense_i_create_from_phvec_dense_i(ccl_phvec_dense_i* src,
                                                 ccl_phvec_dense_i** dst);

void ccl_phvec_dense_i_allocate_from_phvec_dense_i(ccl_phvec_dense_i* src,
                                                   ccl_phvec_dense_i* dst);

void ccl_phvec_dense_i_assign(ccl_phvec_dense_i* v, ccl_index_t n,
                              ccl_index_t val);

// TODO: Assign Random
// void ccl_phvec_dense_i_assign_random(
//     ccl_phvec_dense_i* v, ccl_index_t range_low, ccl_index_t
//     range_high);

void ccl_phvec_dense_i_resize(ccl_phvec_dense_i* v, ccl_index_t n);

void ccl_phvec_dense_i_resize_fill(ccl_phvec_dense_i* v, ccl_index_t n,
                                   ccl_index_t val);

void ccl_phvec_dense_i_destroy(ccl_phvec_dense_i** v);

ccl_index_t ccl_phvec_dense_i_size(ccl_phvec_dense_i* v);

ccl_index_t* ccl_phvec_dense_i_data(ccl_phvec_dense_i* v);

ccl_index_t ccl_phvec_dense_i_values_at(ccl_phvec_dense_i* v, ccl_index_t i);

void ccl_phvec_dense_i_set_values_at(ccl_phvec_dense_i* v, ccl_index_t i,
                                     ccl_index_t val);

void ccl_phvec_dense_v_hostmirror_create_default(
    ccl_phvec_dense_v_hostmirror** v);

void ccl_phvec_dense_v_hostmirror_create(ccl_phvec_dense_v_hostmirror** v,
                                         ccl_index_t n, ccl_value_t val);

void ccl_phvec_dense_v_hostmirror_create_from_phvec_dense_v_hostmirror(
    ccl_phvec_dense_v_hostmirror* src, ccl_phvec_dense_v_hostmirror** dst);

void ccl_phvec_dense_v_hostmirror_allocate_from_phvec_dense_v_hostmirror(
    ccl_phvec_dense_v_hostmirror* src, ccl_phvec_dense_v_hostmirror* dst);

void ccl_phvec_dense_v_hostmirror_assign(ccl_phvec_dense_v_hostmirror* v,
                                         ccl_index_t n, ccl_value_t val);

// TODO: Assign Random
// void ccl_phvec_dense_v_hostmirror_assign_random(
//     ccl_phvec_dense_v_hostmirror* v, ccl_value_t range_low, ccl_value_t
//     range_high);

void ccl_phvec_dense_v_hostmirror_resize(ccl_phvec_dense_v_hostmirror* v,
                                         ccl_index_t n);

void ccl_phvec_dense_v_hostmirror_resize_fill(ccl_phvec_dense_v_hostmirror* v,
                                              ccl_index_t n, ccl_value_t val);

void ccl_phvec_dense_v_hostmirror_destroy(ccl_phvec_dense_v_hostmirror** v);

ccl_index_t ccl_phvec_dense_v_hostmirror_size(ccl_phvec_dense_v_hostmirror* v);

ccl_value_t* ccl_phvec_dense_v_hostmirror_data(ccl_phvec_dense_v_hostmirror* v);

ccl_value_t ccl_phvec_dense_v_hostmirror_values_at(
    ccl_phvec_dense_v_hostmirror* v, ccl_index_t i);

void ccl_phvec_dense_v_hostmirror_set_values_at(ccl_phvec_dense_v_hostmirror* v,
                                                ccl_index_t i, ccl_value_t val);

void ccl_phvec_dense_i_hostmirror_create_default(
    ccl_phvec_dense_i_hostmirror** v);

void ccl_phvec_dense_i_hostmirror_create(ccl_phvec_dense_i_hostmirror** v,
                                         ccl_index_t n, ccl_index_t val);

void ccl_phvec_dense_i_hostmirror_create_from_phvec_dense_i_hostmirror(
    ccl_phvec_dense_i_hostmirror* src, ccl_phvec_dense_i_hostmirror** dst);

void ccl_phvec_dense_i_hostmirror_allocate_from_phvec_dense_i_hostmirror(
    ccl_phvec_dense_i_hostmirror* src, ccl_phvec_dense_i_hostmirror* dst);

void ccl_phvec_dense_i_hostmirror_assign(ccl_phvec_dense_i_hostmirror* v,
                                         ccl_index_t n, ccl_index_t val);

// TODO: Assign Random
// void ccl_phvec_dense_i_hostmirror_assign_random(
//     ccl_phvec_dense_i_hostmirror* v, ccl_index_t range_low, ccl_index_t
//     range_high);

void ccl_phvec_dense_i_hostmirror_resize(ccl_phvec_dense_i_hostmirror* v,
                                         ccl_index_t n);

void ccl_phvec_dense_i_hostmirror_resize_fill(ccl_phvec_dense_i_hostmirror* v,
                                              ccl_index_t n, ccl_index_t val);

void ccl_phvec_dense_i_hostmirror_destroy(ccl_phvec_dense_i_hostmirror** v);

ccl_index_t ccl_phvec_dense_i_hostmirror_size(ccl_phvec_dense_i_hostmirror* v);

ccl_index_t* ccl_phvec_dense_i_hostmirror_data(ccl_phvec_dense_i_hostmirror* v);

ccl_index_t ccl_phvec_dense_i_hostmirror_values_at(
    ccl_phvec_dense_i_hostmirror* v, ccl_index_t i);

void ccl_phvec_dense_i_hostmirror_set_values_at(ccl_phvec_dense_i_hostmirror* v,
                                                ccl_index_t i, ccl_index_t val);

#ifdef __cplusplus
}
#endif

#endif  // MORPHEUS_CCL_PHOST_DENSEVECTOR_HPP
