/**
 * Examples_09_Scan.c
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
    vec *in, *out, *keys;
    ccl_index_t size = 10;
    ccl_hvec_dense_v_create(&in, size, 1);
    ccl_hvec_dense_v_create(&out, size, 0);
    ccl_hvec_dense_v_create(&keys, size, 0);

    ccl_hvec_dense_v_inclusive_scan(in, out, size, 0);

    printf("Inclusive Scan:\n");
    ccl_hvec_dense_v_print(out);

    ccl_hvec_dense_v_exclusive_scan(in, out, size, 0);

    printf("Exclusive Scan:\n");
    ccl_hvec_dense_v_print(out);

    ccl_hvec_dense_v_set_values_at(keys, 0, 0);
    ccl_hvec_dense_v_set_values_at(keys, 1, 0);
    ccl_hvec_dense_v_set_values_at(keys, 2, 0);
    ccl_hvec_dense_v_set_values_at(keys, 3, 1);
    ccl_hvec_dense_v_set_values_at(keys, 4, 1);
    ccl_hvec_dense_v_set_values_at(keys, 5, 2);
    ccl_hvec_dense_v_set_values_at(keys, 6, 3);
    ccl_hvec_dense_v_set_values_at(keys, 7, 3);
    ccl_hvec_dense_v_set_values_at(keys, 8, 3);
    ccl_hvec_dense_v_set_values_at(keys, 9, 3);

    ccl_hvec_dense_v_inclusive_scan_by_key(keys, in, out, size, 0);

    printf("Inclusive Scan by key:\n");
    ccl_hvec_dense_v_print(out);

    ccl_hvec_dense_v_exclusive_scan_by_key(keys,in, out, size, 0);

    printf("Exclusive Scan by key:\n");
    ccl_hvec_dense_v_print(out);

    ccl_hvec_dense_v_destroy(&in);
    ccl_hvec_dense_v_destroy(&out);
    ccl_hvec_dense_v_destroy(&keys);
  }
  ccl_finalize();

  return 0;
}
