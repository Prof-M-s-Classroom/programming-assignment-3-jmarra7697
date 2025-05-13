[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/K_t6ffJX)
# Prim's Algorithm with Min Heap and Adjacency Matrix

## Author
Jake Marra (827952717)

## Description
Using both heap.h and graph.h, my program implements Prim's algorithm to find the MST of a weighted undirected graph.
My heap.h file implements a custom min-heap class that selects the smallest vertex with the smallest edge weight.
My graph.h file implements an adjacency matrix to represent the MST graph, along with the logic of the Prim algorithm.
I also developed a couple helper functions, primarily swap() and minHeapHelper() that swaps and updates the positions of
2 nodes in a heap, and restores the min-heap property from a given index respectively.


## Files
- graph.h / graph.cpp
- heap.h / heap.cpp
- main.cpp (unchanged)
- README.md

## How to Compile and Run
This project was developed and tested in CLion.  
Run directly from the IDE.

## Time Complexity Analysis
| Operation            | Time Complexity |
|----------------------|-----------------|
| Insert in MinHeap    | O(logN)         |
| Extract Min          | O(logN)         |
| Decrease Key         | O(logN)         |
| Prim’s MST Overall   | O(N^2)          |

* Insert in MinHeap is O(logN), or, more specifically, O(logV), because of a while loop that called the swap() function
* Extract Min is O(LogN) or O(logV) because of recursive function minHeapHelper holding the MST's integrity
* Decrease Key is O(logN) or O(logV) because of a while loop that calls the swap() function if the new node's key is smaller than its parent's key
* Prim's MST overall is O(N^2) primarily because of the primMST() function which has a nested for loop in a while loop that updates the weight of each vertex edge


## Test Case Description
I used a couple test cases to double-check that my code works for extra cases.
**Input 1 (Two vertices, one edge):**
Graph g(2);
g.addEdge(0, 1, 5);
g.primMST();
- Correctly outputted with 0 - 1 : 5 and a total weight of 5

**Input 2 (Graph with a cycle):**
Graph g(4);
g.addEdge(0, 1, 1);
g.addEdge(0, 3, 3);
g.addEdge(1, 2, 2);
g.addEdge(2, 3, 4);
g.primMST();
- Correctly outputted with 0 - 1 : 1, 1 - 2 : 2, 0 - 3 : 3, and a total weight of 6

**Input 3 (Generic extra test case):**
Graph g(5);
g.addEdge(0, 1, 4);
g.addEdge(0, 2, 1);
g.addEdge(1, 2, 2);
g.addEdge(1, 3, 5);
g.addEdge(2, 3, 8);
g.addEdge(2, 4, 3);
g.addEdge(3, 4, 6);
g.primMST();
- Correctly outputted with 2 - 1 : 2, 0 - 2 : 1, 1 - 3 : 5, 2 - 4 : 3, with a total weight of 11

## Challenges Faced
During my first iteration of the program, I was having some issues getting the total weight of MST because I kept getting the following input:
0 - 1 : 2
4 - 2 : 7
0 - 3 : 6
-1 - 4 : 0
Total Weight of MST: 15

For whatever reason after the first edge the weight would just start spouting random numbers. The edges and vertices were outputting correctly, my weight was just being weird.I ended up using vector logic 
and had to revamp the primMST() function so it would properly give me the right output with an MST weight of 16. You might be able to see that process in my past commits? I forget if I published the original 
primMST to the repository. Probably.