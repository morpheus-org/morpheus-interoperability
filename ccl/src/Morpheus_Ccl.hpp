/**
 * Morpheus_Ccl.hpp
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

#ifndef MORPHEUS_CCL_HPP
#define MORPHEUS_CCL_HPP

#include <host/Morpheus_Ccl_Host.hpp>
#include <phost/Morpheus_Ccl_pHost.hpp>
#include <dev/Morpheus_Ccl_Dev.hpp>

#ifdef __cplusplus
extern "C" {
#endif

void ccl_initialize(int* argc, char** argv);
void ccl_initialize_without_args(void);
void ccl_finalize(void);
void ccl_print_configuration(const char* prepend_name_in,
                             const char* file_name_in);

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // MORPHEUS_CCL_HPP
