/**
 * Fcl_C_DenseVector.cpp
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

#include "Fcl_C_DenseVector.hpp"

extern "C" {

    void c_morpheus_create_vec_dirh(Morpheus::Fcl::vec_r64_i32_r_h** v, Morpheus::Fcl::i32_t n, Morpheus::Fcl::r64_t val)
    {
        *v = (new Morpheus::Fcl::vec_r64_i32_r_h("vec_iirh", n, val));
    }

    void c_morpheus_create_vec_dirh_from_dirh(Morpheus::Fcl::vec_r64_i32_r_h* src, Morpheus::Fcl::vec_r64_i32_r_h** dst)
    {
        *dst = (new Morpheus::Fcl::vec_r64_i32_r_h(*src));
    }

    void c_morpheus_destroy_vec_dirh(Morpheus::Fcl::vec_r64_i32_r_h** v)
    {
        delete(*v);
    }

    void c_morpheus_print_vec_dirh(Morpheus::Fcl::vec_r64_i32_r_h* v)
    {
        Morpheus::print(*v);
    }
}