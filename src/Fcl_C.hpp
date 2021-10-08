/**
 * Fcl_C.hpp
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

#ifndef FCL_C_HPP
#define FCL_C_HPP

#include "Fcl_C_CooMatrix.hpp"
#include "Fcl_C_CsrMatrix.hpp"
#include "Fcl_C_DiaMatrix.hpp"
#include "Fcl_C_DenseVector.hpp"
#include "Fcl_C_DynamicMatrix.hpp"

#include "Fcl_C_MirrorContainers.hpp"

#include "Fcl_C_Convert.hpp"
#include "Fcl_C_Dot.hpp"
#include "Fcl_C_Multiply.hpp"
#include "Fcl_C_Print.hpp"
#include "Fcl_C_Reduction.hpp"
#include "Fcl_C_Scan.hpp"
#include "Fcl_C_WAXPBY.hpp"

#ifdef __cplusplus
extern "C" {
#endif

void c_morpheus_initialize(int* argc, char** argv);
void c_morpheus_initialize_without_args(void);
void c_morpheus_finalize(void);
void c_morpheus_print_configuration(const char* prepend_name_in,
                                    const char* file_name_in);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // FCL_C_HPP