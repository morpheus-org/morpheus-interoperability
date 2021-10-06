/**
 * Fcl_C_WAXPBY.cpp
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

#include "Fcl_C_WAXPBY.hpp"

void c_morpheus_waxpby_vec_dense_vec_dense_r64_i32_r_h_serial(
    fcl_i32_t n, fcl_r64_t alpha, const fcl_vec_dense_r64_i32_r_h* x,
    fcl_r64_t beta, const fcl_vec_dense_r64_i32_r_h* y,
    fcl_vec_dense_r64_i32_r_h* w) {
  Morpheus::waxpby<fcl_serial_t>(n, alpha, *x, beta, *y, *w);
}
