#include "Fcl_C.hpp"

typedef fcl_mat_dyn_r64_i32_r_h dyn;
typedef fcl_mat_coo_r64_i32_r_h coo;
typedef fcl_vec_dense_r64_i32_r_h vec;

int main() {
  c_morpheus_initialize_without_args();
  {
    dyn *Adyn;
    coo *A;
    vec *x, *y;
    fcl_r64_t *Aval, *xval, *yval;
    fcl_i32_t *Arind, *Acind;

    c_morpheus_create_mat_coo_r64_i32_r_h(&A, &Arind, &Acind, &Aval, 5, 3, 3);
    Arind[0] = 0;
    Acind[0] = 0;
    Aval[0]  = 4;
    Arind[1] = 2;
    Acind[1] = 1;
    Aval[1]  = -2;
    Arind[2] = 4;
    Acind[2] = 2;
    Aval[2]  = 2.5;

    c_morpheus_create_vec_dense_r64_i32_r_h(&x, &xval, 3, 3);
    c_morpheus_create_vec_dense_r64_i32_r_h(&y, &yval, 5, 0);

    c_morpheus_create_mat_dyn_from_mat_coo_r64_i32_r_h(A, &Adyn);
    c_morpheus_print_mat_dyn_r64_i32_r_h(Adyn);

    c_morpheus_multiply_mat_dyn_vec_dense_vec_dense_r64_i32_r_h_serial(Adyn, x,
                                                                       y);

    c_morpheus_print_mat_dyn_r64_i32_r_h(Adyn);
    c_morpheus_print_vec_dense_r64_i32_r_h(x);
    c_morpheus_print_vec_dense_r64_i32_r_h(y);

    coo *Afromdyn;
    fcl_i32_t *Adrind, *Adcind;
    fcl_r64_t *Adval;

    c_morpheus_create_mat_coo_from_mat_dyn_r64_i32_r_h(Adyn, &Afromdyn, &Adrind, &Adcind, &Adval);
    c_morpheus_print_mat_coo_r64_i32_r_h(Afromdyn);
    Adval[2] = -22.5;
    c_morpheus_print_mat_dyn_r64_i32_r_h(Adyn);

    c_morpheus_activate_mat_dyn_r64_i32_r_h(Adyn, CSR_FORMAT);
    c_morpheus_print_mat_dyn_r64_i32_r_h(Adyn);

    c_morpheus_destroy_mat_dyn_r64_i32_r_h(&Adyn);
    c_morpheus_destroy_mat_coo_r64_i32_r_h(&A);
    c_morpheus_destroy_vec_dense_r64_i32_r_h(&x);
    c_morpheus_destroy_vec_dense_r64_i32_r_h(&y);
  }
  c_morpheus_finalize();

  return 0;
}
