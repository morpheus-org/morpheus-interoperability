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

#include "Fcl_C_Util.hpp"
#include "Fcl_C_CooMatrix.hpp"
#include "Fcl_C_DenseVector.hpp"

using coomat = Morpheus::Fcl::coomat_r64_i32_r_h;
using vec = Morpheus::Fcl::vec_r64_i32_r_h;

extern "C"{

int main(){

    c_morpheus_initialize_without_args();
    {   
        coomat *A;
        vec *x, *y;

        c_morpheus_create_coomat_dirh(&A, 5, 3, 3);
        A->row_indices[0] = 0;
        A->column_indices[0] = 0;
        A->values[0] = 4;
        A->row_indices[1] = 2;
        A->column_indices[1] = 1;
        A->values[1] = -2;
        A->row_indices[2] = 4;
        A->column_indices[2] = 2;
        A->values[2] = 2.5;


        c_morpheus_create_vec_dirh(&x, 3, 3);
        c_morpheus_create_vec_dirh(&y, 5, 0);

        c_morpheus_multiply_coo_vec_vec_dirh_serial(A,x,y);

        c_morpheus_print_coomat_dirh(A);
        c_morpheus_print_vec_dirh(x);
        c_morpheus_print_vec_dirh(y);

        // shallow copy matrix
        coomat *A_shallow;
        c_morpheus_create_coomat_dirh_from_dirh(A, &A_shallow);
        A->values[2] = -2.5;
        c_morpheus_print_coomat_dirh(A_shallow);


        c_morpheus_destroy_coomat_dirh(&A);
        c_morpheus_destroy_coomat_dirh(&A_shallow);
        c_morpheus_destroy_vec_dirh(&x);
        c_morpheus_destroy_vec_dirh(&y);
    }
    c_morpheus_finalize();

    return 0;
}

}