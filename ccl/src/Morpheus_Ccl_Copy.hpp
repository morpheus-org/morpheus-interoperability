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

#ifndef MORPHEUS_CCL_COPY_HPP
#define MORPHEUS_CCL_COPY_HPP

#include <Morpheus_Ccl_CooMatrix.hpp>
#include <Morpheus_Ccl_CsrMatrix.hpp>
#include <Morpheus_Ccl_DiaMatrix.hpp>
#include <Morpheus_Ccl_DynamicMatrix.hpp>
#include <Morpheus_Ccl_DenseMatrix.hpp>
#include <Morpheus_Ccl_DenseVector.hpp>

#ifdef __cplusplus
extern "C" {
#endif

// coo -> coo
void morpheus_ccl_copy_mat_coo_to_mat_coo_serial(const ccl_mat_coo* src,
                                                 ccl_mat_coo* dst);
// coo -> coo_hostmirror
void morpheus_ccl_copy_mat_coo_to_mat_coo_hostmirror_serial(
    const ccl_mat_coo* src, ccl_mat_coo_hostmirror* dst);
// coo_hostmirror -> coo
void morpheus_ccl_copy_mat_coo_hostmirror_to_mat_coo_serial(
    const ccl_mat_coo_hostmirror* src, ccl_mat_coo* dst);
// coo_hostmirror -> coo_hostmirror
void morpheus_ccl_copy_mat_coo_hostmirror_to_mat_coo_hostmirror_serial(
    const ccl_mat_coo_hostmirror* src, ccl_mat_coo_hostmirror* dst);

// csr -> csr
void morpheus_ccl_copy_mat_csr_to_mat_csr_serial(const ccl_mat_csr* src,
                                                 ccl_mat_csr* dst);
// csr -> csr_hostmirror
void morpheus_ccl_copy_mat_csr_to_mat_csr_hostmirror_serial(
    const ccl_mat_csr* src, ccl_mat_csr_hostmirror* dst);
// csr_hostmirror -> csr
void morpheus_ccl_copy_mat_csr_hostmirror_to_mat_csr_serial(
    const ccl_mat_csr_hostmirror* src, ccl_mat_csr* dst);
// csr_hostmirror -> csr_hostmirror
void morpheus_ccl_copy_mat_csr_hostmirror_to_mat_csr_hostmirror_serial(
    const ccl_mat_csr_hostmirror* src, ccl_mat_csr_hostmirror* dst);

// dia -> dia
void morpheus_ccl_copy_mat_dia_to_mat_dia_serial(const ccl_mat_dia* src,
                                                 ccl_mat_dia* dst);
// dia -> dia_hostmirror
void morpheus_ccl_copy_mat_dia_to_mat_dia_hostmirror_serial(
    const ccl_mat_dia* src, ccl_mat_dia_hostmirror* dst);
// dia_hostmirror -> dia
void morpheus_ccl_copy_mat_dia_hostmirror_to_mat_dia_serial(
    const ccl_mat_dia_hostmirror* src, ccl_mat_dia* dst);
// dia_hostmirror -> dia_hostmirror
void morpheus_ccl_copy_mat_dia_hostmirror_to_mat_dia_hostmirror_serial(
    const ccl_mat_dia_hostmirror* src, ccl_mat_dia_hostmirror* dst);

// mat dense -> mat dense
void morpheus_ccl_copy_mat_dense_to_mat_dense_serial(const ccl_mat_dense* src,
                                                     ccl_mat_dense* dst);
// mat dense -> mat dense_hostmirror
void morpheus_ccl_copy_mat_dense_to_mat_dense_hostmirror_serial(
    const ccl_mat_dense* src, ccl_mat_dense_hostmirror* dst);
// mat dense_hostmirror -> mat dense
void morpheus_ccl_copy_mat_dense_hostmirror_to_mat_dense_serial(
    const ccl_mat_dense_hostmirror* src, ccl_mat_dense* dst);
// mat dense_hostmirror -> mat dense_hostmirror
void morpheus_ccl_copy_mat_dense_hostmirror_to_mat_dense_hostmirror_serial(
    const ccl_mat_dense_hostmirror* src, ccl_mat_dense_hostmirror* dst);

// vec dense -> vec dense
void morpheus_ccl_copy_vec_dense_to_vec_dense_serial(const ccl_vec_dense* src,
                                                     ccl_vec_dense* dst);
// vec dense -> vec dense_hostmirror
void morpheus_ccl_copy_vec_dense_to_vec_dense_hostmirror_serial(
    const ccl_vec_dense* src, ccl_vec_dense_hostmirror* dst);
// vec dense_hostmirror -> vec dense
void morpheus_ccl_copy_vec_dense_hostmirror_to_vec_dense_serial(
    const ccl_vec_dense_hostmirror* src, ccl_vec_dense* dst);
// vec dense_hostmirror -> vec dense_hostmirror
void morpheus_ccl_copy_vec_dense_hostmirror_to_vec_dense_hostmirror_serial(
    const ccl_vec_dense_hostmirror* src, ccl_vec_dense_hostmirror* dst);

// dyn -> dyn
void morpheus_ccl_copy_mat_dyn_to_mat_dyn_serial(const ccl_mat_dyn* src,
                                                 ccl_mat_dyn* dst);
// dyn -> dyn_hostmirror
void morpheus_ccl_copy_mat_dyn_to_mat_dyn_hostmirror_serial(
    const ccl_mat_dyn* src, ccl_mat_dyn_hostmirror* dst);
// dyn_hostmirror -> dyn
void morpheus_ccl_copy_mat_dyn_hostmirror_to_mat_dyn_serial(
    const ccl_mat_dyn_hostmirror* src, ccl_mat_dyn* dst);
// dyn_hostmirror -> dyn_hostmirror
void morpheus_ccl_copy_mat_dyn_hostmirror_to_mat_dyn_hostmirror_serial(
    const ccl_mat_dyn_hostmirror* src, ccl_mat_dyn_hostmirror* dst);

// coo -> dyn
void morpheus_ccl_copy_mat_coo_to_mat_dyn_serial(const ccl_mat_coo* src,
                                                 ccl_mat_dyn* dst);
// dyn -> coo
void morpheus_ccl_copy_mat_dyn_to_mat_coo_serial(const ccl_mat_dyn* src,
                                                 ccl_mat_coo* dst);
// coo_hostmirror -> dyn
void morpheus_ccl_copy_mat_coo_hostmirror_to_mat_dyn_serial(
    const ccl_mat_coo_hostmirror* src, ccl_mat_dyn* dst);
// dyn -> coo_hostmirror
void morpheus_ccl_copy_mat_dyn_to_mat_coo_hostmirror_serial(
    const ccl_mat_dyn* src, ccl_mat_coo_hostmirror* dst);

// coo -> dyn_hostmirror
void morpheus_ccl_copy_mat_coo_to_mat_dyn_hostmirror_serial(
    const ccl_mat_coo* src, ccl_mat_dyn_hostmirror* dst);
// dyn_hostmirror -> coo
void morpheus_ccl_copy_mat_dyn_hostmirror_to_mat_coo_serial(
    const ccl_mat_dyn_hostmirror* src, ccl_mat_coo* dst);
// coo_hostmirror -> dyn_hostmirror
void morpheus_ccl_copy_mat_coo_hostmirror_to_mat_dyn_hostmirror_serial(
    const ccl_mat_coo_hostmirror* src, ccl_mat_dyn_hostmirror* dst);
// dyn_hostmirror -> coo_hostmirror
void morpheus_ccl_copy_mat_dyn_hostmirror_to_mat_coo_hostmirror_serial(
    const ccl_mat_dyn_hostmirror* src, ccl_mat_coo_hostmirror* dst);

// csr -> dyn
void morpheus_ccl_copy_mat_csr_to_mat_dyn_serial(const ccl_mat_csr* src,
                                                 ccl_mat_dyn* dst);
// dyn -> csr
void morpheus_ccl_copy_mat_dyn_to_mat_csr_serial(const ccl_mat_dyn* src,
                                                 ccl_mat_csr* dst);
// csr_hostmirror -> dyn
void morpheus_ccl_copy_mat_csr_hostmirror_to_mat_dyn_serial(
    const ccl_mat_csr_hostmirror* src, ccl_mat_dyn* dst);
// dyn -> csr_hostmirror
void morpheus_ccl_copy_mat_dyn_to_mat_csr_hostmirror_serial(
    const ccl_mat_dyn* src, ccl_mat_csr_hostmirror* dst);

// csr -> dyn_hostmirror
void morpheus_ccl_copy_mat_csr_to_mat_dyn_hostmirror_serial(
    const ccl_mat_csr* src, ccl_mat_dyn_hostmirror* dst);
// dyn_hostmirror -> csr
void morpheus_ccl_copy_mat_dyn_hostmirror_to_mat_csr_serial(
    const ccl_mat_dyn_hostmirror* src, ccl_mat_csr* dst);
// csr_hostmirror -> dyn_hostmirror
void morpheus_ccl_copy_mat_csr_hostmirror_to_mat_dyn_hostmirror_serial(
    const ccl_mat_csr_hostmirror* src, ccl_mat_dyn_hostmirror* dst);
// dyn_hostmirror -> csr_hostmirror
void morpheus_ccl_copy_mat_dyn_hostmirror_to_mat_csr_hostmirror_serial(
    const ccl_mat_dyn_hostmirror* src, ccl_mat_csr_hostmirror* dst);

// dia -> dyn
void morpheus_ccl_copy_mat_dia_to_mat_dyn_serial(const ccl_mat_dia* src,
                                                 ccl_mat_dyn* dst);
// dyn -> dia
void morpheus_ccl_copy_mat_dyn_to_mat_dia_serial(const ccl_mat_dyn* src,
                                                 ccl_mat_dia* dst);
// dia_hostmirror -> dyn
void morpheus_ccl_copy_mat_dia_hostmirror_to_mat_dyn_serial(
    const ccl_mat_dia_hostmirror* src, ccl_mat_dyn* dst);
// dyn -> dia_hostmirror
void morpheus_ccl_copy_mat_dyn_to_mat_dia_hostmirror_serial(
    const ccl_mat_dyn* src, ccl_mat_dia_hostmirror* dst);

// dia -> dyn_hostmirror
void morpheus_ccl_copy_mat_dia_to_mat_dyn_hostmirror_serial(
    const ccl_mat_dia* src, ccl_mat_dyn_hostmirror* dst);
// dyn_hostmirror -> dia
void morpheus_ccl_copy_mat_dyn_hostmirror_to_mat_dia_serial(
    const ccl_mat_dyn_hostmirror* src, ccl_mat_dia* dst);
// dia_hostmirror -> dyn_hostmirror
void morpheus_ccl_copy_mat_dia_hostmirror_to_mat_dyn_hostmirror_serial(
    const ccl_mat_dia_hostmirror* src, ccl_mat_dyn_hostmirror* dst);
// dyn_hostmirror -> dia_hostmirror
void morpheus_ccl_copy_mat_dyn_hostmirror_to_mat_dia_hostmirror_serial(
    const ccl_mat_dyn_hostmirror* src, ccl_mat_dia_hostmirror* dst);

#ifdef __cplusplus
}
#endif

#endif  // MORPHEUS_CCL_COPY_HPP
