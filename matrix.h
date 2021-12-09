/**
 * \file        matrix.h
 * \brief       Header file which holds function prototypes related to matrix functions.
 * \author      P. Prunty
 * \version     1.0
 * \date        2019-11-19
 */
#ifndef MATRIX_H_7BZWC1IU
#define MATRIX_H_7BZWC1IU

// Function prototypes
void print_sq_matrix(double *const *const A, const int dim);

int alloc_cont_mem_sq_mat(double ***A, const int N);

#endif /* end of include guard: MATRIX_H_7BZWC1IU */
