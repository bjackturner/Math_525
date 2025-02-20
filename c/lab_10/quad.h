#ifndef QUAD_H
#define QUAD_H

typedef struct quad{

    // Store which nodes are next to one another 
    int node_map[4][2];

    // Store x,y,z of each node 
    double node[4][3];

    // Store other information 
    double area;
    double perimeter;
    double angles[4];

} quad;

quad create_quad(const char *filename);
void quad_area(quad *q);
void quad_perimeter(quad *q);
void quad_angles(quad *q);

#endif 