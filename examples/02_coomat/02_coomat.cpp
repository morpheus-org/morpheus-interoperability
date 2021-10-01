/**
 * 01_initialize.cpp
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

#include <Morpheus_Core.hpp>
#include "Fcl_Util.h"
#include "Fcl_Cxx.hpp"

using coomat = Morpheus::Fcl::coomat_r64_i32_r_h;

int main(){

    c_morpheus_initialize_without_args();
    {   
        coomat *A;
        Morpheus::Fcl::c_morpheus_allocate_coomat_dirh(&A, 5, 3, 2);
        Morpheus::Fcl::c_morpheus_print_coomat_dirh(A);
        Morpheus::Fcl::c_morpheus_deallocate_coomat_dirh(&A);
    }
    c_morpheus_finalize();

    return 0;
}