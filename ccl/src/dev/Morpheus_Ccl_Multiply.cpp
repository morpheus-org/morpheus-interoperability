/**
 * Morpheus_Ccl_Multiply.cpp
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

#include <dev/Morpheus_Ccl_Multiply.hpp>

void ccl_dmat_coo_dvec_dense_v_multiply(ccl_dmat_coo* A, ccl_dvec_dense_v* x,
                                        ccl_dvec_dense_v* y) {
  Morpheus::multiply<ccl_dev_t>(*A, *x, *y);
}

void ccl_dmat_csr_dvec_dense_v_multiply(ccl_dmat_csr* A, ccl_dvec_dense_v* x,
                                        ccl_dvec_dense_v* y) {
  Morpheus::multiply<ccl_dev_t>(*A, *x, *y);
}

void ccl_dmat_dia_dvec_dense_v_multiply(ccl_dmat_dia* A, ccl_dvec_dense_v* x,
                                        ccl_dvec_dense_v* y) {
  Morpheus::multiply<ccl_dev_t>(*A, *x, *y);
}

void ccl_dmat_dyn_dvec_dense_v_multiply(ccl_dmat_dyn* A, ccl_dvec_dense_v* x,
                                        ccl_dvec_dense_v* y) {
  Morpheus::multiply<ccl_dev_t>(*A, *x, *y);
}

void ccl_dmat_coo_hostmirror_dvec_dense_v_hostmirror_multiply(
    ccl_dmat_coo_hostmirror* A, ccl_dvec_dense_v_hostmirror* x,
    ccl_dvec_dense_v_hostmirror* y) {
  Morpheus::multiply<ccl_hostspace_t>(*A, *x, *y);
}

void ccl_dmat_csr_hostmirror_dvec_dense_v_hostmirror_multiply(
    ccl_dmat_csr_hostmirror* A, ccl_dvec_dense_v_hostmirror* x,
    ccl_dvec_dense_v_hostmirror* y) {
  Morpheus::multiply<ccl_hostspace_t>(*A, *x, *y);
}

void ccl_dmat_dia_hostmirror_dvec_dense_v_hostmirror_multiply(
    ccl_dmat_dia_hostmirror* A, ccl_dvec_dense_v_hostmirror* x,
    ccl_dvec_dense_v_hostmirror* y) {
  Morpheus::multiply<ccl_hostspace_t>(*A, *x, *y);
}

void ccl_dmat_dyn_hostmirror_dvec_dense_v_hostmirror_multiply(
    ccl_dmat_dyn_hostmirror* A, ccl_dvec_dense_v_hostmirror* x,
    ccl_dvec_dense_v_hostmirror* y) {
  Morpheus::multiply<ccl_hostspace_t>(*A, *x, *y);
}
