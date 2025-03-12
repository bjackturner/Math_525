#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"
#include "trimatrix.h"


int WinMain() {
    // Seed the random number generator
    srand(time(NULL));

    int n;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);  // Read matrix size

    // Create a new matrix with size n x n
    matrix mat = new_matrix(n, n);

    // Initialize the matrix with random values and set the diagonal to 1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j) {
                mat.val[i * mat.cols + j] = 1.0;  // Set diagonal to 1
            } else {
                mat.val[i * mat.cols + j] = (double)rand() / RAND_MAX;  // Random value between 0 and 1
            }
        }
    }

    // Hessenberg reduction to tridiagonal form
    trimatrix T = new_trimatrix(n);

    void Hessenberg(const matrix *A, trimatrix *T);
    Hessenberg(&mat, &T);

    printf("\n");
    printf("Original Matrix:\n");
    print_matrix(&mat);

    printf("Reduction to Tridiagonal Form:\n");
    print_trimatrix(&T);

    // QR Algorithm to find eigenvalues of T
    // which are the same as the eigenvalues of A
    void QRA(trimatrix *T);
    QRA(&T);

    printf("After QR Algorithm:\n");
    print_trimatrix(&T);


    return 0;
}