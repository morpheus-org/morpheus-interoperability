/**
 * Fcl_Cxx.hpp
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
#ifndef FCL_CXX_HPP
#define FCL_CXX_HPP

#include <Morpheus_Core.hpp>
#include "Fcl_Types.hpp"

namespace Morpheus {
namespace Fcl { 
 
 typedef Morpheus::CooMatrix<r64_t, i32_t, Kokkos::LayoutRight, Kokkos::HostSpace> coomat_r64_i32_r_h;
  
 extern "C"{
    void c_morpheus_allocate_coomat_dirh(Morpheus::Fcl::coomat_r64_i32_r_h** A, Morpheus::Fcl::i32_t nrows, Morpheus::Fcl::i32_t ncols, Morpheus::Fcl::i32_t nnnz);
    void c_morpheus_deallocate_coomat_dirh(Morpheus::Fcl::coomat_r64_i32_r_h** A);
    void c_morpheus_print_coomat_dirh(Morpheus::Fcl::coomat_r64_i32_r_h* A);
 }

//  typedef Morpheus::DynamicMatrix<r64_t, i32_t, Kokkos::LayoutRight, Kokkos::HostSpace> dynmat_r64_i32_r_h;
}}

#endif // FCL_CXX_HPP