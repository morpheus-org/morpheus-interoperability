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

#include <host/Morpheus_Ccl_Convert.hpp>

// coo -> coo
void morpheus_ccl_convert_hmat_coo_to_hmat_coo(const ccl_hmat_coo* src,
                                               ccl_hmat_coo* dst) {
  Morpheus::convert(*src, *dst);
}

// csr -> csr
void morpheus_ccl_convert_hmat_csr_to_hmat_csr(const ccl_hmat_csr* src,
                                               ccl_hmat_csr* dst) {
  Morpheus::convert(*src, *dst);
}
// csr -> coo
void morpheus_ccl_convert_hmat_csr_to_hmat_coo(const ccl_hmat_csr* src,
                                               ccl_hmat_coo* dst) {
  Morpheus::convert(*src, *dst);
}
// coo -> csr
void morpheus_ccl_convert_hmat_coo_to_hmat_csr(const ccl_hmat_coo* src,
                                               ccl_hmat_csr* dst) {
  Morpheus::convert(*src, *dst);
}
// csr -> dia
void morpheus_ccl_convert_hmat_csr_to_hmat_dia(const ccl_hmat_csr* src,
                                               ccl_hmat_dia* dst) {
  Morpheus::convert(*src, *dst);
}

// dia -> dia
void morpheus_ccl_convert_hmat_dia_to_hmat_dia(const ccl_hmat_dia* src,
                                               ccl_hmat_dia* dst) {
  Morpheus::convert(*src, *dst);
}
// dia -> coo
void morpheus_ccl_convert_hmat_dia_to_hmat_coo(const ccl_hmat_dia* src,
                                               ccl_hmat_coo* dst) {
  Morpheus::convert(*src, *dst);
}
// coo -> dia
void morpheus_ccl_convert_hmat_coo_to_hmat_dia(const ccl_hmat_coo* src,
                                               ccl_hmat_dia* dst) {
  Morpheus::convert(*src, *dst);
}
// dia -> csr
void morpheus_ccl_convert_hmat_dia_to_hmat_csr(const ccl_hmat_dia* src,
                                               ccl_hmat_csr* dst) {
  Morpheus::convert(*src, *dst);
}

// dense mat -> dense mat
void morpheus_ccl_convert_hmat_dense_to_hmat_dense(const ccl_hmat_dense* src,
                                                   ccl_hmat_dense* dst) {
  Morpheus::convert(*src, *dst);
}
// dense mat -> dense vec
void morpheus_ccl_convert_hmat_dense_to_hvec_dense(const ccl_hmat_dense* src,
                                                   ccl_hvec_dense* dst) {
  Morpheus::convert(*src, *dst);
}
// dense mat -> coo
void morpheus_ccl_convert_hmat_dense_to_hmat_coo(const ccl_hmat_dense* src,
                                                 ccl_hmat_coo* dst) {
  Morpheus::convert(*src, *dst);
}
// coo -> dense mat
void morpheus_ccl_convert_hmat_coo_to_hmat_dense(const ccl_hmat_coo* src,
                                                 ccl_hmat_dense* dst) {
  Morpheus::convert(*src, *dst);
}

// dynamic -> concrete
void morpheus_ccl_convert_hmat_dyn_to_hmat_coo(const ccl_hmat_dyn* src,
                                               ccl_hmat_coo* dst) {
  Morpheus::convert(*src, *dst);
}
void morpheus_ccl_convert_hmat_dyn_to_hmat_csr(const ccl_hmat_dyn* src,
                                               ccl_hmat_csr* dst) {
  Morpheus::convert(*src, *dst);
}
void morpheus_ccl_convert_hmat_dyn_to_hmat_dia(const ccl_hmat_dyn* src,
                                               ccl_hmat_dia* dst) {
  Morpheus::convert(*src, *dst);
}

// concrete -> dynamic
void morpheus_ccl_convert_hmat_coo_to_hmat_dyn(const ccl_hmat_coo* src,
                                               ccl_hmat_dyn* dst) {
  Morpheus::convert(*src, *dst);
}

void morpheus_ccl_convert_hmat_csr_to_hmat_dyn(const ccl_hmat_csr* src,
                                               ccl_hmat_dyn* dst) {
  Morpheus::convert(*src, *dst);
}

void morpheus_ccl_convert_hmat_dia_to_hmat_dyn(const ccl_hmat_dia* src,
                                               ccl_hmat_dyn* dst) {
  Morpheus::convert(*src, *dst);
}

// dynamic -> dynamic
void morpheus_ccl_convert_hmat_dyn_to_hmat_dyn(const ccl_hmat_dyn* src,
                                               ccl_hmat_dyn* dst) {
  Morpheus::convert(*src, *dst);
}

// in-place conversions for dynamic
void morpheus_ccl_convert_hmat_dyn(ccl_hmat_dyn* mat,
                                   const ccl_formats_e index) {
  Morpheus::convert(*mat, index);
}

void morpheus_ccl_convert_index_hmat_dyn(ccl_hmat_dyn* mat, const int index) {
  Morpheus::convert(*mat, index);
}

// desne vec -> dense vec
void morpheus_ccl_convert_hvec_dense_to_hvec_dense(const ccl_hvec_dense* src,
                                                   ccl_hvec_dense* dst) {
  Morpheus::convert(*src, *dst);
}
