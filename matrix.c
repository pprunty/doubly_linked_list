/**
 * \file 			matrix.c
 * \brief 			A file which allocates contiguous memory for a 2d array (matrix) and prints each node (matrix) in the linked list
 * \author 			P. Prunty
 * \version 		1.0
 * \date 			2019-11-29
 */
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

/*! \brief      A simple function used to allocate contiguous memory for a given matrix.
 *  \param A    A here represents a triple pointer
 *  \param N    N. The size of the square matrix.
 */
int alloc_cont_mem_sq_mat(double ***A, const int N) {


    /*
     * Two arrays - one of pointers and one contiguous
     * array to contain the data.
     */

    // Allocate memory for an array of pointers
    double **datapointers = malloc(N * sizeof(double *));

    // Error check to determine if memory has been allocated successfully
    if (datapointers == NULL) {
        perror("Error allocating memory for datapointers");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for contiguous n x n block of data points
    double *data = malloc(N * N * sizeof(double));

    // Error check to determine if memory has been allocated successfully
    if (data == NULL) {
        perror("Error allocating memory for data");
        exit(EXIT_FAILURE);
    }

    // This N is each dimension in the .txt file (i.e the first N=7 for data.txt) so this loop goes through data pointers
    for (int i = 0; i < N; i++) {
        datapointers[i] = data + i * N;
    }

    *A = datapointers;

    return 0;

}

/*! \brief      A simple function used to print a two dimensional matrix
 *  \param B    The n x n square matrix
 *  \param dim  The matrix dimensions. In this case it is just n
 */
void print_sq_matrix(double *const *const B, const int dim) {

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (j != 0) printf("\t");
            printf("%0.2lf", B[i][j]);  //<! Print element of matrix to two decimal places
        }
        printf("\n");   //<! Go to the next line after row is filled
    }

    printf("\n");  //<! When matrix is complete make space for next matrix so data is clear
}
