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

#include <phost/Morpheus_Ccl_DynamicMatrix.hpp>

void ccl_phmat_dyn_create_default(ccl_phmat_dyn** A) {
  *A = (new ccl_phmat_dyn());
}

void ccl_phmat_dyn_create_from_phmat(void* src, ccl_formats_e index,
                                     ccl_phmat_dyn** dst) {
  if (index == Morpheus::COO_FORMAT) {
    ccl_phmat_coo* src_cast = (ccl_phmat_coo*)src;
    *dst                    = new ccl_phmat_dyn(ccl_phmat_coo(*src_cast));
  } else if (index == Morpheus::CSR_FORMAT) {
    ccl_phmat_csr* src_cast = (ccl_phmat_csr*)src;
    *dst                    = new ccl_phmat_dyn(ccl_phmat_csr(*src_cast));
  } else if (index == Morpheus::DIA_FORMAT) {
    ccl_phmat_dia* src_cast = (ccl_phmat_dia*)src;
    *dst                    = new ccl_phmat_dyn(ccl_phmat_dia(*src_cast));
  }
}

void ccl_phmat_dyn_assign_from_phmat(void* src, ccl_formats_e index,
                                     ccl_phmat_dyn* dst) {
  if (index == Morpheus::COO_FORMAT) {
    *dst = *(ccl_phmat_coo*)src;
  } else if (index == Morpheus::CSR_FORMAT) {
    *dst = *(ccl_phmat_csr*)src;
  } else if (index == Morpheus::DIA_FORMAT) {
    *dst = *(ccl_phmat_dia*)src;
  }
}

void ccl_phmat_dyn_assign_from_phmat_dia(ccl_phmat_dia* src,
                                         ccl_phmat_dyn* dst) {
  *dst = *src;
}

void ccl_phmat_dyn_resize(ccl_phmat_dyn* A, const ccl_index_t num_rows,
                          const ccl_index_t num_cols,
                          const ccl_index_t num_nnz) {
  A->resize(num_rows, num_cols, num_nnz);
}

void ccl_phmat_dyn_resize_diags(ccl_phmat_dyn* A, const ccl_index_t num_rows,
                                const ccl_index_t num_cols,
                                const ccl_index_t num_nnz,
                                const ccl_index_t num_diags) {
  A->resize(num_rows, num_cols, num_nnz, num_diags);
}

void ccl_phmat_dyn_resize_aligned(ccl_phmat_dyn* A, const ccl_index_t num_rows,
                                  const ccl_index_t num_cols,
                                  const ccl_index_t num_nnz,
                                  const ccl_index_t num_diags,
                                  const ccl_index_t alignment) {
  A->resize(num_rows, num_cols, num_nnz, num_diags, alignment);
}

void ccl_phmat_dyn_allocate_from_phmat_dyn(ccl_phmat_dyn* src,
                                           ccl_phmat_dyn* dst) {
  dst->allocate("ccl_phmat_dyn::allocate::", *src);
}

void ccl_phmat_dyn_destroy(ccl_phmat_dyn** A) { delete (*A); }

ccl_index_t ccl_phmat_dyn_nrows(ccl_phmat_dyn* A) { return A->nrows(); }

ccl_index_t ccl_phmat_dyn_ncols(ccl_phmat_dyn* A) { return A->ncols(); }

ccl_index_t ccl_phmat_dyn_nnnz(ccl_phmat_dyn* A) { return A->nnnz(); }

void ccl_phmat_dyn_set_nrows(ccl_phmat_dyn* A, ccl_index_t nrows) {
  A->set_nrows(nrows);
}

void ccl_phmat_dyn_set_ncols(ccl_phmat_dyn* A, ccl_index_t ncols) {
  A->set_ncols(ncols);
}

void ccl_phmat_dyn_set_nnnz(ccl_phmat_dyn* A, ccl_index_t nnnz) {
  A->set_nnnz(nnnz);
}

void ccl_phmat_dyn_activate(ccl_phmat_dyn* A, const ccl_formats_e index) {
  A->activate(index);
}

void ccl_phmat_dyn_activate_index(ccl_phmat_dyn* A, const int index) {
  A->activate(index);
}

int ccl_phmat_dyn_active_index(ccl_phmat_dyn* A) { return A->active_index(); }

ccl_formats_e ccl_phmat_dyn_active_enum(ccl_phmat_dyn* A) {
  return A->active_enum();
}

ccl_formats_e ccl_phmat_dyn_format_enum(ccl_phmat_dyn* A) {
  return A->format_enum();
}
