/**
 * Morpheus_Ccl_Multiply.cpp
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

#include <Morpheus_Ccl_Multiply.hpp>

void morpheus_ccl_multiply_mat_coo_vec_dense_vec_dense_r64_i32_r_h_serial(
    fcl_mat_coo_r64_i32_r_h* A, fcl_vec_dense_r64_i32_r_h* x,
    fcl_vec_dense_r64_i32_r_h* y) {
  Morpheus::multiply<ccl_host_t>(*A, *x, *y);
}

void morpheus_ccl_multiply_mat_csr_vec_dense_vec_dense_r64_i32_r_h_serial(
    fcl_mat_csr_r64_i32_r_h* A, fcl_vec_dense_r64_i32_r_h* x,
    fcl_vec_dense_r64_i32_r_h* y) {
  Morpheus::multiply<ccl_host_t>(*A, *x, *y);
}

void morpheus_ccl_multiply_mat_dia_vec_dense_vec_dense_r64_i32_r_h_serial(
    fcl_mat_dia_r64_i32_r_h* A, fcl_vec_dense_r64_i32_r_h* x,
    fcl_vec_dense_r64_i32_r_h* y) {
  Morpheus::multiply<ccl_host_t>(*A, *x, *y);
}

void morpheus_ccl_multiply_mat_dyn_vec_dense_vec_dense_r64_i32_r_h_serial(
    fcl_mat_dyn_r64_i32_r_h* A, fcl_vec_dense_r64_i32_r_h* x,
    fcl_vec_dense_r64_i32_r_h* y) {
  Morpheus::multiply<ccl_host_t>(*A, *x, *y);
}
