#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#ifdef _OPENMP
#include <omp.h>
#endif

void usage(const char *prog_name);
double LocalSimpsonIntergral(const double a, const double b, const int N);
double func(const double x);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        usage(argv[0]);
    }

    const int thread_count = strtol(argv[1], NULL, 10);
    const int N = strtol(argv[2], NULL, 10);

    if (thread_count < 1 || N < 1 || N % thread_count != 0) {
        usage(argv[0]);
    }

    const double a = 0.0, b = 1.0;
    double intergral = 0.0;

    const double time1 = omp_get_wtime();

    #pragma omp parallel num_threads(thread_count)
    {
        double loc_intergral = LocalSimpsonIntergral(a, b, N);
        #pragma omp critical
        intergral += loc_intergral;
    }

    const double time2 = omp_get_wtime();

    double Iex = exp(1.0);
    double err = fabs(intergral - Iex);

    printf("\nN = %i, T = %23.15e, err = %12.5e,\n", N, intergral, err);
    printf("Time = %12.5e\n\n", time2 - time1);

    return 0;
}

double LocalSimpsonIntergral(const double a, const double b, const int N) {
    
    #ifdef _OPENMP
    const int my_rank = omp_get_thread_num();
    const int thread_count = omp_get_num_threads();
    #else
    const int my_rank = 0;
    const int thread_count = 1;
    #endif

    double h = (b - a) / ((double)N);
    int local_N = N / thread_count;
    double local_a = a + my_rank * local_N * h;
    double local_b = local_a + local_N * h;

    double inter = 0;
    double x_local = local_a;

    for (int i = 1; i < local_N; i++) {
        x_local += h;
        inter += (func(x_local) + 4*func(x_local + h/2) + func(x_local + h));
    }

    return (h/6) * inter;
}

double func(const double x) {
    return (1.0 + exp(x));
}

void usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <num_threads> <num_intervals>\n", prog_name);
    exit(1);
}
