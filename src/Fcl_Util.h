/**
 * Flc_Util.h
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

#ifndef FCL_UTIL_H
#define FCL_UTIL_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
void c_morpheus_initialize(int* argc, char** argv);
#else

#endif
void c_morpheus_initialize_without_args(void);
void c_morpheus_finalize(void);
void c_morpheus_print_configuration(const char* prepend_name_in,
                                    const char* file_name_in);

#ifdef __cplusplus
bool c_morpheus_is_initialized(void);
#else
_Bool c_morpheus_is_initialized(void);
#endif

#ifdef __cplusplus
}  // extern "C"
#endif

#endif  // FCL_UTIL_H