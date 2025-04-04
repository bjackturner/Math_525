#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <string.h>

void usage(const char* prog_name);
double AdaptiveInt(const double a, const double b, const double TOL, char* filename, const int num_threads);
double Q(const double a, const double b);
double f(const double x);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        usage(argv[0]);
    }

    const int thread_count = strtol(argv[1], NULL, 10);
    const double TOL = strtod(argv[2], NULL);
    
    if (thread_count <= 0 || TOL < 5.0e-16) {
        usage(argv[0]);
    }

    // Create a file to store thread count
    FILE* file = fopen("thread_count.data", "w");
    fprintf(file, "%i\n", thread_count);
    fclose(file);

    const double a = -2.0;
    const double b =  4.0;
    const double Iex = 0.4147421694070212;
    double I = 0.0;

    // Create individual files for each thread
    for (int i = 1; i <= thread_count; i++) {
        char filename[36];
        snprintf(filename, sizeof(filename), "quadrature_%d.data", i);
        FILE* file = fopen(filename, "w");
        fclose(file);
    }

    // Parallel integration using OpenMP
    #pragma omp parallel num_threads(thread_count)
    {
        const int my_rank = omp_get_thread_num();

        // Create a unique file for each thread
        char filename[36];
        snprintf(filename, sizeof(filename), "quadrature_%d.data", my_rank + 1);
        FILE* file = fopen(filename, "a");

        // Divide the interval among threads
        const double width = (b - a) / ((double)thread_count);
        const double a_local = a + my_rank * width;
        const double b_local = a_local + width;
        const double TOL_local = TOL / ((double)thread_count);

        // Compute integral for local subinterval
        double I_thread = AdaptiveInt(a_local, b_local, TOL_local, filename, thread_count);
        fclose(file);

        // Accumulate results using OpenMP critical section
        #pragma omp critical
        I += I_thread;
    }

    // Print results
    printf("\n");
    printf("thread_count = %i\n", thread_count);
    printf("TOL = %24.15e\n", TOL);
    printf("I = %24.15e\n", I);
    printf("err = %24.15e\n", fabs(I - Iex));
    printf("\n");

    return 0;
}

void usage(const char* prog_name) {
    fprintf(stderr, "Usage: %s <num_threads> <TOL>\n", prog_name);
    fprintf(stderr, "num_threads should be positive\n");
    fprintf(stderr, "TOL should be positive\n");
    exit(1);
}

double AdaptiveInt(const double a, const double b, const double TOL, char* filename, const int num_threads) {
    double Qab = Q(a, b);
    const double c = 0.5 * (a + b);
    double Qac = Q(a, c);
    double Qcb = Q(c, b);

    FILE* file = fopen(filename, "a");
    fprintf(file, "%24.15e %24.15e\n", a, b);
    fclose(file);

    const double one_over_15 = 1.0 / 15.0;
    const double error_est = one_over_15 * fabs(Qac + Qcb - Qab);

    if (error_est < TOL) {
        return Qac + Qcb;
    } else {
        double I1 = 0.0, I2 = 0.0;

        #pragma omp task shared(I1) if (num_threads > 1)
        I1 = AdaptiveInt(a, c, 0.5 * TOL, filename, num_threads / 2);

        #pragma omp task shared(I2) if (num_threads > 1)
        I2 = AdaptiveInt(c, b, 0.5 * TOL, filename, num_threads / 2);

        #pragma omp taskwait
        return I1 + I2;
    }
}

double Q(const double a, const double b) {
    const double one_sixth = 1.0 / 6.0;
    const double c = 0.5 * (a + b);
    return one_sixth * (b - a) * (f(a) + 4.0 * f(c) + f(b));
}

double f(const double x) {
    const double beta = 10.0;
    return exp(-pow(beta * x, 2)) + sin(x);
}

