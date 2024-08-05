#include <iostream>
using namespace std;

int findMissingNumber(int arr[], int n) {
    int x1 = arr[0]; // XOR of all array elements
    int x2 = 1;      // XOR of all numbers from 1 to n

    // XOR all the elements in the array
    for (int i = 1; i < n; i++) {
        x1 = x1 ^ arr[i];
    }

    // XOR all the numbers from 1 to n+1
    for (int i = 2; i <= n + 1; i++) {
        x2 = x2 ^ i;
    }

    // XOR of x1 and x2 gives the missing number
    return (x1 ^ x2);
}

int main() {
    int arr[] = {1,2,3, 5, 6}; // Array of size n-1
    int n = sizeof(arr) / sizeof(arr[0]);

    int missingNumber = findMissingNumber(arr, n);
    cout << "The missing number is: " << missingNumber << endl;

    return 0;
}