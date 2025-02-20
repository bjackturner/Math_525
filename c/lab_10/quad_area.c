#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "quad.h"

void quad_area(quad *q){

    // Define the vectors between points
    double vec_1[3];
    double vec_2[3];

    // Save the points next to the point 1
    int i1 = q->node_map[0][0];
    int i2 = q->node_map[0][1];

    // Because of the point map, only three points are required
    for (int j = 0; j < 3; j++){

        // Save the displacement between point 1 and its two neighbors
        vec_1[j] = q->node[i1][j] - q->node[0][j];
        vec_2[j] = q->node[i2][j] - q->node[0][j];
    }

    // Calculate the components of the cross product
    double cx = vec_1[1] * vec_2[2] - vec_1[2] * vec_2[1];
    double cy = vec_1[2] * vec_2[0] - vec_1[0] * vec_2[2];
    double cz = vec_1[0] * vec_2[1] - vec_1[1] * vec_2[0];

    // Calculate the magnitude of the cross product vector
    q->area = sqrt(cx * cx + cy * cy + cz * cz);
}