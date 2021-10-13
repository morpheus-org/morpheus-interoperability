/**
 * Fcl_C_DynamicMatrix.cpp
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

#include "Fcl_C_DynamicMatrix.hpp"

void c_morpheus_create_default_mat_dyn_r64_i32_r_h(
    fcl_mat_dyn_r64_i32_r_h** A) {
  *A = (new fcl_mat_dyn_r64_i32_r_h());
}

void c_morpheus_create_mat_dyn_from_mat_r64_i32_r_h(
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

void c_morpheus_assign_mat_dyn_from_mat_r64_i32_r_h(
    void* src, fcl_formats_e index, fcl_mat_dyn_r64_i32_r_h* dst) {
  if (index == Morpheus::COO_FORMAT) {
    *dst = *(fcl_mat_coo_r64_i32_r_h*)src;
  } else if (index == Morpheus::CSR_FORMAT) {
    *dst = *(fcl_mat_csr_r64_i32_r_h*)src;
  } else if (index == Morpheus::DIA_FORMAT) {
    *dst = *(fcl_mat_dia_r64_i32_r_h*)src;
  }
}

void c_morpheus_assign_mat_dyn_from_mat_dia_r64_i32_r_h(
    fcl_mat_dia_r64_i32_r_h* src, fcl_mat_dyn_r64_i32_r_h* dst) {
  *dst = *src;
}

void c_morpheus_resize_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A,
                                           const fcl_i32_t num_rows,
                                           const fcl_i32_t num_cols,
                                           const fcl_i32_t num_nnz) {
  A->resize(num_rows, num_cols, num_nnz);
}

void c_morpheus_resize_diags_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A,
                                                 const fcl_i32_t num_rows,
                                                 const fcl_i32_t num_cols,
                                                 const fcl_i32_t num_nnz,
                                                 const fcl_i32_t num_diags) {
  A->resize(num_rows, num_cols, num_nnz, num_diags);
}

void c_morpheus_resize_aligned_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A,
                                                   const fcl_i32_t num_rows,
                                                   const fcl_i32_t num_cols,
                                                   const fcl_i32_t num_nnz,
                                                   const fcl_i32_t num_diags,
                                                   const fcl_i32_t alignment) {
  A->resize(num_rows, num_cols, num_nnz, num_diags, alignment);
}

void c_morpheus_allocate_mat_dyn_from_mat_dyn_r64_i32_r_h(
    fcl_mat_dyn_r64_i32_r_h* src, fcl_mat_dyn_r64_i32_r_h* dst) {
  dst->allocate("fcl_mat_dyn_r64_i32_r_h::allocate::", *src);
}

void c_morpheus_destroy_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h** A) {
  delete (*A);
}

fcl_i32_t c_morpheus_nrows_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A) {
  return A->nrows();
}

fcl_i32_t c_morpheus_ncols_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A) {
  return A->ncols();
}

fcl_i32_t c_morpheus_nnnz_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A) {
  return A->nnnz();
}

void c_morpheus_set_nrows_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A,
                                              fcl_i32_t nrows) {
  A->set_nrows(nrows);
}

void c_morpheus_set_ncols_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A,
                                              fcl_i32_t ncols) {
  A->set_ncols(ncols);
}

void c_morpheus_set_nnnz_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A,
                                             fcl_i32_t nnnz) {
  A->set_nnnz(nnnz);
}

void c_morpheus_activate_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A,
                                             const fcl_formats_e index) {
  A->activate(index);
}

void c_morpheus_activate_index_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A,
                                                   const int index) {
  A->activate(index);
}

int c_morpheus_active_index_mat_dyn_r64_i32_r_h(fcl_mat_dyn_r64_i32_r_h* A) {
  return A->active_index();
}

fcl_formats_e c_morpheus_active_enum_mat_dyn_r64_i32_r_h(
    fcl_mat_dyn_r64_i32_r_h* A) {
  return A->active_enum();
}

fcl_formats_e c_morpheus_format_enum_mat_dyn_r64_i32_r_h(
    fcl_mat_dyn_r64_i32_r_h* A) {
  return A->format_enum();
}