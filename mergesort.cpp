#include<iostream>
using namespace std;

// Merge function to merge two halves
void merge(int arr[], int s, int e, int mid) {
    int leftLength = mid - s + 1;
    int rightLength = e - mid;

    // Create temporary arrays
    int* leftArr = new int[leftLength];
    int* rightArr = new int[rightLength];

    // Copy data to temp arrays
    for (int i = 0; i < leftLength; i++)
        leftArr[i] = arr[s + i];
    for (int i = 0; i < rightLength; i++)
        rightArr[i] = arr[mid + 1 + i];

    // Merge the temp arrays back into arr[s..e]
    int i = 0; // Initial index of left subarray
    int j = 0; // Initial index of right subarray
    int k = s; // Initial index of merged subarray
    while (i < leftLength && j < rightLength) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < leftLength) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < rightLength) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    // Free the dynamically allocated memory
    delete[] leftArr;
    delete[] rightArr;
}

// Merge sort function
void mergeSort(int arr[], int s, int e) {
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;

    // Recursively sort the first and second halves
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    // Merge the sorted halves
    merge(arr, s, e, mid);
}

int main() {
    int arr[] = {10, 80, 110, 90, 50, 30, 40, 20};
    int size = sizeof(arr) / sizeof(arr[0]);
    int s = 0;
    int e = size - 1;

    mergeSort(arr, s, e);

    // Print the sorted array
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
