/**
 * Morpheus_Ccl_Print.hpp
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

#ifndef MORPHEUS_CCL_PHOST_PRINT_HPP
#define MORPHEUS_CCL_PHOST_PRINT_HPP

#include <phost/Morpheus_Ccl_CooMatrix.hpp>
#include <phost/Morpheus_Ccl_CsrMatrix.hpp>
#include <phost/Morpheus_Ccl_DenseMatrix.hpp>
#include <phost/Morpheus_Ccl_DiaMatrix.hpp>
#include <phost/Morpheus_Ccl_DynamicMatrix.hpp>
#include <phost/Morpheus_Ccl_DenseVector.hpp>

#ifdef __cplusplus
extern "C" {
#endif

void ccl_phvec_dense_v_print(ccl_phvec_dense_v* v);

void ccl_phmat_coo_print(ccl_phmat_coo* A);

void ccl_phmat_csr_print(ccl_phmat_csr* A);

void ccl_phmat_dense_print(ccl_phmat_dense* A);

void ccl_phmat_dia_print(ccl_phmat_dia* A);

void ccl_phmat_dyn_print(ccl_phmat_dyn* A);

#ifdef __cplusplus
}
#endif

#endif  // MORPHEUS_CCL_PHOST_PRINT_HPP
