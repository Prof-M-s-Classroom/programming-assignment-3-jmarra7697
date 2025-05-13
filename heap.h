#ifndef HEAP_H
#define HEAP_H

class MinHeap {
public:

    // Constructor
    MinHeap(int capacity) {
        this->capacity = capacity;
        size = 0;
        heapArray = new int[capacity];
        keyArray = new int[capacity];
        position = new int[capacity];

        for (int i = 0; i < capacity; ++i) {
            position[i] = -1;
        }
    }
    // Initializes variables size, and 3 new arrays used for storing key/heap values

    // Destructor
    ~MinHeap() {
        delete[] heapArray;
        delete[] position;
        delete[] keyArray;
    }
    // Deletes all 3 arrays used to track values


    void insert(int vertex, int key) {

        if (size == capacity) { // Edge case if the size of array is at capacity
            return;
        }
        int i = size;
        heapArray[i] = vertex;
        keyArray[i] = key;
        position[vertex] = i;
        size++;

        while (i != 0 && keyArray[parent(i)] > keyArray[i]) {

        }
    };
    int extractMin();
    void decreaseKey(int vertex, int newKey);
    bool isInMinHeap(int vertex);
    bool isEmpty();

private:
    int* heapArray;        // Heap of vertex indices
    int* keyArray;         // Corresponding key values
    int* position;         // Maps vertex to its position in heap
    int capacity;
    int size;
    int parent(int i) { return (i - 1) / 2; };
    int left(int i) { return 2 * i + 1; };
    int right(int i) { return 2 * i + 2; };

    // Helper function that swaps positions, vertices, and keys in an array
    void swap(int i, int j) {
        position[heapArray[i]] = j;
        position[heapArray[j]] = i;


        int temp = heapArray[i];
        heapArray[i] = heapArray[j];
        heapArray[j] = temp;
    }

    // Helper function that restores min-heap property if it becomes violated at a certain node.
    void minHeapHelper(int index) {
        int smallest = index;
        int left = left(index);
        int right = right(index);

        if (left < size && keyArray[left] < keyArray[smallest]) {
            smallest = left;
        }
        if (right < size && keyArray[right] < keyArray[smallest]) {
            smallest = right;
        }
        if (smallest != index) {
            swap(index, smallest);
            minHeapHelper(smallest);
        }
    }
};

#endif