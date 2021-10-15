/**
 * Morpheus_Ccl_DynamicMatrix.cpp
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

#include <Morpheus_Ccl_DynamicMatrix.hpp>

void morpheus_ccl_create_default_mat_dyn_r64_i32_r_h(
    fcl_mat_dyn_r64_i32_r_h** A) {
  *A = (new fcl_mat_dyn_r64_i32_r_h());
}

void morpheus_ccl_create_mat_dyn_from_mat_r64_i32_r_h(
    void* src, fcl_formats_e index, fcl_mat_dyn_r64_i32_r_h** dst) {
  if (index == Morpheus::COO_FORMAT) {
    fcl_mat_coo_r64_i32_r_h* src_cast = (fcl_mat_coo_r64_i32_r_h*)src;
    *dst = new fcl_mat_dyn_r64_i32_r_h(fcl_mat_coo_r64_i32_r_h(*src_cast));
  } else if (index == Morpheus::CSR_FORMAT) {
    fcl_mat_csr_r64_i32_r_h* src_cast = (fcl_mat_csr_r64_i32_r_h*)src;
    *dst = new fcl_mat_dyn_r64_i32_r_h(fcl_mat_csr_r64_i32_r_h(*src_cast));
  } else if (index == Morpheus::DIA_FORMAT) {
    fcl_mat_dia_r64_i32_r_h* src_cast = (fcl_mat_dia_r64_i32_r_h*)src;
    *dst = new fcl_mat_dyn_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h(*src_cast));
  }
}

void morpheus_ccl_assign_mat_dyn_from_mat_r64_i32_r_h(
    void* src, fcl_formats_e index, fcl_mat_dyn_r64_i32_r_h* dst) {
  if (index == Morpheus::COO_FORMAT) {
    *dst = *(fcl_mat_coo_r64_i32_r_h*)src;
  } else if (index == Morpheus::CSR_FORMAT) {
    *dst = *(fcl_mat_csr_r64_i32_r_h*)src;
  } else if (index == Morpheus::DIA_FORMAT) {
    *dst = *(fcl_mat_dia_r64_i32_r_h*)src;
  }
}

void morpheus_ccl_assign_mat_dyn_from_mat_dia_r64_i32_r_h(
    fcl_mat_dia_r64_i32_r_h* src, fcl_mat_dyn_r64_i32_r_h* dst) {
  *dst = *src;
}

void morpheus_ccl_resize_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A,
                                             const ccl_index_t num_rows,
                                             const ccl_index_t num_cols,
                                             const ccl_index_t num_nnz) {
  A->resize(num_rows, num_cols, num_nnz);
}

void morpheus_ccl_resize_diags_mat_dyn_r64_i32_r_h(
    fcl_mat_dyn_r64_i32_r_h* A, const ccl_index_t num_rows,
    const ccl_index_t num_cols, const ccl_index_t num_nnz,
    const ccl_index_t num_diags) {
  A->resize(num_rows, num_cols, num_nnz, num_diags);
}

void morpheus_ccl_resize_aligned_mat_dyn_r64_i32_r_h(
    fcl_mat_dyn_r64_i32_r_h* A, const ccl_index_t num_rows,
    const ccl_index_t num_cols, const ccl_index_t num_nnz,
    const ccl_index_t num_diags, const ccl_index_t alignment) {
  A->resize(num_rows, num_cols, num_nnz, num_diags, alignment);
}

void morpheus_ccl_allocate_mat_dyn_from_mat_dyn_r64_i32_r_h(
    fcl_mat_dyn_r64_i32_r_h* src, fcl_mat_dyn_r64_i32_r_h* dst) {
  dst->allocate("fcl_mat_dyn_r64_i32_r_h::allocate::", *src);
}

void morpheus_ccl_destroy_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h** A) {
  delete (*A);
}

ccl_index_t morpheus_ccl_nrows_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A) {
  return A->nrows();
}

ccl_index_t morpheus_ccl_ncols_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A) {
  return A->ncols();
}

ccl_index_t morpheus_ccl_nnnz_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A) {
  return A->nnnz();
}

void morpheus_ccl_set_nrows_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A,
                                                ccl_index_t nrows) {
  A->set_nrows(nrows);
}

void morpheus_ccl_set_ncols_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A,
                                                ccl_index_t ncols) {
  A->set_ncols(ncols);
}

void morpheus_ccl_set_nnnz_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A,
                                               ccl_index_t nnnz) {
  A->set_nnnz(nnnz);
}

void morpheus_ccl_activate_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A,
                                               const fcl_formats_e index) {
  A->activate(index);
}

void morpheus_ccl_activate_index_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A,
                                                     const int index) {
  A->activate(index);
}

int morpheus_ccl_active_index_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A) {
  return A->active_index();
}

fcl_formats_e morpheus_ccl_active_enum_mat_dyn_r64_i32_r_h(
    fcl_mat_dyn_r64_i32_r_h* A) {
  return A->active_enum();
}

fcl_formats_e morpheus_ccl_format_enum_mat_dyn_r64_i32_r_h(
    fcl_mat_dyn_r64_i32_r_h* A) {
  return A->format_enum();
}
