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
typedef ccl_vec_dense vec;

int main() {
  morpheus_ccl_initialize_without_args();
  {
    vec *in, *out, *keys;
    ccl_index_t size = 10;
    morpheus_ccl_create_vec_dense(&in, size, 1);
    morpheus_ccl_create_vec_dense(&out, size, 0);
    morpheus_ccl_create_vec_dense(&keys, size, 0);

    morpheus_ccl_inclusive_scan_vec_dense_vec_dense_serial(in, out, size, 0);

    printf("Inclusive Scan:\n");
    morpheus_ccl_print_vec_dense(out);

    morpheus_ccl_exclusive_scan_vec_dense_vec_dense_serial(in, out, size, 0);

    printf("Exclusive Scan:\n");
    morpheus_ccl_print_vec_dense(out);

    morpheus_ccl_set_values_at_vec_dense(keys, 0, 0);
    morpheus_ccl_set_values_at_vec_dense(keys, 1, 0);
    morpheus_ccl_set_values_at_vec_dense(keys, 2, 0);
    morpheus_ccl_set_values_at_vec_dense(keys, 3, 1);
    morpheus_ccl_set_values_at_vec_dense(keys, 4, 1);
    morpheus_ccl_set_values_at_vec_dense(keys, 5, 2);
    morpheus_ccl_set_values_at_vec_dense(keys, 6, 3);
    morpheus_ccl_set_values_at_vec_dense(keys, 7, 3);
    morpheus_ccl_set_values_at_vec_dense(keys, 8, 3);
    morpheus_ccl_set_values_at_vec_dense(keys, 9, 3);

    morpheus_ccl_inclusive_scan_by_key_vec_dense_vec_dense_serial(keys, in, out, size, 0);

    printf("Inclusive Scan by key:\n");
    morpheus_ccl_print_vec_dense(out);

    morpheus_ccl_exclusive_scan_by_key_vec_dense_vec_dense_serial(keys,in, out, size, 0);

    printf("Exclusive Scan by key:\n");
    morpheus_ccl_print_vec_dense(out);

    morpheus_ccl_destroy_vec_dense(&in);
    morpheus_ccl_destroy_vec_dense(&out);
    morpheus_ccl_destroy_vec_dense(&keys);
  }
  morpheus_ccl_finalize();

  return 0;
}
