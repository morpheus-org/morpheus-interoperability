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

#ifndef MORPHEUS_CCL_HOST_CONVERT_HPP
#define MORPHEUS_CCL_HOST_CONVERT_HPP

#include <host/Morpheus_Ccl_CooMatrix.hpp>
#include <host/Morpheus_Ccl_CsrMatrix.hpp>
#include <host/Morpheus_Ccl_DiaMatrix.hpp>
#include <host/Morpheus_Ccl_DynamicMatrix.hpp>
#include <host/Morpheus_Ccl_DenseMatrix.hpp>
#include <host/Morpheus_Ccl_DenseVector.hpp>

#ifdef __cplusplus
extern "C" {
#endif

// coo -> coo
void ccl_hmat_coo_convert_to_hmat_coo(const ccl_hmat_coo* src,
                                      ccl_hmat_coo* dst);

// csr -> csr
void ccl_hmat_csr_convert_to_hmat_csr(const ccl_hmat_csr* src,
                                      ccl_hmat_csr* dst);
// csr -> coo
void ccl_hmat_csr_convert_to_hmat_coo(const ccl_hmat_csr* src,
                                      ccl_hmat_coo* dst);
// coo -> csr
void ccl_hmat_coo_convert_to_hmat_csr(const ccl_hmat_coo* src,
                                      ccl_hmat_csr* dst);
// csr -> dia
void ccl_hmat_csr_convert_to_hmat_dia(const ccl_hmat_csr* src,
                                      ccl_hmat_dia* dst);

// dia -> dia
void ccl_hmat_dia_convert_to_hmat_dia(const ccl_hmat_dia* src,
                                      ccl_hmat_dia* dst);
// dia -> coo
void ccl_hmat_dia_convert_to_hmat_coo(const ccl_hmat_dia* src,
                                      ccl_hmat_coo* dst);
// coo -> dia
void ccl_hmat_coo_convert_to_hmat_dia(const ccl_hmat_coo* src,
                                      ccl_hmat_dia* dst);
// dia -> csr
void ccl_hmat_dia_convert_to_hmat_csr(const ccl_hmat_dia* src,
                                      ccl_hmat_csr* dst);

// dense mat -> dense mat
void ccl_hmat_dense_convert_to_hmat_dense(const ccl_hmat_dense* src,
                                          ccl_hmat_dense* dst);
// dense mat -> dense vec
void ccl_hmat_dense_convert_to_hvec_dense_v(const ccl_hmat_dense* src,
                                            ccl_hvec_dense_v* dst);
// dense mat -> coo
void ccl_hmat_dense_convert_to_hmat_coo(const ccl_hmat_dense* src,
                                        ccl_hmat_coo* dst);
// coo -> dense mat
void ccl_hmat_coo_convert_to_hmat_dense(const ccl_hmat_coo* src,
                                        ccl_hmat_dense* dst);

// dynamic -> concrete
void ccl_hmat_dyn_convert_to_hmat_coo(const ccl_hmat_dyn* src,
                                      ccl_hmat_coo* dst);
void ccl_hmat_dyn_convert_to_hmat_csr(const ccl_hmat_dyn* src,
                                      ccl_hmat_csr* dst);
void ccl_hmat_dyn_convert_to_hmat_dia(const ccl_hmat_dyn* src,
                                      ccl_hmat_dia* dst);

// concrete -> dynamic
void ccl_hmat_coo_convert_to_hmat_dyn(const ccl_hmat_coo* src,
                                      ccl_hmat_dyn* dst);

void ccl_hmat_csr_convert_to_hmat_dyn(const ccl_hmat_csr* src,
                                      ccl_hmat_dyn* dst);

void ccl_hmat_dia_convert_to_hmat_dyn(const ccl_hmat_dia* src,
                                      ccl_hmat_dyn* dst);

// dynamic -> dynamic
void ccl_hmat_dyn_convert_to_hmat_dyn(const ccl_hmat_dyn* src,
                                      ccl_hmat_dyn* dst);

// in-place conversions for dynamic
void ccl_hmat_dyn_convert(ccl_hmat_dyn* mat, const ccl_formats_e index);

void ccl_hmat_dyn_convert_index(ccl_hmat_dyn* mat, const int index);

// desne vec -> dense vec
void ccl_hvec_dense_v_convert_to_hvec_dense_v(const ccl_hvec_dense_v* src,
                                              ccl_hvec_dense_v* dst);
#ifdef __cplusplus
}
#endif

#endif  // MORPHEUS_CCL_HOST_CONVERT_HPP
