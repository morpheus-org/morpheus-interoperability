/**
 * Fcl_C_DenseVector.hpp
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

#ifndef FCL_C_DENSEVECTOR_HPP
#define FCL_C_DENSEVECTOR_HPP

#include <Morpheus_Core.hpp>

#include "Fcl_C_Types.hpp"

namespace Morpheus {
namespace Fcl {

typedef Morpheus::DenseVector<i32_t, i32_t, right_t, host_t> vec_r64_i32_r_h;

}
}  // namespace Morpheus

extern "C" {
void c_morpheus_create_vec_dirh(Morpheus::Fcl::vec_r64_i32_r_h** v,
                                Morpheus::Fcl::i32_t n,
                                Morpheus::Fcl::r64_t val);
void c_morpheus_create_vec_dirh_from_dirh(Morpheus::Fcl::vec_r64_i32_r_h* src,
                                          Morpheus::Fcl::vec_r64_i32_r_h** dst);
void c_morpheus_destroy_vec_dirh(Morpheus::Fcl::vec_r64_i32_r_h** v);
void c_morpheus_print_vec_dirh(Morpheus::Fcl::vec_r64_i32_r_h* v);
}

#endif  // FCL_C_DENSEVECTOR_HPP