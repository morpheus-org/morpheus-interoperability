#include "Fcl_C.hpp"

#include <stdio.h>
#include <string.h>
typedef fcl_mat_dyn_r64_i32_r_h dyn;
typedef fcl_mat_coo_r64_i32_r_h coo;
typedef fcl_vec_dense_r64_i32_r_h vec;

int main() {
  c_morpheus_initialize_without_args();
  {
    coo *A, *B;
    vec *x, *y;
    fcl_r64_t *Aval, *xval, *yval;
    fcl_i32_t *Arind, *Acind;

    c_morpheus_create_mat_coo_r64_i32_r_h(&A, &Arind, &Acind, &Aval, 5, 3, 3);

    int i;
    for(i=0; i<3; i++){
      Arind[i] = i;
      Acind[i] = i;
      Aval[i] = i;
    }
    Arind[0] = 15;

    c_morpheus_create_vec_dense_r64_i32_r_h(&x, &xval, 3, 3);
    c_morpheus_create_vec_dense_r64_i32_r_h(&y, &yval, 5, 0);

    c_morpheus_multiply_mat_coo_vec_dense_vec_dense_r64_i32_r_h_serial(A, x,
                                                                       y);

    c_morpheus_resize_mat_coo_r64_i32_r_h(A, &Arind, &Acind, &Aval, 10, 10, 64);

    fcl_r64_t *Bval;
    fcl_i32_t *Brind, *Bcind;
    c_morpheus_create_mat_coo_r64_i32_r_h(&B, &Brind, &Bcind, &Bval, 0,0,0);
    c_morpheus_allocate_mat_coo_from_mat_coo_r64_i32_r_h(A, B, &Brind, &Bcind, &Bval);
    for(i=0; i<64; i++){
      Brind[i] = i;
      Bcind[i] = i;
      Bval[i] = i;
    }

    Bval[63] = -55;
    c_morpheus_print_mat_coo_r64_i32_r_h(B);
    c_morpheus_print_mat_coo_r64_i32_r_h(A);
    
    c_morpheus_set_nrows_mat_coo_r64_i32_r_h(A, 15);
    c_morpheus_set_ncols_mat_coo_r64_i32_r_h(A, 22);
    c_morpheus_set_nnnz_mat_coo_r64_i32_r_h(A, 111);

    printf("Coo Enum: %d\n", c_morpheus_format_enum_mat_coo_r64_i32_r_h(A));

    printf("Coo Index: %d\n", c_morpheus_format_index_mat_coo_r64_i32_r_h(A));

    c_morpheus_destroy_mat_coo_r64_i32_r_h(&A);
    c_morpheus_destroy_mat_coo_r64_i32_r_h(&B);
    c_morpheus_destroy_vec_dense_r64_i32_r_h(&x);
    c_morpheus_destroy_vec_dense_r64_i32_r_h(&y);
  }
  c_morpheus_finalize();

  return 0;
}
