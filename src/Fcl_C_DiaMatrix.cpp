/**
 * Fcl_C_DiaMatrix.cpp
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

#include "Fcl_C_DiaMatrix.hpp"

void c_morpheus_create_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h** A,
                                           fcl_i32_t nrows, fcl_i32_t ncols,
                                           fcl_i32_t nnnz, fcl_i32_t ndiags) {
  *A = (new fcl_mat_dia_r64_i32_r_h("fcl_mat_dia_r64_i32_r_h::", nrows, ncols,
                                    nnnz, ndiags));
}

void c_morpheus_create_aligned_mat_dia_r64_i32_r_h(
    fcl_mat_dia_r64_i32_r_h** A, fcl_i32_t nrows, fcl_i32_t ncols,
    fcl_i32_t nnnz, fcl_i32_t ndiags, fcl_i32_t alginment) {
  *A = (new fcl_mat_dia_r64_i32_r_h("fcl_mat_dia_r64_i32_r_h::", nrows, ncols,
                                    nnnz, ndiags, alginment));
}

void c_morpheus_create_mat_dia_from_mat_dia_r64_i32_r_h(
    fcl_mat_dia_r64_i32_r_h* src, fcl_mat_dia_r64_i32_r_h** dst) {
  *dst = (new fcl_mat_dia_r64_i32_r_h(*src));
}

void c_morpheus_create_mat_dia_from_mat_dyn_r64_i32_r_h(
    fcl_mat_dyn_r64_i32_r_h* src, fcl_mat_dia_r64_i32_r_h** dst) {
  *dst = (new fcl_mat_dia_r64_i32_r_h(*src));
}

void c_morpheus_resize_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A,
                                           const fcl_i32_t num_rows,
                                           const fcl_i32_t num_cols,
                                           const fcl_i32_t num_nnz,
                                           const fcl_i32_t num_diagonals) {
  A->resize(num_rows, num_cols, num_nnz, num_diagonals);
}

void c_morpheus_resize_aligned_mat_dia_r64_i32_r_h(
    fcl_mat_dia_r64_i32_r_h* A, const fcl_i32_t num_rows,
    const fcl_i32_t num_cols, const fcl_i32_t num_nnz,
    const fcl_i32_t num_diagonals, const fcl_i32_t alginment) {
  A->resize(num_rows, num_cols, num_nnz, num_diagonals, alginment);
}

// Assumes dst matrix is always created
void c_morpheus_allocate_mat_dia_from_mat_dia_r64_i32_r_h(
    fcl_mat_dia_r64_i32_r_h* src, fcl_mat_dia_r64_i32_r_h* dst) {
  dst->allocate("fcl_mat_dia_r64_i32_r_h::allocate::", *src);
}

void c_morpheus_destroy_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h** A) {
  delete (*A);
}

fcl_i32_t c_morpheus_nrows_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A) {
  return A->nrows();
}

fcl_i32_t c_morpheus_ncols_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A) {
  return A->ncols();
}

fcl_i32_t c_morpheus_nnnz_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A) {
  return A->nnnz();
}

fcl_i32_t c_morpheus_ndiags_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A) {
  // TODO: MorpheusCore:: Convert that into proper function
  return A->ndiags;
}

fcl_i32_t c_morpheus_alignment_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A) {
  // TODO: MorpheusCore:: Convert that into proper function
  return A->nalign;
}

void c_morpheus_set_nrows_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A,
                                              fcl_i32_t nrows) {
  A->set_nrows(nrows);
}

void c_morpheus_set_ncols_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A,
                                              fcl_i32_t ncols) {
  A->set_ncols(ncols);
}

void c_morpheus_set_nnnz_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A,
                                             fcl_i32_t nnnz) {
  A->set_nnnz(nnnz);
}

void c_morpheus_set_ndiags_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A,
                                               fcl_i32_t ndiags) {
  // TODO: MorpheusCore:: Convert that into proper function
  A->ndiags = ndiags;
}

void c_morpheus_set_alignment_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A,
                                                  fcl_i32_t alignment) {
  // TODO: MorpheusCore:: Convert that into proper function
  A->nalign = alignment;
}

fcl_i32_t c_morpheus_diagonal_offests_at_dia_r64_i32_r_h(
    fcl_mat_dia_r64_i32_r_h* A, fcl_i32_t i) {
  return A->diagonal_offsets[i];
}

fcl_r64_t c_morpheus_values_at_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A,
                                               fcl_i32_t i, fcl_i32_t j) {
  return A->values(i, j);
}

void c_morpheus_set_diagonal_offests_at_dia_r64_i32_r_h(
    fcl_mat_dia_r64_i32_r_h* A, fcl_i32_t i, fcl_i32_t val) {
  A->diagonal_offsets[i] = val;
}

void c_morpheus_set_values_at_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A,
                                              fcl_i32_t i, fcl_i32_t j,
                                              fcl_r64_t val) {
  A->values(i, j) = val;
}

// fcl_bool_t c_morpheus_exceeds_tolerance_mat_dia_r64_i32_r_h(
//     fcl_mat_dia_r64_i32_r_h* A, const fcl_i32_t num_rows,
//     const fcl_i32_t num_entries, const fcl_i32_t num_diagonals) {
//   return (*A).exceeds_tolerance(num_rows, num_entries, num_diagonals);
// }

fcl_formats_e c_morpheus_format_enum_mat_dia_r64_i32_r_h(
    fcl_mat_dia_r64_i32_r_h* A) {
  return A->format_enum();
}

int c_morpheus_format_index_mat_dia_r64_i32_r_h(fcl_mat_dia_r64_i32_r_h* A) {
  return A->format_index();
}
