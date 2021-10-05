#include "Fcl_C.hpp"

#include <stdio.h>
#include <string.h>
typedef fcl_mat_dyn_r64_i32_r_h dyn;
typedef fcl_mat_csr_r64_i32_r_h csr;
typedef fcl_vec_dense_r64_i32_r_h vec;

int main() {
  c_morpheus_initialize_without_args();
  {
    csr *A, *B;
    vec *x, *y;
    fcl_r64_t *Aval, *xval, *yval;
    fcl_i32_t *Aroff, *Acind;

    c_morpheus_create_mat_csr_r64_i32_r_h(&A, &Aroff, &Acind, &Aval, 5, 3, 3);

    int i;
    for(i=0; i<3; i++){
      Aroff[i] = i;
      Acind[i] = i;
      Aval[i] = i;
    }
    Aroff[0] = 15;

    c_morpheus_create_vec_dense_r64_i32_r_h(&x, &xval, 3, 3);
    c_morpheus_create_vec_dense_r64_i32_r_h(&y, &yval, 5, 0);

    c_morpheus_multiply_mat_csr_vec_dense_vec_dense_r64_i32_r_h_serial(A, x,
                                                                       y);

    c_morpheus_resize_mat_csr_r64_i32_r_h(A, &Aroff, &Acind, &Aval, 10, 10, 64);

    fcl_r64_t *Bval;
    fcl_i32_t *Broff, *Bcind;
    c_morpheus_create_mat_csr_r64_i32_r_h(&B, &Broff, &Bcind, &Bval, 0,0,0);
    c_morpheus_allocate_mat_csr_from_mat_csr_r64_i32_r_h(A, B, &Broff, &Bcind, &Bval);
    for(i=0; i<64; i++){
      Broff[i] = i;
      Bcind[i] = i;
      Bval[i] = i;
    }

    Bval[63] = -55;
    c_morpheus_print_mat_csr_r64_i32_r_h(B);
    c_morpheus_print_mat_csr_r64_i32_r_h(A);
    
    c_morpheus_set_nrows_mat_csr_r64_i32_r_h(A, 15);
    c_morpheus_set_ncols_mat_csr_r64_i32_r_h(A, 22);
    c_morpheus_set_nnnz_mat_csr_r64_i32_r_h(A, 111);

    printf("Csr Enum: %d\n", c_morpheus_format_enum_mat_csr_r64_i32_r_h(A));

    printf("Csr Index: %d\n", c_morpheus_format_index_mat_csr_r64_i32_r_h(A));

    c_morpheus_destroy_mat_csr_r64_i32_r_h(&A);
    c_morpheus_destroy_mat_csr_r64_i32_r_h(&B);
    c_morpheus_destroy_vec_dense_r64_i32_r_h(&x);
    c_morpheus_destroy_vec_dense_r64_i32_r_h(&y);
  }
  c_morpheus_finalize();

  return 0;
}
