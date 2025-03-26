#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#ifdef _OPENMP
#include <omp.h>
#endif

void usage(const char* prog_name) {
    fprintf(stderr, "Usage: %s <thread_count> <N>\n", prog_name);
    fprintf(stderr, "  thread_count should be positive.\n");
    fprintf(stderr, "  N should be positive.\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        usage(argv[0]);
    }

    const int thread_count = strtol(argv[1], NULL, 10);
    const int N = strtol(argv[2], NULL, 10);

    if (thread_count <= 0 || N <= 0) {
        usage(argv[0]);
    }

    srand(time(NULL));

    const double time1 = omp_get_wtime();
    double total_sum = 0.0;

    #pragma omp parallel for num_threads(thread_count) reduction(+:total_sum)
    for (int i = 1; i <= N; i++) {
        double x = ((double)rand()) / RAND_MAX;  // Generate a random number in [0,1]
        double sum = 1.0;
        for (int k = 1; k <= 200; k++) {
            sum += sqrt(pow(x, k + 2) + pow(x, k + 1) + pow(x, k) + pow(x, k - 1));
        }
        total_sum += sum;
    }

    const double time2 = omp_get_wtime();
    const double clock_time = time2 - time1;

    printf("With %d threads, clock_time = %11.5e (sec)\n", thread_count, clock_time);
    printf("Total sum: %f\n", total_sum);
    fflush(stdout);

    return 0;
}
