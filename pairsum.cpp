#include <iostream>
#include <vector>
#include <utility>  // For std::pair

using namespace std;

void solve(int arr[], int size, vector<pair<int, int>>& ans) { // Pass by reference
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) { // Start from i + 1 to avoid pairing with itself
            for(int k = 0; k < size; k++) { // Start from j + 1
                if(arr[i] + arr[j] == arr[k]) {
                    ans.push_back(make_pair(arr[i], arr[j]));
                }
            }
        }
    }
    for (const auto& nums : ans) {
        cout << nums.first << " " << nums.second << endl;
    }
}

int main() {
    int arr[] = {1, 3,2,6 ,9,8,5,10};
    int size = sizeof(arr) / sizeof(arr[0]); // Compute size based on array
    vector<pair<int, int>> ans;
    solve(arr, size, ans);
    return 0;
}