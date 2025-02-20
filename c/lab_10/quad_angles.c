#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "quad.h"

void quad_angles(quad *q){

    // Define the vectors between points
    double vec_1[3]; double mag_1;
    double vec_2[3]; double mag_2;
    double dot_product;

    // Loop through all points
    for (int i = 0; i < 4; i++){

        // Reset vars
        mag_1 = 0.0; mag_2 = 0.0; dot_product = 0.0;

        for (int j = 0; j < 3; j++){

            // Get index of adjacent points
            int i1 = q->node_map[i][0];
            int i2 = q->node_map[i][1];

            // Find vectors from current point to adjacent points
            vec_1[j] = q->node[i1][j] - q->node[i][j];
            vec_2[j] = q->node[i2][j] - q->node[i][j];

            // Save for normalization 
            mag_1 += pow(vec_1[j],2);
            mag_2 += pow(vec_2[j],2);

        }

        // Compute dot product
        for (int j = 0; j < 3; j++){
            dot_product += vec_1[j] * vec_2[j];
        }

        // Use dot product of vectors to find angle
        q->angles[i] = acos(dot_product / (mag_1 * mag_2));

    }
}