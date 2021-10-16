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

#ifndef MORPHEUS_CCL_PHOST_MIRRORCONTAINERS_HPP
#define MORPHEUS_CCL_PHOST_MIRRORCONTAINERS_HPP

#include <phost/Morpheus_Ccl_CooMatrix.hpp>
#include <phost/Morpheus_Ccl_CsrMatrix.hpp>
#include <phost/Morpheus_Ccl_DiaMatrix.hpp>
#include <phost/Morpheus_Ccl_DynamicMatrix.hpp>
#include <phost/Morpheus_Ccl_DenseMatrix.hpp>
#include <phost/Morpheus_Ccl_DenseVector.hpp>

#ifdef __cplusplus
extern "C" {
#endif

ccl_phmat_coo_hostmirror* ccl_phmat_coo_create_mirror(ccl_phmat_coo* src);

ccl_phmat_csr_hostmirror* ccl_phmat_csr_create_mirror(ccl_phmat_csr* src);

ccl_phmat_dia_hostmirror* ccl_phmat_dia_create_mirror(ccl_phmat_dia* src);

ccl_phmat_dense_hostmirror* ccl_phmat_dense_create_mirror(ccl_phmat_dense* src);

ccl_phvec_dense_v_hostmirror* ccl_phvec_dense_v_create_mirror(
    ccl_phvec_dense_v* src);

ccl_phmat_dyn_hostmirror* ccl_phmat_dyn_create_mirror(ccl_phmat_dyn* src);

ccl_phmat_coo* ccl_phmat_coo_create_mirror_container(ccl_phmat_coo* src);

ccl_phmat_csr* ccl_phmat_csr_create_mirror_container(ccl_phmat_csr* src);

ccl_phmat_dia* ccl_phmat_dia_create_mirror_container(ccl_phmat_dia* src);

ccl_phmat_dense* ccl_phmat_dense_create_mirror_container(ccl_phmat_dense* src);

ccl_phvec_dense_v* ccl_phvec_dense_v_create_mirror_container(
    ccl_phvec_dense_v* src);

ccl_phmat_dyn* ccl_phmat_dyn_create_mirror_container(ccl_phmat_dyn* src);

#ifdef __cplusplus
}
#endif

#endif  // MORPHEUS_CCL_PHOST_MIRRORCONTAINERS_HPP
