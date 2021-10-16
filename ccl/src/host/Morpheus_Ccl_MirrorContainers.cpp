/**
 * Morpheus_Ccl_MirrorContainers.cpp
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

#include <host/Morpheus_Ccl_MirrorContainers.hpp>

ccl_hmat_coo_hostmirror* morpheus_ccl_create_mirror_hmat_coo(
    ccl_hmat_coo* src) {
  ccl_hmat_coo_hostmirror mirror = Morpheus::create_mirror(*src);

  return (new ccl_hmat_coo_hostmirror(mirror));
}

ccl_hmat_csr_hostmirror* morpheus_ccl_create_mirror_hmat_csr(
    ccl_hmat_csr* src) {
  ccl_hmat_csr_hostmirror mirror = Morpheus::create_mirror(*src);

  return (new ccl_hmat_csr_hostmirror(mirror));
}

ccl_hmat_dia_hostmirror* morpheus_ccl_create_mirror_hmat_dia(
    ccl_hmat_dia* src) {
  ccl_hmat_dia_hostmirror mirror = Morpheus::create_mirror(*src);

  return (new ccl_hmat_dia_hostmirror(mirror));
}

ccl_hmat_dense_hostmirror* morpheus_ccl_create_mirror_hmat_dense(
    ccl_hmat_dense* src) {
  ccl_hmat_dense_hostmirror mirror = Morpheus::create_mirror(*src);

  return (new ccl_hmat_dense_hostmirror(mirror));
}

ccl_hvec_dense_hostmirror* morpheus_ccl_create_mirror_hvec_dense(
    ccl_hvec_dense* src) {
  ccl_hvec_dense_hostmirror mirror = Morpheus::create_mirror(*src);

  return (new ccl_hvec_dense_hostmirror(mirror));
}

ccl_hmat_dyn_hostmirror* morpheus_ccl_create_mirror_hmat_dyn(
    ccl_hmat_dyn* src) {
  ccl_hmat_dyn_hostmirror mirror = Morpheus::create_mirror(*src);

  return (new ccl_hmat_dyn_hostmirror(mirror));
}

ccl_hmat_coo* morpheus_ccl_create_mirror_container_hmat_coo(ccl_hmat_coo* src) {
  ccl_hmat_coo mirror = Morpheus::create_mirror_container(*src);

  return (new ccl_hmat_coo(mirror));
}

ccl_hmat_csr* morpheus_ccl_create_mirror_container_hmat_csr(ccl_hmat_csr* src) {
  ccl_hmat_csr mirror = Morpheus::create_mirror_container(*src);

  return (new ccl_hmat_csr(mirror));
}

ccl_hmat_dia* morpheus_ccl_create_mirror_container_hmat_dia(ccl_hmat_dia* src) {
  ccl_hmat_dia mirror = Morpheus::create_mirror_container(*src);

  return (new ccl_hmat_dia(mirror));
}

ccl_hmat_dense* morpheus_ccl_create_mirror_container_hmat_dense(
    ccl_hmat_dense* src) {
  ccl_hmat_dense mirror = Morpheus::create_mirror_container(*src);

  return (new ccl_hmat_dense(mirror));
}

ccl_hvec_dense* morpheus_ccl_create_mirror_container_hvec_dense(
    ccl_hvec_dense* src) {
  ccl_hvec_dense mirror = Morpheus::create_mirror_container(*src);

  return (new ccl_hvec_dense(mirror));
}

ccl_hmat_dyn* morpheus_ccl_create_mirror_container_hmat_dyn(ccl_hmat_dyn* src) {
  ccl_hmat_dyn mirror = Morpheus::create_mirror_container(*src);

  return (new ccl_hmat_dyn(mirror));
}
