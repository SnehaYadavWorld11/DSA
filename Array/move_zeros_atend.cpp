#include <iostream>
#include <vector>
using namespace std;

// Function to move all zeros in the array to the end
void moveZerosToEnd(vector<int>& v) {
    int n = v.size();
    int idx = 0; // index to place non-zero elements

    // Step 1: Move all non-zero elements to the front
    for(int i = 0; i < n; i++) {
        if(v[i] != 0) {
            v[idx++] = v[i];
        }
    }

    // Step 2: Fill remaining positions with zeros
    while(idx < n) {
        v[idx++] = 0;
    }
}

int main() {
    vector<int> v = {1,0,1,2,3,3,0,3,4,0,5,6,6,0,7,8,0,8,9};

    moveZerosToEnd(v);

    cout << "Array after moving zeros to the end: ";
    for(int num : v) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity:  O(n) - single traversal of the array
Space Complexity: O(1) - in-place, no extra array used
*/
