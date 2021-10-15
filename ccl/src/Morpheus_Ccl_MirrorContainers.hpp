/**
 * Morpheus_Ccl_MirrorContainers.hpp
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

#ifndef MORPHEUS_CCL_MIRRORCONTAINERS_HPP
#define MORPHEUS_CCL_MIRRORCONTAINERS_HPP

#include <Morpheus_Ccl_CooMatrix.hpp>
#include <Morpheus_Ccl_CsrMatrix.hpp>
#include <Morpheus_Ccl_DiaMatrix.hpp>
#include <Morpheus_Ccl_DynamicMatrix.hpp>
#include <Morpheus_Ccl_DenseMatrix.hpp>
#include <Morpheus_Ccl_DenseVector.hpp>

#ifdef __cplusplus
extern "C" {
#endif

ccl_mat_coo_hostmirror* morpheus_ccl_create_mirror_mat_coo_serial(
    ccl_mat_coo* src);

ccl_mat_csr_hostmirror* morpheus_ccl_create_mirror_mat_csr_serial(
    ccl_mat_csr* src);

ccl_mat_dia_hostmirror* morpheus_ccl_create_mirror_mat_dia_serial(
    ccl_mat_dia* src);

ccl_mat_dense_hostmirror* morpheus_ccl_create_mirror_mat_dense_serial(
    ccl_mat_dense* src);

ccl_vec_dense_hostmirror* morpheus_ccl_create_mirror_vec_dense_serial(
    ccl_vec_dense* src);

ccl_mat_dyn_hostmirror* morpheus_ccl_create_mirror_mat_dyn_serial(
    ccl_mat_dyn* src);

ccl_mat_coo* morpheus_ccl_create_mirror_container_mat_coo_serial(
    ccl_mat_coo* src);

ccl_mat_csr* morpheus_ccl_create_mirror_container_mat_csr_serial(
    ccl_mat_csr* src);

ccl_mat_dia* morpheus_ccl_create_mirror_container_mat_dia_serial(
    ccl_mat_dia* src);

ccl_mat_dense* morpheus_ccl_create_mirror_container_mat_dense_serial(
    ccl_mat_dense* src);

ccl_vec_dense* morpheus_ccl_create_mirror_container_vec_dense_serial(
    ccl_vec_dense* src);

ccl_mat_dyn* morpheus_ccl_create_mirror_container_mat_dyn_serial(
    ccl_mat_dyn* src);

#ifdef __cplusplus
}
#endif

#endif  // MORPHEUS_CCL_MIRRORCONTAINERS_HPP
