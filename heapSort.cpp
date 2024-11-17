
#include <iostream>
#include<vector>


using namespace std;

// To heapify a subtree rooted with node i
// which is an index in arr[].
void heapify(vector<int>& arr, int n, int i){

    // Initialize largest as root
    int largest = i;

    // left index
    int l = 2 * i ;

    // right in
    int r = 2 * i + 1;

    // If left child is larger 
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger 
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        
        heapify(arr, n, largest);
    }
}


void heapSort(vector<int>& arr){
    int n = arr.size();
    // BUild Heap
    for (int i = n / 2 ; i >= 0; i--)
        heapify(arr, n, i);

    // root ko end me lana
    for (int i = n - 1; i > 0; i--) {

        
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

// A utility function to print vector of size n
void printArray(vector<int>& arr){
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << "\n";
}


int main(){
    vector<int> arr = { 9, 4, 3, 8, 10, 2, 5 };

    // Function call
    heapSort(arr);

    cout << "Sorted array is \n";
    printArray(arr);
}