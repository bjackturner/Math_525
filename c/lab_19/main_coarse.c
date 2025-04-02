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

    if (thread_count < 1 || N < 1 || N % thread_count != 0) {
        usage(argv[0]);
    }

    double x[N];
    srand(13); 
    for (int i = 0; i < N; i++) {
        x[i] = (rand() / (RAND_MAX + 1.0)) * 100.0;  // Random double between 0 and 100
    }

    double norm = 0.0;
    const double time1 = omp_get_wtime();

    #pragma omp parallel num_threads(thread_count) reduction(+:norm)
    { 
        const int my_rank = omp_get_thread_num();

        const int N_per_thread = N / thread_count;
        const int istart = my_rank * N_per_thread;
        const int iend = (my_rank + 1) * N_per_thread - 1;

        double norm_thread = 0.0;
        for (int i = istart; i <= iend; i++) 
        { 
            norm_thread += pow(fabs(x[i]),2); // for norm-2
            // norm_thread = fabs(x[i]) > norm_thread ? fabs(x[i]) : norm_thread // For norm max
        }

        norm += norm_thread; // For norm-2
    }

    norm = sqrt(norm); // For norm-2

    // Normalization after norm calculation
    #pragma omp parallel num_threads(thread_count)
    {
        const int my_rank = omp_get_thread_num();
        const int N_per_thread = N / thread_count;
        const int istart = my_rank * N_per_thread;
        const int iend = (my_rank + 1) * N_per_thread - 1;

        for (int i = istart; i <= iend; i++) 
        { 
            x[i] = x[i] / norm; 
        } 
    }

    const double time2 = omp_get_wtime();

    printf("\nN = %i, x(0) = %23.15lf, x(n-1) = %12.5lf, norm = %12.5lf\n", N, x[0], x[N-1], norm);
    printf("Time = %12.5e\n\n", time2 - time1);

    return 0;
}

void usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <num_threads> <num_intervals>\n", prog_name);
    exit(1);
}
