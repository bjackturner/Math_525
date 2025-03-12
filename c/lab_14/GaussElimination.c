#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void gaussElimination(int n, double matrix[n][n+1], double solution[n]) {
    int i, j, k;
    double factor;

    // Forward Elimination
    for (i = 0; i < n; i++) {
        // Pivoting (partial pivoting for numerical stability)
        int maxRow = i;
        for (k = i + 1; k < n; k++) {
            if (fabs(matrix[k][i]) > fabs(matrix[maxRow][i])) {
                maxRow = k;
            }
        }
        // Swap rows if needed
        if (maxRow != i) {
            for (j = 0; j <= n; j++) {
                double temp = matrix[i][j];
                matrix[i][j] = matrix[maxRow][j];
                matrix[maxRow][j] = temp;
            }
        }

        // Eliminate column elements below the pivot
        for (k = i + 1; k < n; k++) {
            factor = matrix[k][i] / matrix[i][i];
            for (j = i; j <= n; j++) {
                matrix[k][j] -= factor * matrix[i][j];
            }
        }
    }

    // Back Substitution
    for (i = n - 1; i >= 0; i--) {
        solution[i] = matrix[i][n];
        for (j = i + 1; j < n; j++) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
    }
}

// Example usage
int main() {
    int n = 3;
    double matrix[3][4] = {
        {2, -1, 1, 8},  // 2x - y +  z =  8
        {-3, -1, 2, -11}, // -3x - y + 2z = -11
        {-2, 1, 2, -3}   // -2x + y + 2z = -3
    };
    double solution[3];

    gaussElimination(n, matrix, solution);

    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %lf\n", i + 1, solution[i]);
    }

    return 0;
}
