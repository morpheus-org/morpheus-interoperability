/**
 * Fcl_C_DynamicMatrix.hpp
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

#ifndef FCL_C_DYNAMICMATRIX_HPP
#define FCL_C_DYNAMICMATRIX_HPP

#include <Morpheus_Core.hpp>

#include "Fcl_C_Types.hpp"
#include "Fcl_C_CooMatrix.hpp"
#include "Fcl_C_DenseVector.hpp"

namespace Morpheus {
namespace Fcl { 
 
 typedef Morpheus::DynamicMatrix<r64_t, i32_t, right_t, host_t> dynmat_r64_i32_r_h;

}
}

extern "C" {
    void c_morpheus_create_dynmat_dirh_from_coomat_dirh(Morpheus::Fcl::coomat_r64_i32_r_h* src, Morpheus::Fcl::dynmat_r64_i32_r_h** dst);
    void c_morpheus_destroy_dynmat_dirh(Morpheus::Fcl::dynmat_r64_i32_r_h** A);
    void c_morpheus_print_dynmat_dirh(Morpheus::Fcl::dynmat_r64_i32_r_h* A);
    void c_morpheus_dynmat_dirh_activate(Morpheus::Fcl::dynmat_r64_i32_r_h* A, const Morpheus::formats_e index);

    void c_morpheus_multiply_dyn_vec_vec_dirh_serial(Morpheus::Fcl::dynmat_r64_i32_r_h *A, Morpheus::Fcl::vec_r64_i32_r_h *x, Morpheus::Fcl::vec_r64_i32_r_h *y);
}


#endif // FCL_C_DYNAMICMATRIX_HPP