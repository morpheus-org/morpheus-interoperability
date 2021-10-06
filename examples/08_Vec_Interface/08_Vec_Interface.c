#include "Fcl_C.hpp"

#include <stdio.h>
#include <string.h>
typedef fcl_vec_dense_r64_i32_r_h vec;

int main() {
  c_morpheus_initialize_without_args();
  {
    vec *x, *y;

    c_morpheus_create_vec_dense_r64_i32_r_h(&x, 10, 3);
    c_morpheus_create_vec_dense_r64_i32_r_h(&y, 10, 5);

    c_morpheus_assign_vec_dense_r64_i32_r_h(y, 5, 2.5);

    c_morpheus_print_vec_dense_r64_i32_r_h(y);

    fcl_i32_t xsize = c_morpheus_size_vec_dense_r64_i32_r_h(x);
    fcl_r64_t* xdata = c_morpheus_data_vec_dense_r64_i32_r_h(x);

    printf("x:: Size = %d\nx::vals::\n", xsize);
    for(int i=0; i<xsize; i++){
      printf("\t[%d] %3.1f\n", i, xdata[i]);
    }

    c_morpheus_resize_vec_dense_r64_i32_r_h(x, 2);
    c_morpheus_print_vec_dense_r64_i32_r_h(x);

    c_morpheus_resize_fill_vec_dense_r64_i32_r_h(x, 9, -8.2);
    c_morpheus_print_vec_dense_r64_i32_r_h(x);

    vec *z = c_morpheus_create_default_vec_dense_r64_i32_r_h();
    c_morpheus_allocate_vec_from_vec_dense_r64_i32_r_h(y, z);
    c_morpheus_print_vec_dense_r64_i32_r_h(z);

    c_morpheus_destroy_vec_dense_r64_i32_r_h(&x);
    c_morpheus_destroy_vec_dense_r64_i32_r_h(&y);
    c_morpheus_destroy_vec_dense_r64_i32_r_h(&z);
  }
  c_morpheus_finalize();

  return 0;
}
