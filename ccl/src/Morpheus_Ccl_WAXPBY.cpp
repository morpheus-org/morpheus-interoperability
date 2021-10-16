/**
 * Morpheus_Ccl_WAXPBY.cpp
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

#include <Morpheus_Ccl_WAXPBY.hpp>

void morpheus_ccl_waxpby_hvec_dense_hvec_dense(ccl_index_t n, ccl_value_t alpha,
                                               const ccl_hvec_dense* x,
                                               ccl_value_t beta,
                                               const ccl_hvec_dense* y,
                                               ccl_hvec_dense* w) {
  Morpheus::waxpby<ccl_host_t>(n, alpha, *x, beta, *y, *w);
}
