/**
 * Morpheus_Ccl_Convert.cpp
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

#include <phost/Morpheus_Ccl_Convert.hpp>

// coo -> coo
void ccl_phmat_coo_convert_to_phmat_coo(const ccl_phmat_coo* src,
                                        ccl_phmat_coo* dst) {
  Morpheus::convert(*src, *dst);
}

// csr -> csr
void ccl_phmat_csr_convert_to_phmat_csr(const ccl_phmat_csr* src,
                                        ccl_phmat_csr* dst) {
  Morpheus::convert(*src, *dst);
}
// csr -> coo
void ccl_phmat_csr_convert_to_phmat_coo(const ccl_phmat_csr* src,
                                        ccl_phmat_coo* dst) {
  Morpheus::convert(*src, *dst);
}
// coo -> csr
void ccl_phmat_coo_convert_to_phmat_csr(const ccl_phmat_coo* src,
                                        ccl_phmat_csr* dst) {
  Morpheus::convert(*src, *dst);
}
// csr -> dia
void ccl_phmat_csr_convert_to_phmat_dia(const ccl_phmat_csr* src,
                                        ccl_phmat_dia* dst) {
  Morpheus::convert(*src, *dst);
}

// dia -> dia
void ccl_phmat_dia_convert_to_phmat_dia(const ccl_phmat_dia* src,
                                        ccl_phmat_dia* dst) {
  Morpheus::convert(*src, *dst);
}
// dia -> coo
void ccl_phmat_dia_convert_to_phmat_coo(const ccl_phmat_dia* src,
                                        ccl_phmat_coo* dst) {
  Morpheus::convert(*src, *dst);
}
// coo -> dia
void ccl_phmat_coo_convert_to_phmat_dia(const ccl_phmat_coo* src,
                                        ccl_phmat_dia* dst) {
  Morpheus::convert(*src, *dst);
}
// dia -> csr
void ccl_phmat_dia_convert_to_phmat_csr(const ccl_phmat_dia* src,
                                        ccl_phmat_csr* dst) {
  Morpheus::convert(*src, *dst);
}

// dense mat -> dense mat
void ccl_phmat_dense_convert_to_phmat_dense(const ccl_phmat_dense* src,
                                            ccl_phmat_dense* dst) {
  Morpheus::convert(*src, *dst);
}
// dense mat -> dense vec
void ccl_phmat_dense_convert_to_phvec_dense_v(const ccl_phmat_dense* src,
                                              ccl_phvec_dense_v* dst) {
  Morpheus::convert(*src, *dst);
}
// dense mat -> coo
void ccl_phmat_dense_convert_to_phmat_coo(const ccl_phmat_dense* src,
                                          ccl_phmat_coo* dst) {
  Morpheus::convert(*src, *dst);
}
// coo -> dense mat
void ccl_phmat_coo_convert_to_phmat_dense(const ccl_phmat_coo* src,
                                          ccl_phmat_dense* dst) {
  Morpheus::convert(*src, *dst);
}

// dynamic -> concrete
void ccl_phmat_dyn_convert_to_phmat_coo(const ccl_phmat_dyn* src,
                                        ccl_phmat_coo* dst) {
  Morpheus::convert(*src, *dst);
}
void ccl_phmat_dyn_convert_to_phmat_csr(const ccl_phmat_dyn* src,
                                        ccl_phmat_csr* dst) {
  Morpheus::convert(*src, *dst);
}
void ccl_phmat_dyn_convert_to_phmat_dia(const ccl_phmat_dyn* src,
                                        ccl_phmat_dia* dst) {
  Morpheus::convert(*src, *dst);
}

// concrete -> dynamic
void ccl_phmat_coo_convert_to_phmat_dyn(const ccl_phmat_coo* src,
                                        ccl_phmat_dyn* dst) {
  Morpheus::convert(*src, *dst);
}

void ccl_phmat_csr_convert_to_phmat_dyn(const ccl_phmat_csr* src,
                                        ccl_phmat_dyn* dst) {
  Morpheus::convert(*src, *dst);
}

void ccl_phmat_dia_convert_to_phmat_dyn(const ccl_phmat_dia* src,
                                        ccl_phmat_dyn* dst) {
  Morpheus::convert(*src, *dst);
}

// dynamic -> dynamic
void ccl_phmat_dyn_convert_to_phmat_dyn(const ccl_phmat_dyn* src,
                                        ccl_phmat_dyn* dst) {
  Morpheus::convert(*src, *dst);
}

// in-place conversions for dynamic
void ccl_phmat_dyn_convert(ccl_phmat_dyn* mat, const ccl_formats_e index) {
  Morpheus::convert(*mat, index);
}

void ccl_phmat_dyn_convert_index(ccl_phmat_dyn* mat, const int index) {
  Morpheus::convert(*mat, index);
}

// desne vec -> dense vec
void ccl_phvec_dense_v_convert_to_phvec_dense_v(const ccl_phvec_dense_v* src,
                                                ccl_phvec_dense_v* dst) {
  Morpheus::convert(*src, *dst);
}
