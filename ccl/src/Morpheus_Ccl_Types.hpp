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

#ifdef __cplusplus
#include <cstdint>
#else
#include <stddef.h>
#include <stdint.h>
#endif

typedef char fcl_char_t;

typedef int32_t fcl_i32_t;
typedef int64_t fcl_i64_t;

typedef float fcl_r32_t;
typedef double fcl_r64_t;

#ifdef __cplusplus
typedef bool fcl_bool_t;
typedef std::size_t fcl_index_t;
#else
typedef size_t fcl_index_t;
typedef _Bool fcl_bool_t;
#endif

#ifdef __cplusplus
#include <Morpheus_Core.hpp>
// Kokkos Types
typedef Kokkos::LayoutLeft fcl_left_t;
typedef Kokkos::LayoutRight fcl_right_t;

typedef Kokkos::Serial fcl_serial_t;
typedef Kokkos::HostSpace fcl_host_t;
#else
typedef struct LayoutLeft fcl_left_t;
typedef struct LayoutRight fcl_right_t;

typedef struct Serial fcl_serial_t;
typedef struct HostSpace fcl_host_t;
#endif

#endif  // MORPHEUS_CCL_TYPES_HPP