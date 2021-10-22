/**
 * Morpheus_Ccl_Convert.hpp
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

#ifndef MORPHEUS_CCL_DEV_CONVERT_HPP
#define MORPHEUS_CCL_DEV_CONVERT_HPP

#include <dev/Morpheus_Ccl_CooMatrix.hpp>
#include <dev/Morpheus_Ccl_CsrMatrix.hpp>
#include <dev/Morpheus_Ccl_DiaMatrix.hpp>
#include <dev/Morpheus_Ccl_DynamicMatrix.hpp>
#include <dev/Morpheus_Ccl_DenseMatrix.hpp>
#include <dev/Morpheus_Ccl_DenseVector.hpp>

#ifdef __cplusplus
extern "C" {
#endif

// coo -> coo
void ccl_dmat_coo_hostmirror_convert_to_dmat_coo_hostmirror(
    const ccl_dmat_coo_hostmirror* src, ccl_dmat_coo_hostmirror* dst);

// csr -> csr
void ccl_dmat_csr_hostmirror_convert_to_dmat_csr_hostmirror(
    const ccl_dmat_csr_hostmirror* src, ccl_dmat_csr_hostmirror* dst);
// csr -> coo
void ccl_dmat_csr_hostmirror_convert_to_dmat_coo_hostmirror(
    const ccl_dmat_csr_hostmirror* src, ccl_dmat_coo_hostmirror* dst);
// coo -> csr
void ccl_dmat_coo_hostmirror_convert_to_dmat_csr_hostmirror(
    const ccl_dmat_coo_hostmirror* src, ccl_dmat_csr_hostmirror* dst);
// csr -> dia
void ccl_dmat_csr_hostmirror_convert_to_dmat_dia_hostmirror(
    const ccl_dmat_csr_hostmirror* src, ccl_dmat_dia_hostmirror* dst);

// dia -> dia
void ccl_dmat_dia_hostmirror_convert_to_dmat_dia_hostmirror(
    const ccl_dmat_dia_hostmirror* src, ccl_dmat_dia_hostmirror* dst);
// dia -> coo
void ccl_dmat_dia_hostmirror_convert_to_dmat_coo_hostmirror(
    const ccl_dmat_dia_hostmirror* src, ccl_dmat_coo_hostmirror* dst);
// coo -> dia
void ccl_dmat_coo_hostmirror_convert_to_dmat_dia_hostmirror(
    const ccl_dmat_coo_hostmirror* src, ccl_dmat_dia_hostmirror* dst);
// dia -> csr
void ccl_dmat_dia_hostmirror_convert_to_dmat_csr_hostmirror(
    const ccl_dmat_dia_hostmirror* src, ccl_dmat_csr_hostmirror* dst);

// dense mat -> dense mat
void ccl_dmat_dense_hostmirror_convert_to_dmat_dense_hostmirror(
    const ccl_dmat_dense_hostmirror* src, ccl_dmat_dense_hostmirror* dst);
// dense mat -> dense vec
void ccl_dmat_dense_hostmirror_convert_to_dvec_dense_v_hostmirror(
    const ccl_dmat_dense_hostmirror* src, ccl_dvec_dense_v_hostmirror* dst);
// dense mat -> coo
void ccl_dmat_dense_hostmirror_convert_to_dmat_coo_hostmirror(
    const ccl_dmat_dense_hostmirror* src, ccl_dmat_coo_hostmirror* dst);
// coo -> dense mat
void ccl_dmat_coo_hostmirror_convert_to_dmat_dense_hostmirror(
    const ccl_dmat_coo_hostmirror* src, ccl_dmat_dense_hostmirror* dst);

// dynamic -> concrete
void ccl_dmat_dyn_hostmirror_convert_to_dmat_coo_hostmirror(
    const ccl_dmat_dyn_hostmirror* src, ccl_dmat_coo_hostmirror* dst);
void ccl_dmat_dyn_hostmirror_convert_to_dmat_csr_hostmirror(
    const ccl_dmat_dyn_hostmirror* src, ccl_dmat_csr_hostmirror* dst);
void ccl_dmat_dyn_hostmirror_convert_to_dmat_dia_hostmirror(
    const ccl_dmat_dyn_hostmirror* src, ccl_dmat_dia_hostmirror* dst);

// concrete -> dynamic
void ccl_dmat_coo_hostmirror_convert_to_dmat_dyn_hostmirror(
    const ccl_dmat_coo_hostmirror* src, ccl_dmat_dyn_hostmirror* dst);

void ccl_dmat_csr_hostmirror_convert_to_dmat_dyn_hostmirror(
    const ccl_dmat_csr_hostmirror* src, ccl_dmat_dyn_hostmirror* dst);

void ccl_dmat_dia_hostmirror_convert_to_dmat_dyn_hostmirror(
    const ccl_dmat_dia_hostmirror* src, ccl_dmat_dyn_hostmirror* dst);

// dynamic -> dynamic
void ccl_dmat_dyn_hostmirror_convert_to_dmat_dyn_hostmirror(
    const ccl_dmat_dyn_hostmirror* src, ccl_dmat_dyn_hostmirror* dst);

// in-place conversions for dynamic
void ccl_dmat_dyn_hostmirror_convert(ccl_dmat_dyn_hostmirror* mat,
                                     const ccl_formats_e index);

void ccl_dmat_dyn_hostmirror_convert_index(ccl_dmat_dyn_hostmirror* mat,
                                           const int index);

// desne vec -> dense vec
void ccl_dvec_dense_v_hostmirror_convert_to_dvec_dense_v_hostmirror(
    const ccl_dvec_dense_v_hostmirror* src, ccl_dvec_dense_v_hostmirror* dst);
#ifdef __cplusplus
}
#endif

#endif  // MORPHEUS_CCL_DEV_CONVERT_HPP
