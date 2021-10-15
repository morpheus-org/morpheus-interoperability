/**
 * Morpheus_Ccl_Print.cpp
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

#include <Morpheus_Ccl_Print.hpp>

void morpheus_ccl_print_vec_dense(ccl_vec_dense* v) { Morpheus::print(*v); }

void morpheus_ccl_print_mat_coo(ccl_mat_coo* A) { Morpheus::print(*A); }

void morpheus_ccl_print_mat_csr(ccl_mat_csr* A) { Morpheus::print(*A); }

void morpheus_ccl_print_mat_dense(ccl_mat_dense* A) { Morpheus::print(*A); }

void morpheus_ccl_print_mat_dia(ccl_mat_dia* A) { Morpheus::print(*A); }

void morpheus_ccl_print_mat_dyn(ccl_mat_dyn* A) { Morpheus::print(*A); }
