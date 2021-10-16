/**
 * Examples_08_hvec_Interface.c
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

#include <Morpheus_Ccl.hpp>

#include <stdio.h>
#include <string.h>

typedef ccl_hvec_dense_v vec;

int main() {
  ccl_initialize_without_args();
  {
    vec *x, *y, *w;

    ccl_hvec_dense_v_create(&x, 10, 3);
    ccl_hvec_dense_v_create(&y, 10, 5);
    ccl_hvec_dense_v_create(&w, 10, 0);

    printf("<x,y> = %f\n", ccl_hvec_dense_v_dot(10, x, y));
    ccl_hvec_dense_v_waxpby(10, 1.0, x, 2.0, y, w);
    ccl_hvec_dense_v_print(w);

    printf("Reduced(w) = %f\n", ccl_hvec_dense_v_reduce(w, 10));
    
    ccl_hvec_dense_v_assign(y, 5, 2.5);

    ccl_hvec_dense_v_print(y);

    ccl_index_t xsize = ccl_hvec_dense_v_size(x);
    ccl_value_t* xdata = ccl_hvec_dense_v_data(x);

    printf("x:: Size = %d\nx::vals::\n", xsize);
    for(int i=0; i<xsize; i++){
      printf("\t[%d] %3.1f\n", i, xdata[i]);
    }

    ccl_hvec_dense_v_resize(x, 2);
    ccl_hvec_dense_v_print(x);

    ccl_hvec_dense_v_resize_fill(x, 9, -8.2);
    ccl_hvec_dense_v_print(x);

    vec *z;
    
    ccl_hvec_dense_v_create_default(&z);
    ccl_hvec_dense_v_allocate_from_hvec_dense_v(y, z);
    ccl_hvec_dense_v_print(z);

    ccl_hvec_dense_v_destroy(&x);
    ccl_hvec_dense_v_destroy(&y);
    ccl_hvec_dense_v_destroy(&w);
    ccl_hvec_dense_v_destroy(&z);
  }
  ccl_finalize();

  return 0;
}
