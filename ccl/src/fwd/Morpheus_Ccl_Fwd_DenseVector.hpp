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

#if defined MORPHEUS_ENABLE_SERIAL
typedef Morpheus::DenseVector<ccl_value_t, ccl_index_t, ccl_layout_t,
                              ccl_host_t>
    ccl_hvec_dense_v;
typedef typename ccl_hvec_dense_v::HostMirror ccl_hvec_dense_v_hostmirror;

typedef Morpheus::DenseVector<ccl_index_t, ccl_index_t, ccl_layout_t,
                              ccl_host_t>
    ccl_hvec_dense_i;
typedef typename ccl_hvec_dense_i::HostMirror ccl_hvec_dense_i_hostmirror;
#endif  // MORPHEUS_ENABLE_SERIAL

#if defined MORPHEUS_ENABLE_OPENMP
typedef Morpheus::DenseVector<ccl_value_t, ccl_index_t, ccl_layout_t,
                              ccl_phost_t>
    ccl_phvec_dense_v;
typedef typename ccl_phvec_dense_v::HostMirror ccl_phvec_dense_v_hostmirror;

typedef Morpheus::DenseVector<ccl_index_t, ccl_index_t, ccl_layout_t,
                              ccl_phost_t>
    ccl_phvec_dense_i;
typedef typename ccl_phvec_dense_i::HostMirror ccl_phvec_dense_i_hostmirror;
#endif  // MORPHEUS_ENABLE_OPENMP

#if defined MORPHEUS_ENABLE_CUDA
typedef Morpheus::DenseVector<ccl_value_t, ccl_index_t, ccl_layout_t, ccl_dev_t>
    ccl_dvec_dense_v;
typedef typename ccl_dvec_dense_v::HostMirror ccl_dvec_dense_v_hostmirror;

typedef Morpheus::DenseVector<ccl_index_t, ccl_index_t, ccl_layout_t, ccl_dev_t>
    ccl_dvec_dense_i;
typedef typename ccl_dvec_dense_i::HostMirror ccl_dvec_dense_i_hostmirror;
#endif  // MORPHEUS_ENABLE_CUDA
#else
#if defined MCL_ENABLE_SERIAL
typedef struct Morpheus_DenseVector_v_Host ccl_hvec_dense_v;
typedef struct Morpheus_DenseVector_v_Host_HostMirror
    ccl_hvec_dense_v_hostmirror;

typedef struct Morpheus_DenseVector_i_Host ccl_hvec_dense_i;
typedef struct Morpheus_DenseVector_i_Host_HostMirror
    ccl_hvec_dense_i_hostmirror;
#endif  // MCL_ENABLE_SERIAL

#if defined MCL_ENABLE_OPENMP
typedef struct Morpheus_DenseVector_v_pHost ccl_phvec_dense_v;
typedef struct Morpheus_DenseVector_v_pHost_HostMirror
    ccl_phvec_dense_v_hostmirror;

typedef struct Morpheus_DenseVector_i_pHost ccl_phvec_dense_i;
typedef struct Morpheus_DenseVector_i_pHost_HostMirror
    ccl_phvec_dense_i_hostmirror;
#endif  // MCL_ENABLE_OPENMP

#if defined MCL_ENABLE_CUDA
typedef struct Morpheus_DenseVector_v_Dev ccl_dvec_dense_v;
typedef struct Morpheus_DenseVector_v_Dev_HostMirror
    ccl_dvec_dense_v_hostmirror;

typedef struct Morpheus_DenseVector_i_Dev ccl_dvec_dense_i;
typedef struct Morpheus_DenseVector_i_Dev_HostMirror
    ccl_dvec_dense_i_hostmirror;
#endif  // MCL_ENABLE_CUDA
#endif  // __cplusplus

#endif  // MORPHEUS_CCL_FWD_DENSEVECTOR_HPP
