/**
 * Fcl_C_Copy.hpp
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

#ifndef FCL_C_COPY_HPP
#define FCL_C_COPY_HPP

#include "Fcl_C_CooMatrix.hpp"
#include "Fcl_C_CsrMatrix.hpp"
#include "Fcl_C_DiaMatrix.hpp"
#include "Fcl_C_DynamicMatrix.hpp"
#include "Fcl_C_DenseMatrix.hpp"
#include "Fcl_C_DenseVector.hpp"

#ifdef __cplusplus
extern "C" {
#endif

// coo -> coo
void c_morpheus_copy_mat_coo_to_mat_coo_r64_i32_r_h_serial(
    const fcl_mat_coo_r64_i32_r_h* src, fcl_mat_coo_r64_i32_r_h* dst);
// coo -> coo_hostmirror
void c_morpheus_copy_mat_coo_to_mat_coo_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_coo_r64_i32_r_h* src,
    fcl_mat_coo_hostmirror_r64_i32_r_h* dst);
// coo_hostmirror -> coo
void c_morpheus_copy_mat_coo_hostmirror_to_mat_coo_r64_i32_r_h_serial(
    const fcl_mat_coo_hostmirror_r64_i32_r_h* src,
    fcl_mat_coo_r64_i32_r_h* dst);
// coo_hostmirror -> coo_hostmirror
void c_morpheus_copy_mat_coo_hostmirror_to_mat_coo_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_coo_hostmirror_r64_i32_r_h* src,
    fcl_mat_coo_hostmirror_r64_i32_r_h* dst);

// csr -> csr
void c_morpheus_copy_mat_csr_to_mat_csr_r64_i32_r_h_serial(
    const fcl_mat_csr_r64_i32_r_h* src, fcl_mat_csr_r64_i32_r_h* dst);
// csr -> csr_hostmirror
void c_morpheus_copy_mat_csr_to_mat_csr_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_csr_r64_i32_r_h* src,
    fcl_mat_csr_hostmirror_r64_i32_r_h* dst);
// csr_hostmirror -> csr
void c_morpheus_copy_mat_csr_hostmirror_to_mat_csr_r64_i32_r_h_serial(
    const fcl_mat_csr_hostmirror_r64_i32_r_h* src,
    fcl_mat_csr_r64_i32_r_h* dst);
// csr_hostmirror -> csr_hostmirror
void c_morpheus_copy_mat_csr_hostmirror_to_mat_csr_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_csr_hostmirror_r64_i32_r_h* src,
    fcl_mat_csr_hostmirror_r64_i32_r_h* dst);

// dia -> dia
void c_morpheus_copy_mat_dia_to_mat_dia_r64_i32_r_h_serial(
    const fcl_mat_dia_r64_i32_r_h* src, fcl_mat_dia_r64_i32_r_h* dst);
// dia -> dia_hostmirror
void c_morpheus_copy_mat_dia_to_mat_dia_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dia_r64_i32_r_h* src,
    fcl_mat_dia_hostmirror_r64_i32_r_h* dst);
// dia_hostmirror -> dia
void c_morpheus_copy_mat_dia_hostmirror_to_mat_dia_r64_i32_r_h_serial(
    const fcl_mat_dia_hostmirror_r64_i32_r_h* src,
    fcl_mat_dia_r64_i32_r_h* dst);
// dia_hostmirror -> dia_hostmirror
void c_morpheus_copy_mat_dia_hostmirror_to_mat_dia_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dia_hostmirror_r64_i32_r_h* src,
    fcl_mat_dia_hostmirror_r64_i32_r_h* dst);

// mat dense -> mat dense
void c_morpheus_copy_mat_dense_to_mat_dense_r64_i32_r_h_serial(
    const fcl_mat_dense_r64_i32_r_h* src, fcl_mat_dense_r64_i32_r_h* dst);
// mat dense -> mat dense_hostmirror
void c_morpheus_copy_mat_dense_to_mat_dense_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dense_r64_i32_r_h* src,
    fcl_mat_dense_hostmirror_r64_i32_r_h* dst);
// mat dense_hostmirror -> mat dense
void c_morpheus_copy_mat_dense_hostmirror_to_mat_dense_r64_i32_r_h_serial(
    const fcl_mat_dense_hostmirror_r64_i32_r_h* src,
    fcl_mat_dense_r64_i32_r_h* dst);
// mat dense_hostmirror -> mat dense_hostmirror
void c_morpheus_copy_mat_dense_hostmirror_to_mat_dense_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dense_hostmirror_r64_i32_r_h* src,
    fcl_mat_dense_hostmirror_r64_i32_r_h* dst);

// vec dense -> vec dense
void c_morpheus_copy_vec_dense_to_vec_dense_r64_i32_r_h_serial(
    const fcl_vec_dense_r64_i32_r_h* src, fcl_vec_dense_r64_i32_r_h* dst);
// vec dense -> vec dense_hostmirror
void c_morpheus_copy_vec_dense_to_vec_dense_hostmirror_r64_i32_r_h_serial(
    const fcl_vec_dense_r64_i32_r_h* src,
    fcl_vec_dense_hostmirror_r64_i32_r_h* dst);
// vec dense_hostmirror -> vec dense
void c_morpheus_copy_vec_dense_hostmirror_to_vec_dense_r64_i32_r_h_serial(
    const fcl_vec_dense_hostmirror_r64_i32_r_h* src,
    fcl_vec_dense_r64_i32_r_h* dst);
// vec dense_hostmirror -> vec dense_hostmirror
void c_morpheus_copy_vec_dense_hostmirror_to_vec_dense_hostmirror_r64_i32_r_h_serial(
    const fcl_vec_dense_hostmirror_r64_i32_r_h* src,
    fcl_vec_dense_hostmirror_r64_i32_r_h* dst);

// dyn -> dyn
void c_morpheus_copy_mat_dyn_to_mat_dyn_r64_i32_r_h_serial(
    const fcl_mat_dyn_r64_i32_r_h* src, fcl_mat_dyn_r64_i32_r_h* dst);
// dyn -> dyn_hostmirror
void c_morpheus_copy_mat_dyn_to_mat_dyn_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dyn_r64_i32_r_h* src,
    fcl_mat_dyn_hostmirror_r64_i32_r_h* dst);
// dyn_hostmirror -> dyn
void c_morpheus_copy_mat_dyn_hostmirror_to_mat_dyn_r64_i32_r_h_serial(
    const fcl_mat_dyn_hostmirror_r64_i32_r_h* src,
    fcl_mat_dyn_r64_i32_r_h* dst);
// dyn_hostmirror -> dyn_hostmirror
void c_morpheus_copy_mat_dyn_hostmirror_to_mat_dyn_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dyn_hostmirror_r64_i32_r_h* src,
    fcl_mat_dyn_hostmirror_r64_i32_r_h* dst);

// coo -> dyn
void c_morpheus_copy_mat_coo_to_mat_dyn_r64_i32_r_h_serial(
    const fcl_mat_coo_r64_i32_r_h* src, fcl_mat_dyn_r64_i32_r_h* dst);
// dyn -> coo
void c_morpheus_copy_mat_dyn_to_mat_coo_r64_i32_r_h_serial(
    const fcl_mat_dyn_r64_i32_r_h* src, fcl_mat_coo_r64_i32_r_h* dst);
// coo_hostmirror -> dyn
void c_morpheus_copy_mat_coo_hostmirror_to_mat_dyn_r64_i32_r_h_serial(
    const fcl_mat_coo_hostmirror_r64_i32_r_h* src,
    fcl_mat_dyn_r64_i32_r_h* dst);
// dyn -> coo_hostmirror
void c_morpheus_copy_mat_dyn_to_mat_coo_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dyn_r64_i32_r_h* src,
    fcl_mat_coo_hostmirror_r64_i32_r_h* dst);

// coo -> dyn_hostmirror
void c_morpheus_copy_mat_coo_to_mat_dyn_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_coo_r64_i32_r_h* src,
    fcl_mat_dyn_hostmirror_r64_i32_r_h* dst);
// dyn_hostmirror -> coo
void c_morpheus_copy_mat_dyn_hostmirror_to_mat_coo_r64_i32_r_h_serial(
    const fcl_mat_dyn_hostmirror_r64_i32_r_h* src,
    fcl_mat_coo_r64_i32_r_h* dst);
// coo_hostmirror -> dyn_hostmirror
void c_morpheus_copy_mat_coo_hostmirror_to_mat_dyn_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_coo_hostmirror_r64_i32_r_h* src,
    fcl_mat_dyn_hostmirror_r64_i32_r_h* dst);
// dyn_hostmirror -> coo_hostmirror
void c_morpheus_copy_mat_dyn_hostmirror_to_mat_coo_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dyn_hostmirror_r64_i32_r_h* src,
    fcl_mat_coo_hostmirror_r64_i32_r_h* dst);

// csr -> dyn
void c_morpheus_copy_mat_csr_to_mat_dyn_r64_i32_r_h_serial(
    const fcl_mat_csr_r64_i32_r_h* src, fcl_mat_dyn_r64_i32_r_h* dst);
// dyn -> csr
void c_morpheus_copy_mat_dyn_to_mat_csr_r64_i32_r_h_serial(
    const fcl_mat_dyn_r64_i32_r_h* src, fcl_mat_csr_r64_i32_r_h* dst);
// csr_hostmirror -> dyn
void c_morpheus_copy_mat_csr_hostmirror_to_mat_dyn_r64_i32_r_h_serial(
    const fcl_mat_csr_hostmirror_r64_i32_r_h* src,
    fcl_mat_dyn_r64_i32_r_h* dst);
// dyn -> csr_hostmirror
void c_morpheus_copy_mat_dyn_to_mat_csr_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dyn_r64_i32_r_h* src,
    fcl_mat_csr_hostmirror_r64_i32_r_h* dst);

// csr -> dyn_hostmirror
void c_morpheus_copy_mat_csr_to_mat_dyn_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_csr_r64_i32_r_h* src,
    fcl_mat_dyn_hostmirror_r64_i32_r_h* dst);
// dyn_hostmirror -> csr
void c_morpheus_copy_mat_dyn_hostmirror_to_mat_csr_r64_i32_r_h_serial(
    const fcl_mat_dyn_hostmirror_r64_i32_r_h* src,
    fcl_mat_csr_r64_i32_r_h* dst);
// csr_hostmirror -> dyn_hostmirror
void c_morpheus_copy_mat_csr_hostmirror_to_mat_dyn_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_csr_hostmirror_r64_i32_r_h* src,
    fcl_mat_dyn_hostmirror_r64_i32_r_h* dst);
// dyn_hostmirror -> csr_hostmirror
void c_morpheus_copy_mat_dyn_hostmirror_to_mat_csr_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dyn_hostmirror_r64_i32_r_h* src,
    fcl_mat_csr_hostmirror_r64_i32_r_h* dst);

// dia -> dyn
void c_morpheus_copy_mat_dia_to_mat_dyn_r64_i32_r_h_serial(
    const fcl_mat_dia_r64_i32_r_h* src, fcl_mat_dyn_r64_i32_r_h* dst);
// dyn -> dia
void c_morpheus_copy_mat_dyn_to_mat_dia_r64_i32_r_h_serial(
    const fcl_mat_dyn_r64_i32_r_h* src, fcl_mat_dia_r64_i32_r_h* dst);
// dia_hostmirror -> dyn
void c_morpheus_copy_mat_dia_hostmirror_to_mat_dyn_r64_i32_r_h_serial(
    const fcl_mat_dia_hostmirror_r64_i32_r_h* src,
    fcl_mat_dyn_r64_i32_r_h* dst);
// dyn -> dia_hostmirror
void c_morpheus_copy_mat_dyn_to_mat_dia_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dyn_r64_i32_r_h* src,
    fcl_mat_dia_hostmirror_r64_i32_r_h* dst);

// dia -> dyn_hostmirror
void c_morpheus_copy_mat_dia_to_mat_dyn_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dia_r64_i32_r_h* src,
    fcl_mat_dyn_hostmirror_r64_i32_r_h* dst);
// dyn_hostmirror -> dia
void c_morpheus_copy_mat_dyn_hostmirror_to_mat_dia_r64_i32_r_h_serial(
    const fcl_mat_dyn_hostmirror_r64_i32_r_h* src,
    fcl_mat_dia_r64_i32_r_h* dst);
// dia_hostmirror -> dyn_hostmirror
void c_morpheus_copy_mat_dia_hostmirror_to_mat_dyn_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dia_hostmirror_r64_i32_r_h* src,
    fcl_mat_dyn_hostmirror_r64_i32_r_h* dst);
// dyn_hostmirror -> dia_hostmirror
void c_morpheus_copy_mat_dyn_hostmirror_to_mat_dia_hostmirror_r64_i32_r_h_serial(
    const fcl_mat_dyn_hostmirror_r64_i32_r_h* src,
    fcl_mat_dia_hostmirror_r64_i32_r_h* dst);

#ifdef __cplusplus
}
#endif

#endif  // FCL_C_COPY_HPP