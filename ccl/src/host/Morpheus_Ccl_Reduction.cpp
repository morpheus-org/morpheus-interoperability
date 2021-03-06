/**
 * Morpheus_Ccl_Reduction.cpp
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

#include <host/Morpheus_Ccl_Reduction.hpp>

ccl_value_t ccl_hvec_dense_v_reduce(const ccl_hvec_dense_v* in,
                                    ccl_index_t size) {
  return Morpheus::reduce<ccl_host_t>(*in, size);
}

ccl_value_t ccl_hvec_dense_i_reduce(const ccl_hvec_dense_i* in,
                                    ccl_index_t size) {
  return Morpheus::reduce<ccl_host_t>(*in, size);
}

ccl_value_t ccl_hvec_dense_v_hostmirror_reduce(
    const ccl_hvec_dense_v_hostmirror* in, ccl_index_t size) {
  return Morpheus::reduce<ccl_hostspace_t>(*in, size);
}

ccl_value_t ccl_hvec_dense_i_hostmirror_reduce(
    const ccl_hvec_dense_i_hostmirror* in, ccl_index_t size) {
  return Morpheus::reduce<ccl_hostspace_t>(*in, size);
}
