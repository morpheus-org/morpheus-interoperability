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

#include <dev/Morpheus_Ccl_Print.hpp>

void ccl_dvec_dense_v_hostmirror_print(ccl_dvec_dense_v_hostmirror* v) {
  Morpheus::print(*v);
}

void ccl_dmat_coo_hostmirror_print(ccl_dmat_coo_hostmirror* A) {
  Morpheus::print(*A);
}

void ccl_dmat_csr_hostmirror_print(ccl_dmat_csr_hostmirror* A) {
  Morpheus::print(*A);
}

void ccl_dmat_dense_hostmirror_print(ccl_dmat_dense_hostmirror* A) {
  Morpheus::print(*A);
}

void ccl_dmat_dia_hostmirror_print(ccl_dmat_dia_hostmirror* A) {
  Morpheus::print(*A);
}

void ccl_dmat_dyn_hostmirror_print(ccl_dmat_dyn_hostmirror* A) {
  Morpheus::print(*A);
}
