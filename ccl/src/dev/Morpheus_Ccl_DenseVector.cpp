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

#include <dev/Morpheus_Ccl_DenseVector.hpp>

void ccl_dvec_dense_v_create_default(ccl_dvec_dense_v** v) {
  *v = (new ccl_dvec_dense_v());
}

void ccl_dvec_dense_v_create(ccl_dvec_dense_v** v, ccl_index_t n,
                             ccl_value_t val) {
  *v = (new ccl_dvec_dense_v("ccl_dvec_dense_v::", n, val));
}

void ccl_dvec_dense_v_create_from_dvec_dense_v(ccl_dvec_dense_v* src,
                                               ccl_dvec_dense_v** dst) {
  *dst = (new ccl_dvec_dense_v(*src));
}

void ccl_dvec_dense_v_allocate_from_dvec_dense_v(ccl_dvec_dense_v* src,
                                                 ccl_dvec_dense_v* dst) {
  dst->allocate("ccl_dvec_dense_v::allocate::", *src);
}

void ccl_dvec_dense_v_assign(ccl_dvec_dense_v* v, ccl_index_t n,
                             ccl_value_t val) {
  v->assign(n, val);
}

// TODO: Assign Random
// void ccl_dvec_dense_v_assign_random(
//     ccl_dvec_dense_v* v, ccl_value_t range_low, ccl_value_t
//     range_high);

void ccl_dvec_dense_v_resize(ccl_dvec_dense_v* v, ccl_index_t n) {
  v->resize(n);
}

void ccl_dvec_dense_v_resize_fill(ccl_dvec_dense_v* v, ccl_index_t n,
                                  ccl_value_t val) {
  v->resize(n, val);
}

void ccl_dvec_dense_v_destroy(ccl_dvec_dense_v** v) { delete (*v); }

ccl_index_t ccl_dvec_dense_v_size(ccl_dvec_dense_v* v) { return v->size(); }

ccl_value_t* ccl_dvec_dense_v_data(ccl_dvec_dense_v* v) { return v->data(); }

void ccl_dvec_dense_i_create_default(ccl_dvec_dense_i** v) {
  *v = (new ccl_dvec_dense_i());
}

void ccl_dvec_dense_i_create(ccl_dvec_dense_i** v, ccl_index_t n,
                             ccl_index_t val) {
  *v = (new ccl_dvec_dense_i("ccl_dvec_dense_i::", n, val));
}

void ccl_dvec_dense_i_create_from_dvec_dense_i(ccl_dvec_dense_i* src,
                                               ccl_dvec_dense_i** dst) {
  *dst = (new ccl_dvec_dense_i(*src));
}

void ccl_dvec_dense_i_allocate_from_dvec_dense_i(ccl_dvec_dense_i* src,
                                                 ccl_dvec_dense_i* dst) {
  dst->allocate("ccl_dvec_dense_i::allocate::", *src);
}

void ccl_dvec_dense_i_assign(ccl_dvec_dense_i* v, ccl_index_t n,
                             ccl_index_t val) {
  v->assign(n, val);
}

// TODO: Assign Random
// void ccl_dvec_dense_i_assign_random(
//     ccl_dvec_dense_i* v, ccl_index_t range_low, ccl_index_t
//     range_high);

void ccl_dvec_dense_i_resize(ccl_dvec_dense_i* v, ccl_index_t n) {
  v->resize(n);
}

void ccl_dvec_dense_i_resize_fill(ccl_dvec_dense_i* v, ccl_index_t n,
                                  ccl_index_t val) {
  v->resize(n, val);
}

void ccl_dvec_dense_i_destroy(ccl_dvec_dense_i** v) { delete (*v); }

ccl_index_t ccl_dvec_dense_i_size(ccl_dvec_dense_i* v) { return v->size(); }

ccl_index_t* ccl_dvec_dense_i_data(ccl_dvec_dense_i* v) { return v->data(); }

ccl_index_t ccl_dvec_dense_i_values_at(ccl_dvec_dense_i* v, ccl_index_t i) {
  return (*v)[i];
}

void ccl_dvec_dense_i_set_values_at(ccl_dvec_dense_i* v, ccl_index_t i,
                                    ccl_index_t val) {
  (*v)[i] = val;
}

// HostMirror Interface
void ccl_dvec_dense_v_hostmirror_create_default(
    ccl_dvec_dense_v_hostmirror** v) {
  *v = (new ccl_dvec_dense_v_hostmirror());
}

void ccl_dvec_dense_v_hostmirror_create(ccl_dvec_dense_v_hostmirror** v,
                                        ccl_index_t n, ccl_value_t val) {
  *v = (new ccl_dvec_dense_v_hostmirror("ccl_dvec_dense_v_hostmirror::", n,
                                        val));
}

void ccl_dvec_dense_v_hostmirror_create_from_dvec_dense_v_hostmirror(
    ccl_dvec_dense_v_hostmirror* src, ccl_dvec_dense_v_hostmirror** dst) {
  *dst = (new ccl_dvec_dense_v_hostmirror(*src));
}

void ccl_dvec_dense_v_hostmirror_allocate_from_dvec_dense_v_hostmirror(
    ccl_dvec_dense_v_hostmirror* src, ccl_dvec_dense_v_hostmirror* dst) {
  dst->allocate("ccl_dvec_dense_v_hostmirror::allocate::", *src);
}

void ccl_dvec_dense_v_hostmirror_assign(ccl_dvec_dense_v_hostmirror* v,
                                        ccl_index_t n, ccl_value_t val) {
  v->assign(n, val);
}

// TODO: Assign Random
// void ccl_dvec_dense_v_hostmirror_assign_random(
//     ccl_dvec_dense_v_hostmirror* v, ccl_value_t range_low, ccl_value_t
//     range_high);

void ccl_dvec_dense_v_hostmirror_resize(ccl_dvec_dense_v_hostmirror* v,
                                        ccl_index_t n) {
  v->resize(n);
}

void ccl_dvec_dense_v_hostmirror_resize_fill(ccl_dvec_dense_v_hostmirror* v,
                                             ccl_index_t n, ccl_value_t val) {
  v->resize(n, val);
}

void ccl_dvec_dense_v_hostmirror_destroy(ccl_dvec_dense_v_hostmirror** v) {
  delete (*v);
}

ccl_index_t ccl_dvec_dense_v_hostmirror_size(ccl_dvec_dense_v_hostmirror* v) {
  return v->size();
}

ccl_value_t* ccl_dvec_dense_v_hostmirror_data(ccl_dvec_dense_v_hostmirror* v) {
  return v->data();
}

ccl_value_t ccl_dvec_dense_v_hostmirror_values_at(
    ccl_dvec_dense_v_hostmirror* v, ccl_index_t i) {
  return (*v)[i];
}

void ccl_dvec_dense_v_hostmirror_set_values_at(ccl_dvec_dense_v_hostmirror* v,
                                               ccl_index_t i, ccl_value_t val) {
  (*v)[i] = val;
}

void ccl_dvec_dense_i_hostmirror_create_default(
    ccl_dvec_dense_i_hostmirror** v) {
  *v = (new ccl_dvec_dense_i_hostmirror());
}

void ccl_dvec_dense_i_hostmirror_create(ccl_dvec_dense_i_hostmirror** v,
                                        ccl_index_t n, ccl_index_t val) {
  *v = (new ccl_dvec_dense_i_hostmirror("ccl_dvec_dense_i_hostmirror::", n,
                                        val));
}

void ccl_dvec_dense_i_hostmirror_create_from_dvec_dense_i_hostmirror(
    ccl_dvec_dense_i_hostmirror* src, ccl_dvec_dense_i_hostmirror** dst) {
  *dst = (new ccl_dvec_dense_i_hostmirror(*src));
}

void ccl_dvec_dense_i_hostmirror_allocate_from_dvec_dense_i_hostmirror(
    ccl_dvec_dense_i_hostmirror* src, ccl_dvec_dense_i_hostmirror* dst) {
  dst->allocate("ccl_dvec_dense_i_hostmirror::allocate::", *src);
}

void ccl_dvec_dense_i_hostmirror_assign(ccl_dvec_dense_i_hostmirror* v,
                                        ccl_index_t n, ccl_index_t val) {
  v->assign(n, val);
}

// TODO: Assign Random
// void ccl_dvec_dense_i_hostmirror_assign_random(
//     ccl_dvec_dense_i_hostmirror* v, ccl_index_t range_low, ccl_index_t
//     range_high);

void ccl_dvec_dense_i_hostmirror_resize(ccl_dvec_dense_i_hostmirror* v,
                                        ccl_index_t n) {
  v->resize(n);
}

void ccl_dvec_dense_i_hostmirror_resize_fill(ccl_dvec_dense_i_hostmirror* v,
                                             ccl_index_t n, ccl_index_t val) {
  v->resize(n, val);
}

void ccl_dvec_dense_i_hostmirror_destroy(ccl_dvec_dense_i_hostmirror** v) {
  delete (*v);
}

ccl_index_t ccl_dvec_dense_i_hostmirror_size(ccl_dvec_dense_i_hostmirror* v) {
  return v->size();
}

ccl_index_t* ccl_dvec_dense_i_hostmirror_data(ccl_dvec_dense_i_hostmirror* v) {
  return v->data();
}

ccl_index_t ccl_dvec_dense_i_hostmirror_values_at(
    ccl_dvec_dense_i_hostmirror* v, ccl_index_t i) {
  return (*v)[i];
}

void ccl_dvec_dense_i_hostmirror_set_values_at(ccl_dvec_dense_i_hostmirror* v,
                                               ccl_index_t i, ccl_index_t val) {
  (*v)[i] = val;
}