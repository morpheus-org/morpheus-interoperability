/**
 * Morpheus_Ccl_Convert.cpp
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

#include <Morpheus_Ccl_Convert.hpp>

// coo -> coo
void morpheus_ccl_convert_mat_coo_to_mat_coo_r64_i32_r_h_serial(
    const fcl_mat_coo_r64_i32_r_h* src, fcl_mat_coo_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}

// csr -> csr
void morpheus_ccl_convert_mat_csr_to_mat_csr_r64_i32_r_h_serial(
    const fcl_mat_csr_r64_i32_r_h* src, fcl_mat_csr_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}
// csr -> coo
void morpheus_ccl_convert_mat_csr_to_mat_coo_r64_i32_r_h_serial(
    const fcl_mat_csr_r64_i32_r_h* src, fcl_mat_coo_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}
// coo -> csr
void morpheus_ccl_convert_mat_coo_to_mat_csr_r64_i32_r_h_serial(
    const fcl_mat_coo_r64_i32_r_h* src, fcl_mat_csr_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}
// csr -> dia
void morpheus_ccl_convert_mat_csr_to_mat_dia_r64_i32_r_h_serial(
    const fcl_mat_csr_r64_i32_r_h* src, fcl_mat_dia_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}

// dia -> dia
void morpheus_ccl_convert_mat_dia_to_mat_dia_r64_i32_r_h_serial(
    const fcl_mat_dia_r64_i32_r_h* src, fcl_mat_dia_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}
// dia -> coo
void morpheus_ccl_convert_mat_dia_to_mat_coo_r64_i32_r_h_serial(
    const fcl_mat_dia_r64_i32_r_h* src, fcl_mat_coo_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}
// coo -> dia
void morpheus_ccl_convert_mat_coo_to_mat_dia_r64_i32_r_h_serial(
    const fcl_mat_coo_r64_i32_r_h* src, fcl_mat_dia_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}
// dia -> csr
void morpheus_ccl_convert_mat_dia_to_mat_csr_r64_i32_r_h_serial(
    const fcl_mat_dia_r64_i32_r_h* src, fcl_mat_csr_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}

// dense mat -> dense mat
void morpheus_ccl_convert_mat_dense_to_mat_dense_r64_i32_r_h_serial(
    const fcl_mat_dense_r64_i32_r_h* src, fcl_mat_dense_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}
// dense mat -> dense vec
void morpheus_ccl_convert_mat_dense_to_vec_dense_r64_i32_r_h_serial(
    const fcl_mat_dense_r64_i32_r_h* src, fcl_vec_dense_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}
// dense mat -> coo
void morpheus_ccl_convert_mat_dense_to_mat_coo_r64_i32_r_h_serial(
    const fcl_mat_dense_r64_i32_r_h* src, fcl_mat_coo_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}
// coo -> dense mat
void morpheus_ccl_convert_mat_coo_to_mat_dense_r64_i32_r_h_serial(
    const fcl_mat_coo_r64_i32_r_h* src, fcl_mat_dense_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}

// dynamic -> concrete
void morpheus_ccl_convert_mat_dyn_to_mat_coo_r64_i32_r_h_serial(
    const fcl_mat_dyn_r64_i32_r_h* src, fcl_mat_coo_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}
void morpheus_ccl_convert_mat_dyn_to_mat_csr_r64_i32_r_h_serial(
    const fcl_mat_dyn_r64_i32_r_h* src, fcl_mat_csr_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}
void morpheus_ccl_convert_mat_dyn_to_mat_dia_r64_i32_r_h_serial(
    const fcl_mat_dyn_r64_i32_r_h* src, fcl_mat_dia_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}

// concrete -> dynamic
void morpheus_ccl_convert_mat_coo_to_mat_dyn_r64_i32_r_h_serial(
    const fcl_mat_coo_r64_i32_r_h* src, fcl_mat_dyn_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}

void morpheus_ccl_convert_mat_csr_to_mat_dyn_r64_i32_r_h_serial(
    const fcl_mat_csr_r64_i32_r_h* src, fcl_mat_dyn_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}

void morpheus_ccl_convert_mat_dia_to_mat_dyn_r64_i32_r_h_serial(
    const fcl_mat_dia_r64_i32_r_h* src, fcl_mat_dyn_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}

// dynamic -> dynamic
void morpheus_ccl_convert_mat_dyn_to_mat_dyn_r64_i32_r_h_serial(
    const fcl_mat_dyn_r64_i32_r_h* src, fcl_mat_dyn_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}

// in-place conversions for dynamic
void morpheus_ccl_convert_mat_dyn_r64_i32_r_h_serial(
    fcl_mat_dyn_r64_i32_r_h* mat, const fcl_formats_e index) {
  Morpheus::convert(*mat, index);
}

void morpheus_ccl_convert_index_mat_dyn_r64_i32_r_h_serial(
    fcl_mat_dyn_r64_i32_r_h* mat, const int index) {
  Morpheus::convert(*mat, index);
}

// desne vec -> dense vec
void morpheus_ccl_convert_vec_dense_to_vec_dense_r64_i32_r_h_serial(
    const fcl_vec_dense_r64_i32_r_h* src, fcl_vec_dense_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}
