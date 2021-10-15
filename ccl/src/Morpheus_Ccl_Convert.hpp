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

#ifndef MORPHEUS_CCL_CONVERT_HPP
#define MORPHEUS_CCL_CONVERT_HPP

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
void morpheus_ccl_convert_mat_coo_to_mat_coo_serial(const ccl_mat_coo* src,
                                                    ccl_mat_coo* dst);

// csr -> csr
void morpheus_ccl_convert_mat_csr_to_mat_csr_serial(const ccl_mat_csr* src,
                                                    ccl_mat_csr* dst);
// csr -> coo
void morpheus_ccl_convert_mat_csr_to_mat_coo_serial(const ccl_mat_csr* src,
                                                    ccl_mat_coo* dst);
// coo -> csr
void morpheus_ccl_convert_mat_coo_to_mat_csr_serial(const ccl_mat_coo* src,
                                                    ccl_mat_csr* dst);
// csr -> dia
void morpheus_ccl_convert_mat_csr_to_mat_dia_serial(const ccl_mat_csr* src,
                                                    ccl_mat_dia* dst);

// dia -> dia
void morpheus_ccl_convert_mat_dia_to_mat_dia_serial(const ccl_mat_dia* src,
                                                    ccl_mat_dia* dst);
// dia -> coo
void morpheus_ccl_convert_mat_dia_to_mat_coo_serial(const ccl_mat_dia* src,
                                                    ccl_mat_coo* dst);
// coo -> dia
void morpheus_ccl_convert_mat_coo_to_mat_dia_serial(const ccl_mat_coo* src,
                                                    ccl_mat_dia* dst);
// dia -> csr
void morpheus_ccl_convert_mat_dia_to_mat_csr_serial(const ccl_mat_dia* src,
                                                    ccl_mat_csr* dst);

// dense mat -> dense mat
void morpheus_ccl_convert_mat_dense_to_mat_dense_serial(
    const ccl_mat_dense* src, ccl_mat_dense* dst);
// dense mat -> dense vec
void morpheus_ccl_convert_mat_dense_to_vec_dense_serial(
    const ccl_mat_dense* src, ccl_vec_dense* dst);
// dense mat -> coo
void morpheus_ccl_convert_mat_dense_to_mat_coo_serial(const ccl_mat_dense* src,
                                                      ccl_mat_coo* dst);
// coo -> dense mat
void morpheus_ccl_convert_mat_coo_to_mat_dense_serial(const ccl_mat_coo* src,
                                                      ccl_mat_dense* dst);

// dynamic -> concrete
void morpheus_ccl_convert_mat_dyn_to_mat_coo_serial(const ccl_mat_dyn* src,
                                                    ccl_mat_coo* dst);
void morpheus_ccl_convert_mat_dyn_to_mat_csr_serial(const ccl_mat_dyn* src,
                                                    ccl_mat_csr* dst);
void morpheus_ccl_convert_mat_dyn_to_mat_dia_serial(const ccl_mat_dyn* src,
                                                    ccl_mat_dia* dst);

// concrete -> dynamic
void morpheus_ccl_convert_mat_coo_to_mat_dyn_serial(const ccl_mat_coo* src,
                                                    ccl_mat_dyn* dst);
void morpheus_ccl_convert_mat_csr_to_mat_dyn_serial(const ccl_mat_csr* src,
                                                    ccl_mat_dyn* dst);
void morpheus_ccl_convert_mat_dia_to_mat_dyn_serial(const ccl_mat_dia* src,
                                                    ccl_mat_dyn* dst);

// dynamic -> dynamic
void morpheus_ccl_convert_mat_dyn_to_mat_dyn_serial(const ccl_mat_dyn* src,
                                                    ccl_mat_dyn* dst);

// in-place conversions for dynamic
void morpheus_ccl_convert_mat_dyn_serial(ccl_mat_dyn* mat,
                                         const ccl_formats_e index);
void morpheus_ccl_convert_index_mat_dyn_serial(ccl_mat_dyn* mat,
                                               const int index);

// desne vec -> dense vec
void morpheus_ccl_convert_vec_dense_to_vec_dense_serial(
    const ccl_vec_dense* src, ccl_vec_dense* dst);
#ifdef __cplusplus
}
#endif

#endif  // MORPHEUS_CCL_CONVERT_HPP
