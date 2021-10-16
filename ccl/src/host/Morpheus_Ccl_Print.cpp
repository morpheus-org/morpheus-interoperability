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

#include <host/Morpheus_Ccl_Print.hpp>

void ccl_hvec_dense_v_print(ccl_hvec_dense_v* v) { Morpheus::print(*v); }

void ccl_hmat_coo_print(ccl_hmat_coo* A) { Morpheus::print(*A); }

void ccl_hmat_csr_print(ccl_hmat_csr* A) { Morpheus::print(*A); }

void ccl_hmat_dense_print(ccl_hmat_dense* A) { Morpheus::print(*A); }

void ccl_hmat_dia_print(ccl_hmat_dia* A) { Morpheus::print(*A); }

void ccl_hmat_dyn_print(ccl_hmat_dyn* A) { Morpheus::print(*A); }
