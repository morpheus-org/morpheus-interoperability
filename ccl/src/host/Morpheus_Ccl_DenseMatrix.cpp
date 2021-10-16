/**
 * Morpheus_Ccl_DenseMatrix.cpp
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

#include <host/Morpheus_Ccl_DenseMatrix.hpp>

void ccl_hmat_dense_create_default(ccl_hmat_dense** A) {
  *A = (new ccl_hmat_dense());
}

void ccl_hmat_dense_create(ccl_hmat_dense** A, ccl_index_t num_rows,
                           ccl_index_t num_cols, ccl_value_t val) {
  *A = (new ccl_hmat_dense("ccl_hmat_dense::", num_rows, num_cols, val));
}

void ccl_hmat_dense_create_from_hmat_dense(ccl_hmat_dense* src,
                                           ccl_hmat_dense** dst) {
  *dst = (new ccl_hmat_dense(*src));
}

void ccl_hmat_dense_allocate_from_hmat_dense(ccl_hmat_dense* src,
                                             ccl_hmat_dense* dst) {
  dst->allocate("ccl_hmat_dense::allocate::", *src);
}

void ccl_hmat_dense_assign(ccl_hmat_dense* A, ccl_index_t num_rows,
                           ccl_index_t num_cols, ccl_value_t val) {
  A->assign(num_rows, num_cols, val);
}

void ccl_hmat_dense_resize(ccl_hmat_dense* A, ccl_index_t num_rows,
                           ccl_index_t num_cols) {
  A->resize(num_rows, num_cols);
}

void ccl_hmat_dense_destroy(ccl_hmat_dense** A) { delete (*A); }

ccl_index_t ccl_hmat_dense_nrows(ccl_hmat_dense* A) { return A->nrows(); }

ccl_index_t ccl_hmat_dense_ncols(ccl_hmat_dense* A) { return A->ncols(); }

ccl_index_t ccl_hmat_dense_nnnz(ccl_hmat_dense* A) { return A->nnnz(); }

void ccl_hmat_dense_set_nrows(ccl_hmat_dense* A, ccl_index_t nrows) {
  A->set_nrows(nrows);
}

void ccl_hmat_dense_set_ncols(ccl_hmat_dense* A, ccl_index_t ncols) {
  A->set_ncols(ncols);
}

void ccl_hmat_dense_set_nnnz(ccl_hmat_dense* A, ccl_index_t nnnz) {
  A->set_nnnz(nnnz);
}

ccl_value_t* ccl_hmat_dense_data(ccl_hmat_dense* A) { return A->data(); }

ccl_value_t ccl_hmat_dense_values_at(ccl_hmat_dense* A, ccl_index_t i,
                                     ccl_index_t j) {
  return (*A)(i, j);
}

void ccl_hmat_dense_set_values_at(ccl_hmat_dense* A, ccl_index_t i,
                                  ccl_index_t j, ccl_index_t val) {
  (*A)(i, j) = val;
}
