#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "quad.h"

// Read csv file for the points, don't bother with input errors for this assignment
void read_csv(const char *filename, quad *q) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[100]; // Buffer for each line
    for (int i = 0; i < 4; i++) {
        if (fgets(line, sizeof(line), file)) {
            sscanf(line, "%lf,%lf,%lf", &q->node[i][0], &q->node[i][1], &q->node[i][2]);

        } else {
            fprintf(stderr, "Error reading line %d\n", i + 1);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
}

// Create mapping of points to make math easier
void create_node_map(quad *q){

    // Ideally this would be handled by the user
    q->node_map[0][0] = 1; q->node_map[0][1] = 3; // Node 1 → (2, 4)
    q->node_map[1][0] = 0; q->node_map[1][1] = 2; // Node 2 → (1, 3)
    q->node_map[2][0] = 1; q->node_map[2][1] = 3; // Node 3 → (2, 4)
    q->node_map[3][0] = 0; q->node_map[3][1] = 2; // Node 4 → (1, 3)
}

quad create_quad(const char *filename){

    // initialize quad and read in the points from the file
    quad q;
    read_csv(filename, &q);

    // Create node map
    create_node_map(&q);

    return q;
}