#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "quad.h"

void print_quad_info(const quad *q);

int WinMain() {

    // Compute data
    quad q = create_quad(".\\Math_525\\c\\lab_10\\points.csv");

    for (int i = 0; i < 4; i++) {
        printf("Point %d:", i + 1);
        for (int j = 0; j < 3; j++) {
            printf(" %.2lf", q.node[i][j]);  // Use dot notation instead of -> 
        }
        printf("\n");
    }

    quad_area(&q);
    quad_perimeter(&q);
    quad_angles(&q);

    // Print data
    print_quad_info(&q);

    return 0;
}

void print_quad_info(const quad *q) {

    // Print the area, perimeter, and angles of the quad
    printf("\nArea: %.2lf\n", q->area);
    printf("Perimeter: %.2lf\n", q->perimeter);

    // Printing the angles stored in the quad (assuming you have calculated and stored them)
    printf("\nAngles (in degrees):\n");
    for (int i = 0; i < 4; i++) {
        printf("Angle %d: %.4lf\n", i + 1, q->angles[i]*180/3.141592);  // You need to have angles calculated and stored in your struct
    }
}