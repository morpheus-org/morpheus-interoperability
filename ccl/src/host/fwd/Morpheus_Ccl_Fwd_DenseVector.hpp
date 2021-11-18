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

#ifndef MORPHEUS_CCL_HOST_FWD_DENSEVECTOR_HPP
#define MORPHEUS_CCL_HOST_FWD_DENSEVECTOR_HPP

#include <Morpheus_Ccl_Types.hpp>

#if defined MCL_ENABLE_SERIAL

#ifdef __cplusplus
#include <Morpheus_Core.hpp>

typedef typename Morpheus::DenseVector<ccl_value_t, ccl_index_t, ccl_layout_t,
                                       ccl_host_t>::type ccl_hvec_dense_v;
typedef typename ccl_hvec_dense_v::HostMirror ccl_hvec_dense_v_hostmirror;

typedef typename Morpheus::DenseVector<ccl_index_t, ccl_index_t, ccl_layout_t,
                                       ccl_host_t>::type ccl_hvec_dense_i;
typedef typename ccl_hvec_dense_i::HostMirror ccl_hvec_dense_i_hostmirror;
#else

typedef struct Morpheus_DenseVector_v_Host ccl_hvec_dense_v;
typedef struct Morpheus_DenseVector_v_Host_HostMirror
    ccl_hvec_dense_v_hostmirror;

typedef struct Morpheus_DenseVector_i_Host ccl_hvec_dense_i;
typedef struct Morpheus_DenseVector_i_Host_HostMirror
    ccl_hvec_dense_i_hostmirror;
#endif  // __cplusplus

#endif  // MCL_ENABLE_SERIAL

#endif  // MORPHEUS_CCL_HOST_FWD_DENSEVECTOR_HPP
