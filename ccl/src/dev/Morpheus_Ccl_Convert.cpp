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

#include <dev/Morpheus_Ccl_Convert.hpp>

// coo -> coo
void ccl_dmat_coo_hostmirror_convert_to_dmat_coo_hostmirror(
    const ccl_dmat_coo_hostmirror* src, ccl_dmat_coo_hostmirror* dst) {
  Morpheus::convert(*src, *dst);
}

// csr -> csr
void ccl_dmat_csr_hostmirror_convert_to_dmat_csr_hostmirror(
    const ccl_dmat_csr_hostmirror* src, ccl_dmat_csr_hostmirror* dst) {
  Morpheus::convert(*src, *dst);
}
// csr -> coo
void ccl_dmat_csr_hostmirror_convert_to_dmat_coo_hostmirror(
    const ccl_dmat_csr_hostmirror* src, ccl_dmat_coo_hostmirror* dst) {
  Morpheus::convert(*src, *dst);
}
// coo -> csr
void ccl_dmat_coo_hostmirror_convert_to_dmat_csr_hostmirror(
    const ccl_dmat_coo_hostmirror* src, ccl_dmat_csr_hostmirror* dst) {
  Morpheus::convert(*src, *dst);
}
// csr -> dia
void ccl_dmat_csr_hostmirror_convert_to_dmat_dia_hostmirror(
    const ccl_dmat_csr_hostmirror* src, ccl_dmat_dia_hostmirror* dst) {
  Morpheus::convert(*src, *dst);
}

// dia -> dia
void ccl_dmat_dia_hostmirror_convert_to_dmat_dia_hostmirror(
    const ccl_dmat_dia_hostmirror* src, ccl_dmat_dia_hostmirror* dst) {
  Morpheus::convert(*src, *dst);
}
// dia -> coo
void ccl_dmat_dia_hostmirror_convert_to_dmat_coo_hostmirror(
    const ccl_dmat_dia_hostmirror* src, ccl_dmat_coo_hostmirror* dst) {
  Morpheus::convert(*src, *dst);
}
// coo -> dia
void ccl_dmat_coo_hostmirror_convert_to_dmat_dia_hostmirror(
    const ccl_dmat_coo_hostmirror* src, ccl_dmat_dia_hostmirror* dst) {
  Morpheus::convert(*src, *dst);
}
// dia -> csr
void ccl_dmat_dia_hostmirror_convert_to_dmat_csr_hostmirror(
    const ccl_dmat_dia_hostmirror* src, ccl_dmat_csr_hostmirror* dst) {
  Morpheus::convert(*src, *dst);
}

// dense mat -> dense mat
void ccl_dmat_dense_hostmirror_convert_to_dmat_dense_hostmirror(
    const ccl_dmat_dense_hostmirror* src, ccl_dmat_dense_hostmirror* dst) {
  Morpheus::convert(*src, *dst);
}
// dense mat -> dense vec
void ccl_dmat_dense_hostmirror_convert_to_dvec_dense_v_hostmirror(
    const ccl_dmat_dense_hostmirror* src, ccl_dvec_dense_v_hostmirror* dst) {
  Morpheus::convert(*src, *dst);
}
// dense mat -> coo
void ccl_dmat_dense_hostmirror_convert_to_dmat_coo_hostmirror(
    const ccl_dmat_dense_hostmirror* src, ccl_dmat_coo_hostmirror* dst) {
  Morpheus::convert(*src, *dst);
}
// coo -> dense mat
void ccl_dmat_coo_hostmirror_convert_to_dmat_dense(
    const ccl_dmat_coo_hostmirror* src, ccl_dmat_dense* dst) {
  Morpheus::convert(*src, *dst);
}

// dynamic -> concrete
void ccl_dmat_dyn_hostmirror_convert_to_dmat_coo_hostmirror(
    const ccl_dmat_dyn_hostmirror* src, ccl_dmat_coo_hostmirror* dst) {
  Morpheus::convert(*src, *dst);
}
void ccl_dmat_dyn_hostmirror_convert_to_dmat_csr_hostmirror(
    const ccl_dmat_dyn_hostmirror* src, ccl_dmat_csr_hostmirror* dst) {
  Morpheus::convert(*src, *dst);
}
void ccl_dmat_dyn_hostmirror_convert_to_dmat_dia_hostmirror(
    const ccl_dmat_dyn_hostmirror* src, ccl_dmat_dia_hostmirror* dst) {
  Morpheus::convert(*src, *dst);
}

// concrete -> dynamic
void ccl_dmat_coo_hostmirror_convert_to_dmat_dyn_hostmirror(
    const ccl_dmat_coo_hostmirror* src, ccl_dmat_dyn_hostmirror* dst) {
  Morpheus::convert(*src, *dst);
}

void ccl_dmat_csr_hostmirror_convert_to_dmat_dyn_hostmirror(
    const ccl_dmat_csr_hostmirror* src, ccl_dmat_dyn_hostmirror* dst) {
  Morpheus::convert(*src, *dst);
}

void ccl_dmat_dia_hostmirror_convert_to_dmat_dyn_hostmirror(
    const ccl_dmat_dia_hostmirror* src, ccl_dmat_dyn_hostmirror* dst) {
  Morpheus::convert(*src, *dst);
}

// dynamic -> dynamic
void ccl_dmat_dyn_hostmirror_convert_to_dmat_dyn_hostmirror(
    const ccl_dmat_dyn_hostmirror* src, ccl_dmat_dyn_hostmirror* dst) {
  Morpheus::convert(*src, *dst);
}

// in-place conversions for dynamic
void ccl_dmat_dyn_hostmirror_convert(ccl_dmat_dyn_hostmirror* mat,
                                     const ccl_formats_e index) {
  Morpheus::convert(*mat, index);
}

void ccl_dmat_dyn_hostmirror_convert_index(ccl_dmat_dyn_hostmirror* mat,
                                           const int index) {
  Morpheus::convert(*mat, index);
}

// desne vec -> dense vec
void ccl_dvec_dense_v_hostmirror_convert_to_dvec_dense_v_hostmirror(
    const ccl_dvec_dense_v_hostmirror* src, ccl_dvec_dense_v_hostmirror* dst) {
  Morpheus::convert(*src, *dst);
}
