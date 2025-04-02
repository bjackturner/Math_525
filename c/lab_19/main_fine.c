#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifdef _OPENMP
#include <omp.h>
#endif

void usage(const char *prog_name);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        usage(argv[0]);
    }

    const int thread_count = strtol(argv[1], NULL, 10);
    const int N = strtol(argv[2], NULL, 10);

    if (thread_count < 1 || N < 1) {
        usage(argv[0]);
    }

    double x[N];
    srand(13); 
    for (int i = 0; i < N; i++) {
        x[i] = (rand() / (RAND_MAX + 1.0)) * 100.0;  // Random double between 0 and 100
    }

    double norm = 0.0;
    const double time1 = omp_get_wtime();

    #pragma omp parallel num_threads(thread_count)
    {
        // Step 1: Initialize the array values to -1
        #pragma omp for
        for (int i = 0; i < N; i++) {
            x[i] = -1.0;
        }

        // Step 2: Compute the norm (sum of absolute values)
        #pragma omp for reduction(+: norm)
        for (int i = 0; i < N; i++) {
            norm += fabs(x[i]);
        }

        // Step 3: Normalize the array
        #pragma omp for
        for (int i = 0; i < N; i++) {
            x[i] = x[i] / norm;
        }
    }

    const double time2 = omp_get_wtime();

    // Printing results
    printf("\nN = %i, x(0) = %23.15lf, x(n-1) = %12.5lf, norm = %12.5lf\n", N, x[0], x[N-1], norm);
    printf("Time = %12.5e\n\n", time2 - time1);

    return 0;
}

void usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <num_threads> <num_intervals>\n", prog_name);
    exit(1);
}
