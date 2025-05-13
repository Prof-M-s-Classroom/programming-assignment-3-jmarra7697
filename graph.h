#ifndef GRAPH_H
#define GRAPH_H

#include "heap.h"
#include <iostream>
#include <climits>
#include <vector>

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
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
        // sets the weight for u -> v and v -> u
    };

    void primMST() {
        std::vector<int> parent(numVertices, -1); // For storing the MST
        std::vector<int> key(numVertices, INT_MAX); // The values for picking a minimum weight
        std::vector<bool> inMST(numVertices, false); // Used to track vertices included in the MST

        // Creating a min-heap with all vertices and their keys, starting at vertex 0
        MinHeap minHeap(numVertices);
        key[0] = 0;
        minHeap.insert(0, key[0]);

        // Iterates through all adjacent vertices of u
        while (!minHeap.isEmpty()) {
            int u = minHeap.extractMin();
            inMST[u] = true;
            for (int v = 0; v < numVertices; v++) {
                int weight = adjMatrix[u][v];
                // If an edge exists and v isn't in the mst, then the weight is better than the current key
                if (weight > 0 && !inMST[v] && weight < key[v]) {
                    parent[v] = u;
                    key[v] = weight;
                    // if vertex v is in the min heap, it's inserted. if not, the key value is updated
                    if (minHeap.isInMinHeap(v)) {
                        minHeap.decreaseKey(v, key[v]);
                    } else {
                        minHeap.insert(v, key[v]);
                    }
                }
            }
        }

        // prints the edge between the parent and child vertex, then shows its specific weight
        int totalWeight = 0;
        std::cout << "MST Edges:" << std::endl;
        for (int i = 1; i < numVertices; ++i) {
            if (parent[i] != -1) {
                std::cout << parent[i] << " - " << i << " : " << adjMatrix[i][parent[i]] << std::endl;
                totalWeight += adjMatrix[i][parent[i]];
            }
        }
        std::cout << "Total Weight of MST: " << totalWeight << std::endl;


        // Once full MST has been printed, deletes both the parent and key as they are no longer needed
    };

private:
    int** adjMatrix;
    int numVertices;
};

#endif