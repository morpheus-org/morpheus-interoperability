/**
 * Morpheus_Ccl_Fwd_DenseVector.hpp
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

#ifndef MORPHEUS_CCL_FWD_DENSEVECTOR_HPP
#define MORPHEUS_CCL_FWD_DENSEVECTOR_HPP

#include <Morpheus_Ccl_Types.hpp>

#ifdef __cplusplus
#include <Morpheus_Core.hpp>

typedef Morpheus::DenseVector<ccl_value_t, ccl_index_t, ccl_layout_t,
                              ccl_host_t>
    ccl_hvec_dense_v;
typedef typename ccl_hvec_dense_v::HostMirror ccl_hvec_dense_v_hostmirror;

typedef Morpheus::DenseVector<ccl_index_t, ccl_index_t, ccl_layout_t,
                              ccl_host_t>
    ccl_hvec_dense_i;
typedef typename ccl_hvec_dense_i::HostMirror ccl_hvec_dense_i_hostmirror;
#else
typedef struct Morpheus_DenseVector_Host_v ccl_hvec_dense_v;
typedef ccl_hvec_dense_v ccl_hvec_dense_v_hostmirror;

typedef struct Morpheus_DenseVector_Host_i ccl_hvec_dense_i;
typedef ccl_hvec_dense_i ccl_hvec_dense_i_hostmirror;
#endif

#endif  // MORPHEUS_CCL_FWD_DENSEVECTOR_HPP
