/**
 * Morpheus_Ccl_Dot.cpp
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

#include <dev/Morpheus_Ccl_Dot.hpp>

ccl_value_t ccl_dvec_dense_v_dot(ccl_index_t n, const ccl_dvec_dense_v* x,
                                 const ccl_dvec_dense_v* y) {
  return Morpheus::dot<ccl_dev_t>(n, *x, *y);
}

ccl_value_t ccl_dvec_dense_i_dot(ccl_index_t n, const ccl_dvec_dense_i* x,
                                 const ccl_dvec_dense_i* y) {
  return Morpheus::dot<ccl_dev_t>(n, *x, *y);
}

ccl_value_t ccl_dvec_dense_v_hostmirror_dot(
    ccl_index_t n, const ccl_dvec_dense_v_hostmirror* x,
    const ccl_dvec_dense_v_hostmirror* y) {
  return Morpheus::dot<ccl_hostspace_t>(n, *x, *y);
}

ccl_value_t ccl_dvec_dense_i_hostmirror_dot(
    ccl_index_t n, const ccl_dvec_dense_i_hostmirror* x,
    const ccl_dvec_dense_i_hostmirror* y) {
  return Morpheus::dot<ccl_hostspace_t>(n, *x, *y);
}
