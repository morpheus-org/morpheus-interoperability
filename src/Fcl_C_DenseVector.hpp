/**
 * Fcl_C_DenseVector.hpp
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

#ifndef FCL_C_DENSEVECTOR_HPP
#define FCL_C_DENSEVECTOR_HPP

#include "Fcl_C_Types.hpp"
#include "fwd/Fcl_Fwd_C_DenseVector.hpp"

#ifdef __cplusplus
extern "C" {
#endif

void c_morpheus_create_vec_dense_r64_i32_r_h(fcl_vec_dense_r64_i32_r_h** v,
                                             fcl_i32_t n, fcl_r64_t val);

void c_morpheus_create_vec_from_vec_dense_r64_i32_r_h(
    fcl_vec_dense_r64_i32_r_h* src, fcl_vec_dense_r64_i32_r_h** dst);

void c_morpheus_destroy_vec_dense_r64_i32_r_h(fcl_vec_dense_r64_i32_r_h** v);

fcl_r64_t c_morpheus_values_at_vec_dense_r64_i32_r_h(
    fcl_vec_dense_r64_i32_r_h* v, fcl_i32_t i);

void c_morpheus_set_values_at_vec_dense_r64_i32_r_h(
    fcl_vec_dense_r64_i32_r_h* v, fcl_i32_t i, fcl_i32_t val);

#ifdef __cplusplus
}
#endif

#endif  // FCL_C_DENSEVECTOR_HPP