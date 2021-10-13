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

    c_morpheus_create_mat_csr_r64_i32_r_h(&A, 4, 3, 6);
    // Simple Matrix
    //    [10 20 00]
    //    [00 00 30]
    //    [40 00 50]
    //    [00 60 00]
    // CSR Equivalent:
    // Row Offsets: [0, 2, 3, 5, 6]
    // Column Indices: [0, 1, 2, 0, 2, 1]
    // Values: [10, 20, 30, 40, 50, 60]
    c_morpheus_set_row_offsets_at_csr_r64_i32_r_h(A, 0, 0);
    c_morpheus_set_row_offsets_at_csr_r64_i32_r_h(A, 1, 2);
    c_morpheus_set_row_offsets_at_csr_r64_i32_r_h(A, 2, 3);
    c_morpheus_set_row_offsets_at_csr_r64_i32_r_h(A, 3, 5);
    c_morpheus_set_row_offsets_at_csr_r64_i32_r_h(A, 4, 6);
    
    c_morpheus_set_column_indices_at_csr_r64_i32_r_h(A, 0, 0);
    c_morpheus_set_column_indices_at_csr_r64_i32_r_h(A, 1, 1);
    c_morpheus_set_column_indices_at_csr_r64_i32_r_h(A, 2, 2);
    c_morpheus_set_column_indices_at_csr_r64_i32_r_h(A, 3, 0);
    c_morpheus_set_column_indices_at_csr_r64_i32_r_h(A, 4, 2);
    c_morpheus_set_column_indices_at_csr_r64_i32_r_h(A, 5, 1);
    
    c_morpheus_set_values_at_csr_r64_i32_r_h(A, 0, 10);
    c_morpheus_set_values_at_csr_r64_i32_r_h(A, 1, 20);
    c_morpheus_set_values_at_csr_r64_i32_r_h(A, 2, 30);
    c_morpheus_set_values_at_csr_r64_i32_r_h(A, 3, 40);
    c_morpheus_set_values_at_csr_r64_i32_r_h(A, 4, 50);
    c_morpheus_set_values_at_csr_r64_i32_r_h(A, 5, 60);

    c_morpheus_create_vec_dense_r64_i32_r_h(&x, 3, 3);
    c_morpheus_create_vec_dense_r64_i32_r_h(&y, 6, 0);

    c_morpheus_multiply_mat_csr_vec_dense_vec_dense_r64_i32_r_h_serial(A, x,
                                                                       y);

    c_morpheus_resize_mat_csr_r64_i32_r_h(A, 5, 5, 13);

    c_morpheus_create_mat_csr_r64_i32_r_h(&B, 0, 0, 0);
    c_morpheus_allocate_mat_csr_from_mat_csr_r64_i32_r_h(A, B);

    // Medium matrix
    // [ 1, -1, -3,  0,  0]
    // [-2,  5,  0,  0,  0]
    // [ 0,  0,  4,  6,  4]
    // [-4,  0,  2,  7,  0]
    // [ 0,  8,  0,  0, -5]
    // CSR Equivalent:
    // Row Offsets: [0, 3, 5, 8, 11, 13]
    // Column Indices: [0, 1, 2, 0, 1, 2, 3, 4, 0, 2, 3, 1, 4]
    // Values: [1, -1, -3, -2, 5, 4, 6, 4, -4, 2, 7, 8, -5]
    c_morpheus_set_row_offsets_at_csr_r64_i32_r_h(A, 0, 0);
    c_morpheus_set_row_offsets_at_csr_r64_i32_r_h(A, 1, 3);
    c_morpheus_set_row_offsets_at_csr_r64_i32_r_h(A, 2, 5);
    c_morpheus_set_row_offsets_at_csr_r64_i32_r_h(A, 3, 8);
    c_morpheus_set_row_offsets_at_csr_r64_i32_r_h(A, 4, 11);
    c_morpheus_set_row_offsets_at_csr_r64_i32_r_h(A, 5, 13);

    c_morpheus_set_column_indices_at_csr_r64_i32_r_h(A, 0, 0);
    c_morpheus_set_column_indices_at_csr_r64_i32_r_h(A, 1, 1);
    c_morpheus_set_column_indices_at_csr_r64_i32_r_h(A, 2, 2);
    c_morpheus_set_column_indices_at_csr_r64_i32_r_h(A, 3, 0);
    c_morpheus_set_column_indices_at_csr_r64_i32_r_h(A, 4, 1);
    c_morpheus_set_column_indices_at_csr_r64_i32_r_h(A, 5, 2);
    c_morpheus_set_column_indices_at_csr_r64_i32_r_h(A, 6, 3);
    c_morpheus_set_column_indices_at_csr_r64_i32_r_h(A, 7, 4);
    c_morpheus_set_column_indices_at_csr_r64_i32_r_h(A, 8, 0);
    c_morpheus_set_column_indices_at_csr_r64_i32_r_h(A, 9, 2);
    c_morpheus_set_column_indices_at_csr_r64_i32_r_h(A, 10, 3);
    c_morpheus_set_column_indices_at_csr_r64_i32_r_h(A, 11, 1);
    c_morpheus_set_column_indices_at_csr_r64_i32_r_h(A, 12, 4);
    
    c_morpheus_set_values_at_csr_r64_i32_r_h(A, 0, 1);
    c_morpheus_set_values_at_csr_r64_i32_r_h(A, 1, -1);
    c_morpheus_set_values_at_csr_r64_i32_r_h(A, 2, -3);
    c_morpheus_set_values_at_csr_r64_i32_r_h(A, 3, -2);
    c_morpheus_set_values_at_csr_r64_i32_r_h(A, 4, 5);
    c_morpheus_set_values_at_csr_r64_i32_r_h(A, 5, 4);
    c_morpheus_set_values_at_csr_r64_i32_r_h(A, 6, 6);
    c_morpheus_set_values_at_csr_r64_i32_r_h(A, 7, 4);
    c_morpheus_set_values_at_csr_r64_i32_r_h(A, 8, -4);
    c_morpheus_set_values_at_csr_r64_i32_r_h(A, 9, 2);
    c_morpheus_set_values_at_csr_r64_i32_r_h(A, 10, 7);
    c_morpheus_set_values_at_csr_r64_i32_r_h(A, 11, 8);
    c_morpheus_set_values_at_csr_r64_i32_r_h(A, 12, -5);

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
