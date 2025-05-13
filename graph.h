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
        // First allocates the array of pointers, then allocates each row,
        // and initializes all edges to zero so there's no edges.
    };
    //Destructor
    ~Graph() {
        for (int i = 0; i < numVertices; ++i) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    };
    // Deallocates each row and then deallocates the array of all pointers

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight; // Sets the weight for u -> v
        adjMatrix[v][u] = weight; // Sets the weight for v -> u
    };

    //Primary prim sort function
    void primMST() {
        int* parent = new int[numVertices]; // For storing the MST
        int* key = new int[numVertices]; // The values for picking a minimum weight

        MinHeap minHeap(numVertices); // Initializing the min heap for all vertices

        for (int v = 0; v < numVertices; ++v) { // Initializes all keys as infinite and parent as -1
            parent[v] = -1;
            key[v] = INT_MAX;
            minHeap.insert(v,key[v]);
        }

        // Starts with vertex 0 and updates key value
        key[0] = 0;
        minHeap.decreaseKey(0, key[0]);

        while (!minHeap.isEmpty()) {
            int u = minHeap.extractMin();
            for (int v = 0; v < numVertices; ++v) {
                if (adjMatrix[u][v] && minHeap.isInMinHeap(v) && adjMatrix[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = adjMatrix[u][v];
                    minHeap.decreaseKey(v, key[v]);
                }
            }
        }
        /* For loop checks if an edge exists, the vertex v isn't already in the MST, and if
        u-v's weight is cheaper than v's current key[v] value. If all 3 pass, then u becomes
        v's parent in the MST and updates v's key to the weight of the edge u-v and updates v's position. */

        int totalWeight = 0;
        std::cout << "MST Edges:" << std::endl;
        for (int i = 1; i < numVertices; ++i) {
            std::cout << parent[i] << " - " << i << " : " << adjMatrix[i][parent[i]] << std::endl; // prints the edge between the parent and child vertex, then shows its specific weight
            totalWeight += adjMatrix[i][parent[i]];
        }
        std::cout << "Total Weight of MST: " << totalWeight << std::endl;

        delete[] parent;
        delete[] key;
        // Once full MST has been printed, deletes both the parent and key as they are no longer needed
    };

private:
    int** adjMatrix;
    int numVertices;
};

#endif