/**
 * Morpheus_Ccl_Fwd_CsrMatrix.hpp
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

#ifndef MORPHEUS_CCL_FWD_CSRMATRIX_HPP
#define MORPHEUS_CCL_FWD_CSRMATRIX_HPP

#include <Morpheus_Ccl_Types.hpp>

#ifdef __cplusplus
#include <Morpheus_Core.hpp>

typedef Morpheus::CsrMatrix<ccl_value_t, ccl_index_t, ccl_layout_t, ccl_host_t>
    ccl_mat_csr;
typedef typename ccl_mat_csr::HostMirror ccl_mat_csr_hostmirror;
#else
typedef struct Morpheus_CsrMatrix ccl_mat_csr;
typedef ccl_mat_csr ccl_mat_csr_hostmirror;
#endif

#endif  // MORPHEUS_CCL_FWD_CSRMATRIX_HPP
