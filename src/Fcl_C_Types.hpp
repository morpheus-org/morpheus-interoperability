/**
 * Flc_Types.hpp
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
#ifndef FCL_TYPES_HPP
#define FCL_TYPES_HPP

#include <cstdint>
#include <cstddef>

namespace Morpheus {
namespace Fcl {

typedef bool bool_t;

typedef int32_t i32_t;
typedef int64_t i64_t;

typedef float r32_t;
typedef double r64_t;

typedef std::size_t index_t;

// Kokkos Types
typedef Kokkos::LayoutLeft left_t;
typedef Kokkos::LayoutRight right_t;

typedef Kokkos::Serial serial_t;
typedef Kokkos::HostSpace host_t;

}  // namespace Fcl
}  // namespace Morpheus

#endif  // FCL_TYPES_HPP