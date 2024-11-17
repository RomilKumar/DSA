#include <iostream>
using namespace std;

class heap {
public:
    int arr[100];
    int size;

    // Constructor initializes the heap
    heap() {
        arr[0] = -1; // Not used but simplifies indexing
        size = 0;    // Heap is initially empty
    }

    // Insert a value into the heap
    void insert(int val) {
        size = size + 1;         // Increment size
        arr[size] = val;         // Place the new value at the end
        int index = size;        // Start at the last index

        // Heapify up
        while (index > 1) {
            int parent = index / 2; // Parent index
            if (arr[index] > arr[parent]) {
                swap(arr[index], arr[parent]); // Swap if child is greater than parent
                index = parent;    // Move up to parent
            } else {
                return;            // Heap property satisfied
            }
        }
    }

    // Print the heap
    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl; // New line after printing
    }

    // Delete the root (maximum) element from the heap
    void deleteFromHeap() {
        if (size == 0) {
            cout << "Nothing to delete." << endl;
            return; // Nothing to delete
        }

        // Step 1: Replace root with last element
        arr[1] = arr[size]; // Move last element to the root

        // Step 2: Decrease the size of the heap
        size--;

        // Step 3: Heapify down from the root
        int i = 1; // Start from the root
        while (i <= size) { // Ensure within bounds
            int leftIndex = 2 * i; // Left child index
            int rightIndex = 2 * i + 1; // Right child index

            // Assume current is largest
            int largestIndex = i;

            // Compare with left child
            if (leftIndex <= size && arr[leftIndex] > arr[largestIndex]) {
                largestIndex = leftIndex; // Update largest if left child is greater
            }
            // Compare with right child
            if (rightIndex <= size && arr[rightIndex] > arr[largestIndex]) {
                largestIndex = rightIndex; // Update largest if right child is greater
            }

            // If largest is not the current node, swap and continue
            // if (largestIndex != i) {
            //     swap(arr[i], arr[largestIndex]); // Swap with the largest child
            //     i = largestIndex; // Move down to the largest child
             else {
                return; // Heap property satisfied
            }
        }
    }
};

int main() {
    heap h;
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);
    
    cout << "Heap before deletion:" << endl;
    h.print(); // Print the heap

    h.deleteFromHeap(); // Delete the root element

    cout << "Heap after deletion:" << endl;
    h.print(); // Print the heap again

    return 0;
}
