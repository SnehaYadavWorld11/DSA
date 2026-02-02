#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted arrays into a single sorted array
void mergeSortedArrays(const vector<int>& v1, const vector<int>& v2, vector<int>& result) {
    int n1 = v1.size();
    int n2 = v2.size();
    int idx = 0; // index for result
    int i = 0, j = 0;

    // Merge elements from both arrays in sorted order
    while(i < n1 && j < n2) {
        if(v1[i] <= v2[j]) {
            result[idx++] = v1[i++];
        } else {
            result[idx++] = v2[j++];
        }
    }

    // Copy remaining elements from v1
    while(i < n1) {
        result[idx++] = v1[i++];
    }

    // Copy remaining elements from v2
    while(j < n2) {
        result[idx++] = v2[j++];
    }
}

int main() {
    vector<int> v1 = {1,3,5,7,9};
    vector<int> v2 = {2,4,6,8,10};

    vector<int> result(v1.size() + v2.size());

    mergeSortedArrays(v1, v2, result);

    cout << "Merged sorted array: ";
    for(int ele : result) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity:  O(n1 + n2) - single pass through both arrays
Space Complexity: O(n1 + n2) - result array stores merged elements
*/
