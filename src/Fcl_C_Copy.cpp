/**
 * Fcl_C_Copy.cpp
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

#include "Fcl_C_Copy.hpp"

// coo -> coo
void c_morpheus_copy_mat_coo_to_mat_coo_r64_i32_r_h_serial(
    const fcl_mat_coo_r64_i32_r_h* src, fcl_mat_coo_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// coo -> coo_hostmirror
void c_morpheus_copy_mat_coo_to_mat_coo_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_coo_r64_i32_r_h* src,
    fcl_mat_coo_hostmirror_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// coo_hostmirror -> coo
void c_morpheus_copy_mat_coo_hostmirror_to_mat_coo_r64_i32_r_h_serial(
    const fcl_mat_coo_hostmirror_r64_i32_r_h* src,
    fcl_mat_coo_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// coo_hostmirror -> coo_hostmirror
void c_morpheus_copy_mat_coo_hostmirror_to_mat_coo_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_coo_hostmirror_r64_i32_r_h* src,
    fcl_mat_coo_hostmirror_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// csr -> csr
void c_morpheus_copy_mat_csr_to_mat_csr_r64_i32_r_h_serial(
    const fcl_mat_csr_r64_i32_r_h* src, fcl_mat_csr_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// csr -> csr_hostmirror
void c_morpheus_copy_mat_csr_to_mat_csr_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_csr_r64_i32_r_h* src,
    fcl_mat_csr_hostmirror_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// csr_hostmirror -> csr
void c_morpheus_copy_mat_csr_hostmirror_to_mat_csr_r64_i32_r_h_serial(
    const fcl_mat_csr_hostmirror_r64_i32_r_h* src,
    fcl_mat_csr_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// csr_hostmirror -> csr_hostmirror
void c_morpheus_copy_mat_csr_hostmirror_to_mat_csr_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_csr_hostmirror_r64_i32_r_h* src,
    fcl_mat_csr_hostmirror_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// dia -> dia
void c_morpheus_copy_mat_dia_to_mat_dia_r64_i32_r_h_serial(
    const fcl_mat_dia_r64_i32_r_h* src, fcl_mat_dia_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// dia -> dia_hostmirror
void c_morpheus_copy_mat_dia_to_mat_dia_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dia_r64_i32_r_h* src,
    fcl_mat_dia_hostmirror_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// dia_hostmirror -> dia
void c_morpheus_copy_mat_dia_hostmirror_to_mat_dia_r64_i32_r_h_serial(
    const fcl_mat_dia_hostmirror_r64_i32_r_h* src,
    fcl_mat_dia_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// dia_hostmirror -> dia_hostmirror
void c_morpheus_copy_mat_dia_hostmirror_to_mat_dia_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dia_hostmirror_r64_i32_r_h* src,
    fcl_mat_dia_hostmirror_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// mat dense -> mat dense
void c_morpheus_copy_mat_dense_to_mat_dense_r64_i32_r_h_serial(
    const fcl_mat_dense_r64_i32_r_h* src, fcl_mat_dense_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// mat dense -> mat dense_hostmirror
void c_morpheus_copy_mat_dense_to_mat_dense_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dense_r64_i32_r_h* src,
    fcl_mat_dense_hostmirror_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// mat dense_hostmirror -> mat dense
void c_morpheus_copy_mat_dense_hostmirror_to_mat_dense_r64_i32_r_h_serial(
    const fcl_mat_dense_hostmirror_r64_i32_r_h* src,
    fcl_mat_dense_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// mat dense_hostmirror -> mat dense_hostmirror
void c_morpheus_copy_mat_dense_hostmirror_to_mat_dense_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dense_hostmirror_r64_i32_r_h* src,
    fcl_mat_dense_hostmirror_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// vec dense -> vec dense
void c_morpheus_copy_vec_dense_to_vec_dense_r64_i32_r_h_serial(
    const fcl_vec_dense_r64_i32_r_h* src, fcl_vec_dense_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// vec dense -> vec dense_hostmirror
void c_morpheus_copy_vec_dense_to_vec_dense_hostmirror_r64_i32_r_h_serial(
    const fcl_vec_dense_r64_i32_r_h* src,
    fcl_vec_dense_hostmirror_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// vec dense_hostmirror -> vec dense
void c_morpheus_copy_vec_dense_hostmirror_to_vec_dense_r64_i32_r_h_serial(
    const fcl_vec_dense_hostmirror_r64_i32_r_h* src,
    fcl_vec_dense_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// vec dense_hostmirror -> vec dense_hostmirror
void c_morpheus_copy_vec_dense_hostmirror_to_vec_dense_hostmirror_r64_i32_r_h_serial(
    const fcl_vec_dense_hostmirror_r64_i32_r_h* src,
    fcl_vec_dense_hostmirror_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// dyn -> dyn
void c_morpheus_copy_mat_dyn_to_mat_dyn_r64_i32_r_h_serial(
    const fcl_mat_dyn_r64_i32_r_h* src, fcl_mat_dyn_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// dyn -> dyn_hostmirror
void c_morpheus_copy_mat_dyn_to_mat_dyn_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dyn_r64_i32_r_h* src,
    fcl_mat_dyn_hostmirror_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// dyn_hostmirror -> dyn
void c_morpheus_copy_mat_dyn_hostmirror_to_mat_dyn_r64_i32_r_h_serial(
    const fcl_mat_dyn_hostmirror_r64_i32_r_h* src,
    fcl_mat_dyn_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// dyn_hostmirror -> dyn_hostmirror
void c_morpheus_copy_mat_dyn_hostmirror_to_mat_dyn_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dyn_hostmirror_r64_i32_r_h* src,
    fcl_mat_dyn_hostmirror_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// coo -> dyn
void c_morpheus_copy_mat_coo_to_mat_dyn_r64_i32_r_h_serial(
    const fcl_mat_coo_r64_i32_r_h* src, fcl_mat_dyn_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// dyn -> coo
void c_morpheus_copy_mat_dyn_to_mat_coo_r64_i32_r_h_serial(
    const fcl_mat_dyn_r64_i32_r_h* src, fcl_mat_coo_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// coo_hostmirror -> dyn
void c_morpheus_copy_mat_coo_hostmirror_to_mat_dyn_r64_i32_r_h_serial(
    const fcl_mat_coo_hostmirror_r64_i32_r_h* src,
    fcl_mat_dyn_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// dyn -> coo_hostmirror
void c_morpheus_copy_mat_dyn_to_mat_coo_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dyn_r64_i32_r_h* src,
    fcl_mat_coo_hostmirror_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// coo -> dyn_hostmirror
void c_morpheus_copy_mat_coo_to_mat_dyn_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_coo_r64_i32_r_h* src,
    fcl_mat_dyn_hostmirror_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// dyn_hostmirror -> coo
void c_morpheus_copy_mat_dyn_hostmirror_to_mat_coo_r64_i32_r_h_serial(
    const fcl_mat_dyn_hostmirror_r64_i32_r_h* src,
    fcl_mat_coo_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// coo_hostmirror -> dyn_hostmirror
void c_morpheus_copy_mat_coo_hostmirror_to_mat_dyn_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_coo_hostmirror_r64_i32_r_h* src,
    fcl_mat_dyn_hostmirror_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// dyn_hostmirror -> coo_hostmirror
void c_morpheus_copy_mat_dyn_hostmirror_to_mat_coo_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dyn_hostmirror_r64_i32_r_h* src,
    fcl_mat_coo_hostmirror_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// csr -> dyn
void c_morpheus_copy_mat_csr_to_mat_dyn_r64_i32_r_h_serial(
    const fcl_mat_csr_r64_i32_r_h* src, fcl_mat_dyn_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// dyn -> csr
void c_morpheus_copy_mat_dyn_to_mat_csr_r64_i32_r_h_serial(
    const fcl_mat_dyn_r64_i32_r_h* src, fcl_mat_csr_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// csr_hostmirror -> dyn
void c_morpheus_copy_mat_csr_hostmirror_to_mat_dyn_r64_i32_r_h_serial(
    const fcl_mat_csr_hostmirror_r64_i32_r_h* src,
    fcl_mat_dyn_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// dyn -> csr_hostmirror
void c_morpheus_copy_mat_dyn_to_mat_csr_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dyn_r64_i32_r_h* src,
    fcl_mat_csr_hostmirror_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// csr -> dyn_hostmirror
void c_morpheus_copy_mat_csr_to_mat_dyn_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_csr_r64_i32_r_h* src,
    fcl_mat_dyn_hostmirror_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// dyn_hostmirror -> csr
void c_morpheus_copy_mat_dyn_hostmirror_to_mat_csr_r64_i32_r_h_serial(
    const fcl_mat_dyn_hostmirror_r64_i32_r_h* src,
    fcl_mat_csr_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// csr_hostmirror -> dyn_hostmirror
void c_morpheus_copy_mat_csr_hostmirror_to_mat_dyn_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_csr_hostmirror_r64_i32_r_h* src,
    fcl_mat_dyn_hostmirror_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// dyn_hostmirror -> csr_hostmirror
void c_morpheus_copy_mat_dyn_hostmirror_to_mat_csr_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dyn_hostmirror_r64_i32_r_h* src,
    fcl_mat_csr_hostmirror_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// dia -> dyn
void c_morpheus_copy_mat_dia_to_mat_dyn_r64_i32_r_h_serial(
    const fcl_mat_dia_r64_i32_r_h* src, fcl_mat_dyn_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// dyn -> dia
void c_morpheus_copy_mat_dyn_to_mat_dia_r64_i32_r_h_serial(
    const fcl_mat_dyn_r64_i32_r_h* src, fcl_mat_dia_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// dia_hostmirror -> dyn
void c_morpheus_copy_mat_dia_hostmirror_to_mat_dyn_r64_i32_r_h_serial(
    const fcl_mat_dia_hostmirror_r64_i32_r_h* src,
    fcl_mat_dyn_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// dyn -> dia_hostmirror
void c_morpheus_copy_mat_dyn_to_mat_dia_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dyn_r64_i32_r_h* src,
    fcl_mat_dia_hostmirror_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// dia -> dyn_hostmirror
void c_morpheus_copy_mat_dia_to_mat_dyn_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dia_r64_i32_r_h* src,
    fcl_mat_dyn_hostmirror_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// dyn_hostmirror -> dia
void c_morpheus_copy_mat_dyn_hostmirror_to_mat_dia_r64_i32_r_h_serial(
    const fcl_mat_dyn_hostmirror_r64_i32_r_h* src,
    fcl_mat_dia_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// dia_hostmirror -> dyn_hostmirror
void c_morpheus_copy_mat_dia_hostmirror_to_mat_dyn_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dia_hostmirror_r64_i32_r_h* src,
    fcl_mat_dyn_hostmirror_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}

// dyn_hostmirror -> dia_hostmirror
void c_morpheus_copy_mat_dyn_hostmirror_to_mat_dia_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dyn_hostmirror_r64_i32_r_h* src,
    fcl_mat_dia_hostmirror_r64_i32_r_h* dst) {
  Morpheus::copy(*src, *dst);
}
