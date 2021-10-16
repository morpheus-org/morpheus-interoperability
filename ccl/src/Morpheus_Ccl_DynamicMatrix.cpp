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

void morpheus_ccl_create_default_hmat_dyn(ccl_hmat_dyn** A) {
  *A = (new ccl_hmat_dyn());
}

void morpheus_ccl_create_hmat_dyn_from_hmat(void* src, ccl_formats_e index,
                                            ccl_hmat_dyn** dst) {
  if (index == Morpheus::COO_FORMAT) {
    ccl_hmat_coo* src_cast = (ccl_hmat_coo*)src;
    *dst                   = new ccl_hmat_dyn(ccl_hmat_coo(*src_cast));
  } else if (index == Morpheus::CSR_FORMAT) {
    ccl_hmat_csr* src_cast = (ccl_hmat_csr*)src;
    *dst                   = new ccl_hmat_dyn(ccl_hmat_csr(*src_cast));
  } else if (index == Morpheus::DIA_FORMAT) {
    ccl_hmat_dia* src_cast = (ccl_hmat_dia*)src;
    *dst                   = new ccl_hmat_dyn(ccl_hmat_dia(*src_cast));
  }
}

void morpheus_ccl_assign_hmat_dyn_from_hmat(void* src, ccl_formats_e index,
                                            ccl_hmat_dyn* dst) {
  if (index == Morpheus::COO_FORMAT) {
    *dst = *(ccl_hmat_coo*)src;
  } else if (index == Morpheus::CSR_FORMAT) {
    *dst = *(ccl_hmat_csr*)src;
  } else if (index == Morpheus::DIA_FORMAT) {
    *dst = *(ccl_hmat_dia*)src;
  }
}

void morpheus_ccl_assign_hmat_dyn_from_hmat_dia(ccl_hmat_dia* src,
                                                ccl_hmat_dyn* dst) {
  *dst = *src;
}

void morpheus_ccl_resize_hmat_dyn(ccl_hmat_dyn* A, const ccl_index_t num_rows,
                                  const ccl_index_t num_cols,
                                  const ccl_index_t num_nnz) {
  A->resize(num_rows, num_cols, num_nnz);
}

void morpheus_ccl_resize_diags_hmat_dyn(ccl_hmat_dyn* A,
                                        const ccl_index_t num_rows,
                                        const ccl_index_t num_cols,
                                        const ccl_index_t num_nnz,
                                        const ccl_index_t num_diags) {
  A->resize(num_rows, num_cols, num_nnz, num_diags);
}

void morpheus_ccl_resize_aligned_hmat_dyn(ccl_hmat_dyn* A,
                                          const ccl_index_t num_rows,
                                          const ccl_index_t num_cols,
                                          const ccl_index_t num_nnz,
                                          const ccl_index_t num_diags,
                                          const ccl_index_t alignment) {
  A->resize(num_rows, num_cols, num_nnz, num_diags, alignment);
}

void morpheus_ccl_allocate_hmat_dyn_from_hmat_dyn(ccl_hmat_dyn* src,
                                                  ccl_hmat_dyn* dst) {
  dst->allocate("ccl_hmat_dyn::allocate::", *src);
}

void morpheus_ccl_destroy_hmat_dyn(ccl_hmat_dyn** A) { delete (*A); }

ccl_index_t morpheus_ccl_nrows_hmat_dyn(ccl_hmat_dyn* A) { return A->nrows(); }

ccl_index_t morpheus_ccl_ncols_hmat_dyn(ccl_hmat_dyn* A) { return A->ncols(); }

ccl_index_t morpheus_ccl_nnnz_hmat_dyn(ccl_hmat_dyn* A) { return A->nnnz(); }

void morpheus_ccl_set_nrows_hmat_dyn(ccl_hmat_dyn* A, ccl_index_t nrows) {
  A->set_nrows(nrows);
}

void morpheus_ccl_set_ncols_hmat_dyn(ccl_hmat_dyn* A, ccl_index_t ncols) {
  A->set_ncols(ncols);
}

void morpheus_ccl_set_nnnz_hmat_dyn(ccl_hmat_dyn* A, ccl_index_t nnnz) {
  A->set_nnnz(nnnz);
}

void morpheus_ccl_activate_hmat_dyn(ccl_hmat_dyn* A,
                                    const ccl_formats_e index) {
  A->activate(index);
}

void morpheus_ccl_activate_index_hmat_dyn(ccl_hmat_dyn* A, const int index) {
  A->activate(index);
}

int morpheus_ccl_active_index_hmat_dyn(ccl_hmat_dyn* A) {
  return A->active_index();
}

ccl_formats_e morpheus_ccl_active_enum_hmat_dyn(ccl_hmat_dyn* A) {
  return A->active_enum();
}

ccl_formats_e morpheus_ccl_format_enum_hmat_dyn(ccl_hmat_dyn* A) {
  return A->format_enum();
}
