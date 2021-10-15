/**
 * Morpheus_Ccl_Types.hpp
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

#ifndef MORPHEUS_CCL_TYPES_HPP
#define MORPHEUS_CCL_TYPES_HPP

#include <Morpheus_Ccl_Macros.hpp>

#ifdef __cplusplus
#include <cstdint>
#else
#include <stddef.h>
#include <stdint.h>
#endif

typedef Mcl_VALUETYPE ccl_value_t;
typedef Mcl_INDEXTYPE ccl_index_t;

#ifdef __cplusplus
typedef bool ccl_bool_t;
typedef std::size_t ccl_size_t;
#else
typedef size_t ccl_size_t;
typedef _Bool ccl_bool_t;
#endif

typedef char ccl_char_t;

#ifdef __cplusplus
#include <Morpheus_Core.hpp>
// Kokkos Types
typedef Mcl_LAYOUT ccl_layout_t;

#if defined MORPHEUS_ENABLE_SERIAL
typedef Kokkos::Serial ccl_host_t;
#endif  // MORPHEUS_ENABLE_SERIAL

#if defined MORPHEUS_ENABLE_OPENMP
typedef Kokkos::OpenMP ccl_phost_t;
#endif  // MORPHEUS_ENABLE_OPENMP

#if defined MORPHEUS_ENABLE_CUDA
typedef Kokkos::Cuda ccl_dev_t;
#endif  // MORPHEUS_ENABLE_CUDA
#else
typedef struct Ccl_Layout ccl_layout_t;

#if defined MORPHEUS_ENABLE_SERIAL
typedef struct Ccl_Host ccl_host_t;
#endif  // MORPHEUS_ENABLE_SERIAL

#if defined MORPHEUS_ENABLE_OPENMP
typedef struct Ccl_pHost ccl_phost_t;
#endif  // MORPHEUS_ENABLE_OPENMP

#if defined MORPHEUS_ENABLE_CUDA
typedef struct Ccl_Device ccl_dev_t;
#endif  // MORPHEUS_ENABLE_CUDA
#endif  //__cplusplus

#endif  // MORPHEUS_CCL_TYPES_HPP
