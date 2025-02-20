#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "quad.h"

void quad_perimeter(quad *q){

    double perimeter, distance = 0;

    // Loop through all points
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 3; j++){

            // Save square of distance 
            int ii = q->node_map[i][0];
            distance += pow(q->node[ii][j] - q->node[i][j],2);

        }

        // Add the squared distances and reset intermediaent variable
        perimeter += sqrt(distance);
        distance = 0;
    }

    // Save to stuct
    q->perimeter = perimeter;
}