#include "Fcl_C.hpp"

#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef fcl_mat_dyn_r64_i32_r_h dyn;
typedef fcl_mat_coo_r64_i32_r_h coo;
typedef fcl_mat_csr_r64_i32_r_h csr;
typedef fcl_mat_dia_r64_i32_r_h dia;
typedef fcl_vec_dense_r64_i32_r_h vec;

typedef fcl_mat_coo_hostmirror_r64_i32_r_h mirror_coo;
typedef fcl_mat_csr_hostmirror_r64_i32_r_h mirror_csr;
typedef fcl_mat_dia_hostmirror_r64_i32_r_h mirror_dia;
typedef fcl_vec_dense_hostmirror_r64_i32_r_h mirror_vec;
typedef fcl_mat_dyn_hostmirror_r64_i32_r_h mirror_dyn;

coo* ref_coo(){
  coo *A;
  c_morpheus_create_mat_coo_r64_i32_r_h(&A, 4, 3, 6);
  // COO Equivalent:
  // Row Offsets: [0, 1, 2, 0, 2, 1]
  // Column Indices: [0, 1, 2, 0, 2, 1]
  // Values: [10, 20, 30, 40, 50, 60]
  c_morpheus_set_row_indices_at_coo_r64_i32_r_h(A, 0, 0);
  c_morpheus_set_row_indices_at_coo_r64_i32_r_h(A, 1, 1);
  c_morpheus_set_row_indices_at_coo_r64_i32_r_h(A, 2, 2);
  c_morpheus_set_row_indices_at_coo_r64_i32_r_h(A, 3, 0);
  c_morpheus_set_row_indices_at_coo_r64_i32_r_h(A, 4, 2);
  c_morpheus_set_row_indices_at_coo_r64_i32_r_h(A, 5, 1);
  
  c_morpheus_set_column_indices_at_coo_r64_i32_r_h(A, 0, 0);
  c_morpheus_set_column_indices_at_coo_r64_i32_r_h(A, 1, 1);
  c_morpheus_set_column_indices_at_coo_r64_i32_r_h(A, 2, 2);
  c_morpheus_set_column_indices_at_coo_r64_i32_r_h(A, 3, 0);
  c_morpheus_set_column_indices_at_coo_r64_i32_r_h(A, 4, 2);
  c_morpheus_set_column_indices_at_coo_r64_i32_r_h(A, 5, 1);
  
  c_morpheus_set_values_at_coo_r64_i32_r_h(A, 0, 10);
  c_morpheus_set_values_at_coo_r64_i32_r_h(A, 1, 20);
  c_morpheus_set_values_at_coo_r64_i32_r_h(A, 2, 30);
  c_morpheus_set_values_at_coo_r64_i32_r_h(A, 3, 40);
  c_morpheus_set_values_at_coo_r64_i32_r_h(A, 4, 50);
  c_morpheus_set_values_at_coo_r64_i32_r_h(A, 5, 60);
  
  return A;
}

csr* ref_csr(){
  csr *A;
  c_morpheus_create_mat_csr_r64_i32_r_h(&A, 4, 3, 6);
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
  
  return A;
}

dia* ref_dia(){
  dia *A;

  c_morpheus_create_mat_dia_r64_i32_r_h(&A, 4, 3, 6, 3);

  // Diagonal offsets
  c_morpheus_set_diagonal_offests_at_dia_r64_i32_r_h(A, 0, -2);
  c_morpheus_set_diagonal_offests_at_dia_r64_i32_r_h(A, 1, 0);
  c_morpheus_set_diagonal_offests_at_dia_r64_i32_r_h(A, 2, 1);
  // First Diagonal
  c_morpheus_set_values_at_dia_r64_i32_r_h(A, 0, 0, -1);
  c_morpheus_set_values_at_dia_r64_i32_r_h(A, 1, 0, -1);
  c_morpheus_set_values_at_dia_r64_i32_r_h(A, 2, 0, 40);
  c_morpheus_set_values_at_dia_r64_i32_r_h(A, 3, 0, 60);
  // Second Diagonal
  c_morpheus_set_values_at_dia_r64_i32_r_h(A, 0, 1, 10);
  c_morpheus_set_values_at_dia_r64_i32_r_h(A, 1, 1, 0);
  c_morpheus_set_values_at_dia_r64_i32_r_h(A, 2, 1, 50);
  c_morpheus_set_values_at_dia_r64_i32_r_h(A, 3, 1, -2);
  // Third Diagonal
  c_morpheus_set_values_at_dia_r64_i32_r_h(A, 0, 2, 20);
  c_morpheus_set_values_at_dia_r64_i32_r_h(A, 1, 2, 30);
  c_morpheus_set_values_at_dia_r64_i32_r_h(A, 2, 2, -3);
  c_morpheus_set_values_at_dia_r64_i32_r_h(A, 3, 2, -3);
  
  return A;
}

int main() {
  c_morpheus_initialize_without_args();
  { 
    // Reference Matrix
    //    [10 20 00]
    //    [00 00 30]
    //    [40 00 50]
    //    [00 60 00]
    
    coo *refcoo = ref_coo();
    csr *refcsr = ref_csr();
    dia *refdia = ref_dia();
    
    { 
      mirror_coo *mirror = c_morpheus_create_mirror_mat_coo_r64_i32_r_h_serial(refcoo);
      coo *shallow_mirror = c_morpheus_create_mirror_container_mat_coo_r64_i32_r_h_serial(refcoo);

      c_morpheus_copy_mat_coo_to_mat_coo_hostmirror_r64_i32_r_h_serial(refcoo, mirror);
      c_morpheus_copy_mat_coo_to_mat_coo_hostmirror_r64_i32_r_h_serial(refcoo, shallow_mirror);

      c_morpheus_set_values_at_coo_r64_i32_r_h(refcoo, 5, -15);
      c_morpheus_print_mat_coo_r64_i32_r_h(mirror);
      c_morpheus_print_mat_coo_r64_i32_r_h(shallow_mirror);
      c_morpheus_set_values_at_coo_r64_i32_r_h(refcoo, 5, 60);
      
      c_morpheus_destroy_mat_coo_r64_i32_r_h(&mirror);
      c_morpheus_destroy_mat_coo_r64_i32_r_h(&shallow_mirror);
    }

    { 
      mirror_csr *mirror = c_morpheus_create_mirror_mat_csr_r64_i32_r_h_serial(refcsr);

      c_morpheus_copy_mat_csr_to_mat_csr_hostmirror_r64_i32_r_h_serial(refcsr, mirror);
      c_morpheus_set_values_at_csr_r64_i32_r_h(refcsr, 5, -15);
      c_morpheus_print_mat_csr_r64_i32_r_h(mirror);
      c_morpheus_set_values_at_csr_r64_i32_r_h(refcsr, 5, 60);
      c_morpheus_destroy_mat_csr_r64_i32_r_h(&mirror);
    }

    { 
      mirror_dia *mirror = c_morpheus_create_mirror_mat_dia_r64_i32_r_h_serial(refdia);

      c_morpheus_copy_mat_dia_to_mat_dia_hostmirror_r64_i32_r_h_serial(refdia, mirror);
      c_morpheus_set_values_at_dia_r64_i32_r_h(refdia, 3, 0, -15);
      c_morpheus_print_mat_dia_r64_i32_r_h(mirror);
      c_morpheus_set_values_at_dia_r64_i32_r_h(refdia, 3, 0, 60);
      c_morpheus_destroy_mat_dia_r64_i32_r_h(&mirror);
    }

    c_morpheus_destroy_mat_coo_r64_i32_r_h(&refcoo);
    c_morpheus_destroy_mat_csr_r64_i32_r_h(&refcsr);
    c_morpheus_destroy_mat_dia_r64_i32_r_h(&refdia);
    
  }
  c_morpheus_finalize();

  return 0;
}
