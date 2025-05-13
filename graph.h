#ifndef GRAPH_H
#define GRAPH_H

#include "heap.h"
#include <iostream>
#include <climits>

class Graph {
public:
    // Constructor
    Graph(int vertices) {
        numVertices = vertices;
        adjMatrix = new int*[vertices];
        for (int i = 0; i < vertices; ++i) {
            adjMatrix[i] = new int[vertices];
            for (int j = 0; j < vertices; ++j) {
                adjMatrix[i][j] = 0;
            }
        }
        // Constructor first allocates the array of pointers, then allocates each row,
        // and initializes all edges to zero so there's no edges.
    };
    //Destructor
    ~Graph() {
        for (int i = 0; i < numVertices; ++i) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    };
    // Destructor deallocates each row and then deallocates the array of all pointers

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight; // Sets the weight for u -> v
        adjMatrix[v][u] = weight; // Sets the weight for v -> u
    };

    //Primary prim sort function
    void primMST();  // Must print MST edges and total weight

private:
    int** adjMatrix;
    int numVertices;
};

#endif