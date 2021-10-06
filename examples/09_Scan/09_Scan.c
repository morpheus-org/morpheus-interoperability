#include "Fcl_C.hpp"

#include <stdio.h>
#include <string.h>
typedef fcl_vec_dense_r64_i32_r_h vec;

int main() {
  c_morpheus_initialize_without_args();
  {
    vec *in, *out, *keys;
    fcl_i32_t size = 10;
    c_morpheus_create_vec_dense_r64_i32_r_h(&in, size, 1);
    c_morpheus_create_vec_dense_r64_i32_r_h(&out, size, 0);
    c_morpheus_create_vec_dense_r64_i32_r_h(&keys, size, 0);

    c_morpheus_inclusive_scan_vec_dense_vec_dense_r64_i32_r_h_serial(in, out, size, 0);

    printf("Inclusive Scan:\n");
    c_morpheus_print_vec_dense_r64_i32_r_h(out);

    c_morpheus_exclusive_scan_vec_dense_vec_dense_r64_i32_r_h_serial(in, out, size, 0);

    printf("Exclusive Scan:\n");
    c_morpheus_print_vec_dense_r64_i32_r_h(out);

    c_morpheus_set_values_at_vec_dense_r64_i32_r_h(keys, 0, 0);
    c_morpheus_set_values_at_vec_dense_r64_i32_r_h(keys, 1, 0);
    c_morpheus_set_values_at_vec_dense_r64_i32_r_h(keys, 2, 0);
    c_morpheus_set_values_at_vec_dense_r64_i32_r_h(keys, 3, 1);
    c_morpheus_set_values_at_vec_dense_r64_i32_r_h(keys, 4, 1);
    c_morpheus_set_values_at_vec_dense_r64_i32_r_h(keys, 5, 2);
    c_morpheus_set_values_at_vec_dense_r64_i32_r_h(keys, 6, 3);
    c_morpheus_set_values_at_vec_dense_r64_i32_r_h(keys, 7, 3);
    c_morpheus_set_values_at_vec_dense_r64_i32_r_h(keys, 8, 3);
    c_morpheus_set_values_at_vec_dense_r64_i32_r_h(keys, 9, 3);

    c_morpheus_inclusive_scan_by_key_vec_dense_vec_dense_r64_i32_r_h_serial(keys, in, out, size, 0);

    printf("Inclusive Scan by key:\n");
    c_morpheus_print_vec_dense_r64_i32_r_h(out);

    c_morpheus_exclusive_scan_by_key_vec_dense_vec_dense_r64_i32_r_h_serial(keys,in, out, size, 0);

    printf("Exclusive Scan by key:\n");
    c_morpheus_print_vec_dense_r64_i32_r_h(out);

    c_morpheus_destroy_vec_dense_r64_i32_r_h(&in);
    c_morpheus_destroy_vec_dense_r64_i32_r_h(&out);
    c_morpheus_destroy_vec_dense_r64_i32_r_h(&keys);
  }
  c_morpheus_finalize();

  return 0;
}
