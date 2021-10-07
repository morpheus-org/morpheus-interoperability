/**
 * Fcl_C_Convert.cpp
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

#include "Fcl_C_Convert.hpp"

// coo -> coo
void c_morpheus_convert_mat_coo_to_mat_coo_r64_i32_r_h_serial(
    const fcl_mat_coo_r64_i32_r_h* src, fcl_mat_coo_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}

// csr -> csr
void c_morpheus_convert_mat_csr_to_mat_csr_r64_i32_r_h_serial(
    const fcl_mat_csr_r64_i32_r_h* src, fcl_mat_csr_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}
// csr -> coo
void c_morpheus_convert_mat_csr_to_mat_coo_r64_i32_r_h_serial(
    const fcl_mat_csr_r64_i32_r_h* src, fcl_mat_coo_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}
// coo -> csr
void c_morpheus_convert_mat_coo_to_mat_csr_r64_i32_r_h_serial(
    const fcl_mat_coo_r64_i32_r_h* src, fcl_mat_csr_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}
// csr -> dia
void c_morpheus_convert_mat_csr_to_mat_dia_r64_i32_r_h_serial(
    const fcl_mat_csr_r64_i32_r_h* src, fcl_mat_dia_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}

// dia -> dia
void c_morpheus_convert_mat_dia_to_mat_dia_r64_i32_r_h_serial(
    const fcl_mat_dia_r64_i32_r_h* src, fcl_mat_dia_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}
// dia -> coo
void c_morpheus_convert_mat_dia_to_mat_coo_r64_i32_r_h_serial(
    const fcl_mat_dia_r64_i32_r_h* src, fcl_mat_coo_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}
// coo -> dia
void c_morpheus_convert_mat_coo_to_mat_dia_r64_i32_r_h_serial(
    const fcl_mat_coo_r64_i32_r_h* src, fcl_mat_dia_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}
// dia -> csr
void c_morpheus_convert_mat_dia_to_mat_csr_r64_i32_r_h_serial(
    const fcl_mat_dia_r64_i32_r_h* src, fcl_mat_csr_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}

// dense mat -> dense mat
void c_morpheus_convert_mat_dense_to_mat_dense_r64_i32_r_h_serial(
    const fcl_mat_dense_r64_i32_r_h* src, fcl_mat_dense_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}
// dense mat -> dense vec
void c_morpheus_convert_mat_dense_to_vec_dense_r64_i32_r_h_serial(
    const fcl_mat_dense_r64_i32_r_h* src, fcl_vec_dense_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}
// dense mat -> coo
void c_morpheus_convert_mat_dense_to_mat_coo_r64_i32_r_h_serial(
    const fcl_mat_dense_r64_i32_r_h* src, fcl_mat_coo_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}
// coo -> dense mat
void c_morpheus_convert_mat_coo_to_mat_dense_r64_i32_r_h_serial(
    const fcl_mat_coo_r64_i32_r_h* src, fcl_mat_dense_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}

// dynamic -> concrete
void c_morpheus_convert_mat_dyn_to_mat_coo_r64_i32_r_h_serial(
    const fcl_mat_dyn_r64_i32_r_h* src, fcl_mat_coo_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}
void c_morpheus_convert_mat_dyn_to_mat_csr_r64_i32_r_h_serial(
    const fcl_mat_dyn_r64_i32_r_h* src, fcl_mat_csr_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}
void c_morpheus_convert_mat_dyn_to_mat_dia_r64_i32_r_h_serial(
    const fcl_mat_dyn_r64_i32_r_h* src, fcl_mat_dia_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}

// concrete -> dynamic
void c_morpheus_convert_mat_coo_to_mat_dyn_r64_i32_r_h_serial(
    const fcl_mat_coo_r64_i32_r_h* src, fcl_mat_dyn_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}

void c_morpheus_convert_mat_csr_to_mat_dyn_r64_i32_r_h_serial(
    const fcl_mat_csr_r64_i32_r_h* src, fcl_mat_dyn_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}

void c_morpheus_convert_mat_dia_to_mat_dyn_r64_i32_r_h_serial(
    const fcl_mat_dia_r64_i32_r_h* src, fcl_mat_dyn_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}

// dynamic -> dynamic
void c_morpheus_convert_mat_dyn_to_mat_dyn_r64_i32_r_h_serial(
    const fcl_mat_dyn_r64_i32_r_h* src, fcl_mat_dyn_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}

// desne vec -> dense vec
void c_morpheus_convert_vec_dense_to_vec_dense_r64_i32_r_h_serial(
    const fcl_vec_dense_r64_i32_r_h* src, fcl_vec_dense_r64_i32_r_h* dst) {
  Morpheus::convert(*src, *dst);
}
