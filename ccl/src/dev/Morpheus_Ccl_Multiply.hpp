/**
 * Morpheus_Ccl_Multiply.hpp
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

#ifndef MORPHEUS_CCL_DEV_MULTIPLY_HPP
#define MORPHEUS_CCL_DEV_MULTIPLY_HPP

#include <dev/Morpheus_Ccl_CooMatrix.hpp>
#include <dev/Morpheus_Ccl_CsrMatrix.hpp>
#include <dev/Morpheus_Ccl_DiaMatrix.hpp>
#include <dev/Morpheus_Ccl_DynamicMatrix.hpp>
#include <dev/Morpheus_Ccl_DenseVector.hpp>

#ifdef __cplusplus
extern "C" {
#endif

void ccl_dmat_coo_dvec_dense_v_multiply(ccl_dmat_coo* A, ccl_dvec_dense_v* x,
                                        ccl_dvec_dense_v* y);

void ccl_dmat_csr_dvec_dense_v_multiply(ccl_dmat_csr* A, ccl_dvec_dense_v* x,
                                        ccl_dvec_dense_v* y);

void ccl_dmat_dia_dvec_dense_v_multiply(ccl_dmat_dia* A, ccl_dvec_dense_v* x,
                                        ccl_dvec_dense_v* y);

void ccl_dmat_dyn_dvec_dense_v_multiply(ccl_dmat_dyn* A, ccl_dvec_dense_v* x,
                                        ccl_dvec_dense_v* y);

void ccl_dmat_coo_hostmirror_dvec_dense_v_hostmirror_multiply(
    ccl_dmat_coo_hostmirror* A, ccl_dvec_dense_v_hostmirror* x,
    ccl_dvec_dense_v_hostmirror* y);

void ccl_dmat_csr_hostmirror_dvec_dense_v_hostmirror_multiply(
    ccl_dmat_csr_hostmirror* A, ccl_dvec_dense_v_hostmirror* x,
    ccl_dvec_dense_v_hostmirror* y);

void ccl_dmat_dia_hostmirror_dvec_dense_v_hostmirror_multiply(
    ccl_dmat_dia_hostmirror* A, ccl_dvec_dense_v_hostmirror* x,
    ccl_dvec_dense_v_hostmirror* y);

void ccl_dmat_dyn_hostmirror_dvec_dense_v_hostmirror_multiply(
    ccl_dmat_dyn_hostmirror* A, ccl_dvec_dense_v_hostmirror* x,
    ccl_dvec_dense_v_hostmirror* y);

#ifdef __cplusplus
}
#endif

#endif  // MORPHEUS_CCL_DEV_MULTIPLY_HPP
