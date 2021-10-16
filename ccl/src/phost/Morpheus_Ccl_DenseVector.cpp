/**
 * Morpheus_Ccl_DenseVector.cpp
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

#include <phost/Morpheus_Ccl_DenseVector.hpp>

void ccl_phvec_dense_v_create_default(ccl_phvec_dense_v** v) {
  *v = (new ccl_phvec_dense_v());
}

void ccl_phvec_dense_v_create(ccl_phvec_dense_v** v, ccl_index_t n,
                              ccl_value_t val) {
  *v = (new ccl_phvec_dense_v("ccl_phvec_dense_v::", n, val));
}

void ccl_phvec_dense_v_create_from_phvec_dense_v(ccl_phvec_dense_v* src,
                                                 ccl_phvec_dense_v** dst) {
  *dst = (new ccl_phvec_dense_v(*src));
}

void ccl_phvec_dense_v_allocate_from_phvec_dense_v(ccl_phvec_dense_v* src,
                                                   ccl_phvec_dense_v* dst) {
  dst->allocate("ccl_phvec_dense_v::allocate::", *src);
}

void ccl_phvec_dense_v_assign(ccl_phvec_dense_v* v, ccl_index_t n,
                              ccl_value_t val) {
  v->assign(n, val);
}

// TODO: Assign Random
// void ccl_phvec_dense_v_assign_random(
//     ccl_phvec_dense_v* v, ccl_value_t range_low, ccl_value_t
//     range_high);

void ccl_phvec_dense_v_resize(ccl_phvec_dense_v* v, ccl_index_t n) {
  v->resize(n);
}

void ccl_phvec_dense_v_resize_fill(ccl_phvec_dense_v* v, ccl_index_t n,
                                   ccl_value_t val) {
  v->resize(n, val);
}

void ccl_phvec_dense_v_destroy(ccl_phvec_dense_v** v) { delete (*v); }

ccl_index_t ccl_phvec_dense_v_size(ccl_phvec_dense_v* v) { return v->size(); }

ccl_value_t* ccl_phvec_dense_v_data(ccl_phvec_dense_v* v) { return v->data(); }

ccl_value_t ccl_phvec_dense_v_values_at(ccl_phvec_dense_v* v, ccl_index_t i) {
  return (*v)[i];
}

void ccl_phvec_dense_v_set_values_at(ccl_phvec_dense_v* v, ccl_index_t i,
                                     ccl_index_t val) {
  (*v)[i] = val;
}
