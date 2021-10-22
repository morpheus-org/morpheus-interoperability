/**
 * Morpheus_Ccl_Copy.hpp
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

#ifndef MORPHEUS_CCL_PHOST_COPY_HPP
#define MORPHEUS_CCL_PHOST_COPY_HPP

#include <phost/Morpheus_Ccl_CooMatrix.hpp>
#include <phost/Morpheus_Ccl_CsrMatrix.hpp>
#include <phost/Morpheus_Ccl_DiaMatrix.hpp>
#include <phost/Morpheus_Ccl_DynamicMatrix.hpp>
#include <phost/Morpheus_Ccl_DenseMatrix.hpp>
#include <phost/Morpheus_Ccl_DenseVector.hpp>

#ifdef __cplusplus
extern "C" {
#endif

// coo -> coo
void ccl_phmat_coo_copy_to_phmat_coo(const ccl_phmat_coo* src,
                                     ccl_phmat_coo* dst);

// coo -> coo_hostmirror
void ccl_phmat_coo_copy_to_phmat_coo_hostmirror(const ccl_phmat_coo* src,
                                                ccl_phmat_coo_hostmirror* dst);

// coo_hostmirror -> coo
void ccl_phmat_coo_hostmirror_copy_to_phmat_coo(
    const ccl_phmat_coo_hostmirror* src, ccl_phmat_coo* dst);

// coo_hostmirror -> coo_hostmirror
void ccl_phmat_coo_hostmirror_copy_to_phmat_coo_hostmirror(
    const ccl_phmat_coo_hostmirror* src, ccl_phmat_coo_hostmirror* dst);

// csr -> csr
void ccl_phmat_csr_copy_to_phmat_csr(const ccl_phmat_csr* src,
                                     ccl_phmat_csr* dst);

// csr -> csr_hostmirror
void ccl_phmat_csr_copy_to_phmat_csr_hostmirror(const ccl_phmat_csr* src,
                                                ccl_phmat_csr_hostmirror* dst);

// csr_hostmirror -> csr
void ccl_phmat_csr_hostmirror_copy_to_phmat_csr(
    const ccl_phmat_csr_hostmirror* src, ccl_phmat_csr* dst);

// csr_hostmirror -> csr_hostmirror
void ccl_phmat_csr_hostmirror_copy_to_phmat_csr_hostmirror(
    const ccl_phmat_csr_hostmirror* src, ccl_phmat_csr_hostmirror* dst);

// dia -> dia
void ccl_phmat_dia_copy_to_phmat_dia(const ccl_phmat_dia* src,
                                     ccl_phmat_dia* dst);

// dia -> dia_hostmirror
void ccl_phmat_dia_copy_to_phmat_dia_hostmirror(const ccl_phmat_dia* src,
                                                ccl_phmat_dia_hostmirror* dst);

// dia_hostmirror -> dia
void ccl_phmat_dia_hostmirror_copy_to_phmat_dia(
    const ccl_phmat_dia_hostmirror* src, ccl_phmat_dia* dst);

// dia_hostmirror -> dia_hostmirror
void ccl_phmat_dia_hostmirror_copy_to_phmat_dia_hostmirror(
    const ccl_phmat_dia_hostmirror* src, ccl_phmat_dia_hostmirror* dst);

// mat dense -> mat dense
void ccl_phmat_dense_copy_to_phmat_dense(const ccl_phmat_dense* src,
                                         ccl_phmat_dense* dst);

// mat dense -> mat dense_hostmirror
void ccl_phmat_dense_copy_to_phmat_dense_hostmirror(
    const ccl_phmat_dense* src, ccl_phmat_dense_hostmirror* dst);

// mat dense_hostmirror -> mat dense
void ccl_phmat_dense_hostmirror_copy_to_phmat_dense(
    const ccl_phmat_dense_hostmirror* src, ccl_phmat_dense* dst);

// mat dense_hostmirror -> mat dense_hostmirror
void ccl_phmat_dense_hostmirror_copy_to_phmat_dense_hostmirror(
    const ccl_phmat_dense_hostmirror* src, ccl_phmat_dense_hostmirror* dst);

// vec dense -> vec dense
void ccl_phvec_dense_v_copy_to_phvec_dense_v(const ccl_phvec_dense_v* src,
                                             ccl_phvec_dense_v* dst);

// vec dense -> vec dense_hostmirror
void ccl_phvec_dense_v_copy_to_phvec_dense_v_hostmirror(
    const ccl_phvec_dense_v* src, ccl_phvec_dense_v_hostmirror* dst);

// vec dense_hostmirror -> vec dense
void ccl_phvec_dense_v_copy_hostmirror_to_phvec_dense_v(
    const ccl_phvec_dense_v_hostmirror* src, ccl_phvec_dense_v* dst);

// vec dense_hostmirror -> vec dense_hostmirror
void ccl_phvec_dense_v_hostmirror_copy_to_phvec_dense_v_hostmirror(
    const ccl_phvec_dense_v_hostmirror* src, ccl_phvec_dense_v_hostmirror* dst);

// dyn -> dyn
void ccl_phmat_dyn_copy_to_phmat_dyn(const ccl_phmat_dyn* src,
                                     ccl_phmat_dyn* dst);

// dyn -> dyn_hostmirror
void ccl_phmat_dyn_copy_to_phmat_dyn_hostmirror(const ccl_phmat_dyn* src,
                                                ccl_phmat_dyn_hostmirror* dst);

// dyn_hostmirror -> dyn
void ccl_phmat_dyn_hostmirror_copy_to_phmat_dyn(
    const ccl_phmat_dyn_hostmirror* src, ccl_phmat_dyn* dst);

// dyn_hostmirror -> dyn_hostmirror
void ccl_phmat_dyn_hostmirror_copy_to_phmat_dyn_hostmirror(
    const ccl_phmat_dyn_hostmirror* src, ccl_phmat_dyn_hostmirror* dst);

// coo -> dyn
void ccl_phmat_coo_copy_to_phmat_dyn(const ccl_phmat_coo* src,
                                     ccl_phmat_dyn* dst);

// dyn -> coo
void ccl_phmat_dyn_copy_to_phmat_coo(const ccl_phmat_dyn* src,
                                     ccl_phmat_coo* dst);

// coo_hostmirror -> dyn
void ccl_phmat_coo_hostmirror_copy_to_phmat_dyn(
    const ccl_phmat_coo_hostmirror* src, ccl_phmat_dyn* dst);

// dyn -> coo_hostmirror
void ccl_phmat_dyn_copy_to_phmat_coo_hostmirror(const ccl_phmat_dyn* src,
                                                ccl_phmat_coo_hostmirror* dst);

// coo -> dyn_hostmirror
void ccl_phmat_coo_copy_to_phmat_dyn_hostmirror(const ccl_phmat_coo* src,
                                                ccl_phmat_dyn_hostmirror* dst);

// dyn_hostmirror -> coo
void ccl_phmat_dyn_hostmirror_copy_to_phmat_coo(
    const ccl_phmat_dyn_hostmirror* src, ccl_phmat_coo* dst);

// coo_hostmirror -> dyn_hostmirror
void ccl_phmat_coo_hostmirror_copy_to_phmat_dyn_hostmirror(
    const ccl_phmat_coo_hostmirror* src, ccl_phmat_dyn_hostmirror* dst);

// dyn_hostmirror -> coo_hostmirror
void ccl_phmat_dyn_hostmirror_copy_to_phmat_coo_hostmirror(
    const ccl_phmat_dyn_hostmirror* src, ccl_phmat_coo_hostmirror* dst);

// csr -> dyn
void ccl_phmat_csr_copy_to_phmat_dyn(const ccl_phmat_csr* src,
                                     ccl_phmat_dyn* dst);

// dyn -> csr
void ccl_copy_phmat_dyn_to_phmat_csr(const ccl_phmat_dyn* src,
                                     ccl_phmat_csr* dst);

// csr_hostmirror -> dyn
void ccl_phmat_csr_hostmirror_copy_to_phmat_dyn(
    const ccl_phmat_csr_hostmirror* src, ccl_phmat_dyn* dst);

// dyn -> csr_hostmirror
void ccl_phmat_dyn_copy_to_phmat_csr_hostmirror(const ccl_phmat_dyn* src,
                                                ccl_phmat_csr_hostmirror* dst);

// csr -> dyn_hostmirror
void ccl_phmat_csr_copy_to_phmat_dyn_hostmirror(const ccl_phmat_csr* src,
                                                ccl_phmat_dyn_hostmirror* dst);

// dyn_hostmirror -> csr
void ccl_phmat_dyn_hostmirror_copy_to_phmat_csr(
    const ccl_phmat_dyn_hostmirror* src, ccl_phmat_csr* dst);

// csr_hostmirror -> dyn_hostmirror
void ccl_phmat_csr_hostmirror_copy_to_phmat_dyn_hostmirror(
    const ccl_phmat_csr_hostmirror* src, ccl_phmat_dyn_hostmirror* dst);

// dyn_hostmirror -> csr_hostmirror
void ccl_phmat_dyn_hostmirror_copy_to_phmat_csr_hostmirror(
    const ccl_phmat_dyn_hostmirror* src, ccl_phmat_csr_hostmirror* dst);

// dia -> dyn
void ccl_phmat_dia_copy_to_phmat_dyn(const ccl_phmat_dia* src,
                                     ccl_phmat_dyn* dst);

// dyn -> dia
void ccl_phmat_dyn_copy_to_phmat_dia(const ccl_phmat_dyn* src,
                                     ccl_phmat_dia* dst);

// dia_hostmirror -> dyn
void ccl_phmat_dia_hostmirror_copy_to_phmat_dyn(
    const ccl_phmat_dia_hostmirror* src, ccl_phmat_dyn* dst);

// dyn -> dia_hostmirror
void ccl_phmat_dyn_copy_to_phmat_dia_hostmirror(const ccl_phmat_dyn* src,
                                                ccl_phmat_dia_hostmirror* dst);

// dia -> dyn_hostmirror
void ccl_phmat_dia_copy_to_phmat_dyn_hostmirror(const ccl_phmat_dia* src,
                                                ccl_phmat_dyn_hostmirror* dst);

// dyn_hostmirror -> dia
void ccl_phmat_dyn_hostmirror_copy_to_phmat_dia(
    const ccl_phmat_dyn_hostmirror* src, ccl_phmat_dia* dst);

// dia_hostmirror -> dyn_hostmirror
void ccl_phmat_dia_hostmirror_copy_to_phmat_dyn_hostmirror(
    const ccl_phmat_dia_hostmirror* src, ccl_phmat_dyn_hostmirror* dst);

// dyn_hostmirror -> dia_hostmirror
void ccl_phmat_dyn_hostmirror_copy_to_phmat_dia_hostmirror(
    const ccl_phmat_dyn_hostmirror* src, ccl_phmat_dia_hostmirror* dst);

#ifdef __cplusplus
}
#endif

#endif  // MORPHEUS_CCL_PHOST_COPY_HPP
