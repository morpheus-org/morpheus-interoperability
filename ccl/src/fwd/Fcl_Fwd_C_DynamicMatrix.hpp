/**
 * Fcl_Fwd_C_DynamicMatrix.hpp
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

#ifndef FCL_FWD_C_DYNAMICMATRIX_HPP
#define FCL_FWD_C_DYNAMICMATRIX_HPP

#include "../Fcl_C_Types.hpp"

#ifdef __cplusplus
#include <Morpheus_Core.hpp>

typedef enum Morpheus::formats_e fcl_formats_e;

typedef Morpheus::DynamicMatrix<fcl_r64_t, fcl_i32_t, fcl_right_t, fcl_host_t>
    fcl_mat_dyn_r64_i32_r_h;
typedef typename fcl_mat_dyn_r64_i32_r_h::HostMirror
    fcl_mat_dyn_hostmirror_r64_i32_r_h;
#else
#include <Morpheus_FormatsRegistry.hpp>

typedef enum formats_e fcl_formats_e;

typedef struct Morpheus_DynamicMatrix_r64_i32_r_h fcl_mat_dyn_r64_i32_r_h;
typedef fcl_mat_dyn_r64_i32_r_h fcl_mat_dyn_hostmirror_r64_i32_r_h;
#endif

#endif  // FCL_FWD_C_DYNAMICMATRIX_HPP