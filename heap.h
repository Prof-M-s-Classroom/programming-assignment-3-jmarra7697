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

        if (size == capacity) {
            return;
            // Edge case if the size of array is at capacity
        }
        int i = size++;
        heapArray[i] = vertex;
        keyArray[i] = key;
        position[vertex] = i;


        while (i != 0 && keyArray[parent(i)] > keyArray[i]) {
        swap(i, parent(i));
            i = parent(i);
        }
    };

    int extractMin() {
        // Edge cases if size is 1 or below
        if (size <= 0) {
            return -1;
        }
        if (size == 1) {
            size--;
            position[heapArray[0]] = -1;
            return heapArray[0];
        }

        int root = heapArray[0];
        position[root] = -1;
        heapArray[0] = heapArray[size-1];
        position[heapArray[0]] = 0;
        size--;
        minHeapHelper(0);
        return root;
    };
    // extractMin first saves the root as the smallest key then replaces the root with the last element
    // It then updates the position of the element, reduces the heap size, and restores heap property from the root via minHeapHelper
    // Then finally returns the saved vertex, which is stored in the root value


    void decreaseKey(int vertex, int newKey) {
        int i = position[vertex];
        if (i == -1) {
            return;
        }
        keyArray[i] = newKey;
        while (i != 0 && keyArray[parent(i)] > keyArray[i]) {
            swap(i, parent(i));
            i = parent(i);
        }
    }
    // decreaseKey updates the priority, or key, of a specific vertex and then restores the min-heap property

    bool isInMinHeap(int vertex) {
        return position[vertex] != -1;
    };
    bool isEmpty() {
        return size == 0;
    };

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

        int tempKey = keyArray[i];
        keyArray[i] = keyArray[j];
        keyArray[j] = tempKey;
    }

    // Helper function that restores min-heap property if it becomes violated at a certain node.
    void minHeapHelper(int index) {
        int smallest = index;
        int l = left(index);
        int r = right(index);

        if (l < size && keyArray[l] < keyArray[smallest]) {
            smallest = l;
        }
        if (r < size && keyArray[r] < keyArray[smallest]) {
            smallest = r;
        }
        if (smallest != index) {
            swap(index, smallest);
            minHeapHelper(smallest);
        }
    }
};

#endif