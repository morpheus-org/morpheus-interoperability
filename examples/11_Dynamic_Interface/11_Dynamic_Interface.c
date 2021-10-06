#include "Fcl_C.hpp"

#include <stdio.h>
#include <string.h>
typedef fcl_mat_dyn_r64_i32_r_h dyn;
typedef fcl_mat_coo_r64_i32_r_h coo;
typedef fcl_mat_csr_r64_i32_r_h csr;
typedef fcl_mat_dia_r64_i32_r_h dia;
typedef fcl_vec_dense_r64_i32_r_h vec;

int main() {
  c_morpheus_initialize_without_args();
  {
    dia *Adia;
    csr *Acsr;
    vec *x, *y;
    dyn *A;
    
    c_morpheus_create_mat_dia_r64_i32_r_h(&Adia, 4, 3, 6, 3);

    // Diagonal offsets
    c_morpheus_set_diagonal_offests_at_dia_r64_i32_r_h(Adia, 0, -2);
    c_morpheus_set_diagonal_offests_at_dia_r64_i32_r_h(Adia, 1, 0);
    c_morpheus_set_diagonal_offests_at_dia_r64_i32_r_h(Adia, 2, 1);
    // First Diagonal
    c_morpheus_set_values_at_dia_r64_i32_r_h(Adia, 0, 0, -1);
    c_morpheus_set_values_at_dia_r64_i32_r_h(Adia, 1, 0, -1);
    c_morpheus_set_values_at_dia_r64_i32_r_h(Adia, 2, 0, 40);
    c_morpheus_set_values_at_dia_r64_i32_r_h(Adia, 3, 0, 60);
    // Second Diagonal
    c_morpheus_set_values_at_dia_r64_i32_r_h(Adia, 0, 1, 10);
    c_morpheus_set_values_at_dia_r64_i32_r_h(Adia, 1, 1, 0);
    c_morpheus_set_values_at_dia_r64_i32_r_h(Adia, 2, 1, 50);
    c_morpheus_set_values_at_dia_r64_i32_r_h(Adia, 3, 1, -2);
    // Third Diagonal
    c_morpheus_set_values_at_dia_r64_i32_r_h(Adia, 0, 2, 20);
    c_morpheus_set_values_at_dia_r64_i32_r_h(Adia, 1, 2, 30);
    c_morpheus_set_values_at_dia_r64_i32_r_h(Adia, 2, 2, -3);
    c_morpheus_set_values_at_dia_r64_i32_r_h(Adia, 3, 2, -3);

    c_morpheus_create_mat_csr_r64_i32_r_h(&Acsr, 4, 3, 6);
    // Simple Matrix
    //    [10 20 00]
    //    [00 00 30]
    //    [40 00 50]
    //    [00 60 00]
    // CSR Equivalent:
    // Row Offsets: [0, 2, 3, 5, 6]
    // Column Indices: [0, 1, 2, 0, 2, 1]
    // Values: [10, 20, 30, 40, 50, 60]
    c_morpheus_set_row_offsets_at_csr_r64_i32_r_h(Acsr, 0, 0);
    c_morpheus_set_row_offsets_at_csr_r64_i32_r_h(Acsr, 1, 2);
    c_morpheus_set_row_offsets_at_csr_r64_i32_r_h(Acsr, 2, 3);
    c_morpheus_set_row_offsets_at_csr_r64_i32_r_h(Acsr, 3, 5);
    c_morpheus_set_row_offsets_at_csr_r64_i32_r_h(Acsr, 4, 6);
    
    c_morpheus_set_column_indices_at_csr_r64_i32_r_h(Acsr, 0, 0);
    c_morpheus_set_column_indices_at_csr_r64_i32_r_h(Acsr, 1, 1);
    c_morpheus_set_column_indices_at_csr_r64_i32_r_h(Acsr, 2, 2);
    c_morpheus_set_column_indices_at_csr_r64_i32_r_h(Acsr, 3, 0);
    c_morpheus_set_column_indices_at_csr_r64_i32_r_h(Acsr, 4, 2);
    c_morpheus_set_column_indices_at_csr_r64_i32_r_h(Acsr, 5, 1);
    
    c_morpheus_set_values_at_csr_r64_i32_r_h(Acsr, 0, 10);
    c_morpheus_set_values_at_csr_r64_i32_r_h(Acsr, 1, 20);
    c_morpheus_set_values_at_csr_r64_i32_r_h(Acsr, 2, 30);
    c_morpheus_set_values_at_csr_r64_i32_r_h(Acsr, 3, 40);
    c_morpheus_set_values_at_csr_r64_i32_r_h(Acsr, 4, 50);
    c_morpheus_set_values_at_csr_r64_i32_r_h(Acsr, 5, 60);

    c_morpheus_create_vec_dense_r64_i32_r_h(&x, 3, 3);
    c_morpheus_create_vec_dense_r64_i32_r_h(&y, 4, 0);

    c_morpheus_create_mat_dyn_from_mat_r64_i32_r_h(Adia, DIA_FORMAT, &A);

    c_morpheus_multiply_mat_dyn_vec_dense_vec_dense_r64_i32_r_h_serial(A, x,
                                                                       y);

    c_morpheus_print_mat_dyn_r64_i32_r_h(A);

    c_morpheus_assign_mat_dyn_from_mat_r64_i32_r_h(Acsr, CSR_FORMAT, A);
    c_morpheus_print_mat_dyn_r64_i32_r_h(A);
    // c_morpheus_multiply_mat_dia_vec_dense_vec_dense_r64_i32_r_h_serial(A, x,
    //                                                                    y);

    // c_morpheus_print_mat_dia_r64_i32_r_h(A);

    // c_morpheus_resize_mat_dia_r64_i32_r_h(A, 4, 3, 6, 5);

    //  // Diagonal offsets
    // c_morpheus_set_diagonal_offests_at_dia_r64_i32_r_h(A, 0, -3);
    // c_morpheus_set_diagonal_offests_at_dia_r64_i32_r_h(A, 1, -2);
    // c_morpheus_set_diagonal_offests_at_dia_r64_i32_r_h(A, 2, -1);
    // c_morpheus_set_diagonal_offests_at_dia_r64_i32_r_h(A, 3, 0);
    // c_morpheus_set_diagonal_offests_at_dia_r64_i32_r_h(A, 4, 2);
    // // First Diagonal
    // c_morpheus_set_values_at_dia_r64_i32_r_h(A, 0, 0, -1);
    // c_morpheus_set_values_at_dia_r64_i32_r_h(A, 1, 0, -1);
    // c_morpheus_set_values_at_dia_r64_i32_r_h(A, 2, 0, -1);
    // c_morpheus_set_values_at_dia_r64_i32_r_h(A, 3, 0, 40);
    // // Second Diagonal
    // c_morpheus_set_values_at_dia_r64_i32_r_h(A, 0, 1, -2);
    // c_morpheus_set_values_at_dia_r64_i32_r_h(A, 1, 1, -2);
    // c_morpheus_set_values_at_dia_r64_i32_r_h(A, 2, 1, 0);
    // c_morpheus_set_values_at_dia_r64_i32_r_h(A, 3, 1, 50);
    // // Third Diagonal
    // c_morpheus_set_values_at_dia_r64_i32_r_h(A, 0, 2, -3);
    // c_morpheus_set_values_at_dia_r64_i32_r_h(A, 1, 2, 0);
    // c_morpheus_set_values_at_dia_r64_i32_r_h(A, 2, 2, 0);
    // c_morpheus_set_values_at_dia_r64_i32_r_h(A, 3, 2, 60);
    // // Fourth Diagonal
    // c_morpheus_set_values_at_dia_r64_i32_r_h(A, 0, 3, 10);
    // c_morpheus_set_values_at_dia_r64_i32_r_h(A, 1, 3, 0);
    // c_morpheus_set_values_at_dia_r64_i32_r_h(A, 2, 3, 30);
    // c_morpheus_set_values_at_dia_r64_i32_r_h(A, 3, 3, -4);
    // // Fifth Diagonal
    // c_morpheus_set_values_at_dia_r64_i32_r_h(A, 0, 4, 20);
    // c_morpheus_set_values_at_dia_r64_i32_r_h(A, 1, 4, -5);
    // c_morpheus_set_values_at_dia_r64_i32_r_h(A, 2, 4, -5);
    // c_morpheus_set_values_at_dia_r64_i32_r_h(A, 3, 4, -5);

    // c_morpheus_print_mat_dia_r64_i32_r_h(A);


    // c_morpheus_create_mat_dia_r64_i32_r_h(&B, 0, 0, 0, 0);
    // c_morpheus_allocate_mat_dia_from_mat_dia_r64_i32_r_h(A, B);
    // // Make sure offsets are same in order to get same positional values
    // c_morpheus_set_diagonal_offests_at_dia_r64_i32_r_h(B, 0, -3);
    // c_morpheus_set_diagonal_offests_at_dia_r64_i32_r_h(B, 1, -2);
    // c_morpheus_set_diagonal_offests_at_dia_r64_i32_r_h(B, 2, -1);
    // c_morpheus_set_diagonal_offests_at_dia_r64_i32_r_h(B, 3, 0);
    // c_morpheus_set_diagonal_offests_at_dia_r64_i32_r_h(B, 4, 2);
    // c_morpheus_set_values_at_dia_r64_i32_r_h(B, 0, 4, 120);

    // c_morpheus_print_mat_dia_r64_i32_r_h(B);
    // c_morpheus_print_mat_dia_r64_i32_r_h(A);

    // printf("%d\t%d\t%d\t%d\t%d\n", c_morpheus_nrows_mat_dia_r64_i32_r_h(A),
    //                                c_morpheus_ncols_mat_dia_r64_i32_r_h(A),
    //                                c_morpheus_nnnz_mat_dia_r64_i32_r_h(A),
    //                                c_morpheus_ndiags_mat_dia_r64_i32_r_h(A),
    //                                c_morpheus_alignment_mat_dia_r64_i32_r_h(A));

    // printf("%d\t%d\t%d\t%d\t%d\n", c_morpheus_nrows_mat_dia_r64_i32_r_h(B),
    //                                c_morpheus_ncols_mat_dia_r64_i32_r_h(B),
    //                                c_morpheus_nnnz_mat_dia_r64_i32_r_h(B),
    //                                c_morpheus_ndiags_mat_dia_r64_i32_r_h(B),
    //                                c_morpheus_alignment_mat_dia_r64_i32_r_h(B));
    
    // c_morpheus_set_nrows_mat_dia_r64_i32_r_h(A, 15);
    // c_morpheus_set_ncols_mat_dia_r64_i32_r_h(A, 22);
    // c_morpheus_set_nnnz_mat_dia_r64_i32_r_h(A, 111);
    // c_morpheus_set_ndiags_mat_dia_r64_i32_r_h(A, 8);
    // c_morpheus_set_alignment_mat_dia_r64_i32_r_h(A, 64);

    // printf("%d\t%d\t%d\t%d\t%d\n", c_morpheus_nrows_mat_dia_r64_i32_r_h(A),
    //                                c_morpheus_ncols_mat_dia_r64_i32_r_h(A),
    //                                c_morpheus_nnnz_mat_dia_r64_i32_r_h(A),
    //                                c_morpheus_ndiags_mat_dia_r64_i32_r_h(A),
    //                                c_morpheus_alignment_mat_dia_r64_i32_r_h(A));

    // printf("dia Enum: %d\n", c_morpheus_format_enum_mat_dia_r64_i32_r_h(A));

    // printf("dia Index: %d\n", c_morpheus_format_index_mat_dia_r64_i32_r_h(A));

    c_morpheus_destroy_mat_dia_r64_i32_r_h(&Adia);
    c_morpheus_destroy_vec_dense_r64_i32_r_h(&x);
    c_morpheus_destroy_vec_dense_r64_i32_r_h(&y);
  }
  c_morpheus_finalize();

  return 0;
}
