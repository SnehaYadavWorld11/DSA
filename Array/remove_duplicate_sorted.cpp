#include <iostream>
#include <vector>
using namespace std;

// Function to remove duplicates from a sorted array in-place
// Returns the number of unique elements
int removeDuplicates(vector<int>& v) {
    int n = v.size();
    if(n == 0) return 0;

    int idx = 0; // index of last unique element

    for(int i = 1; i < n; i++) {
        if(v[idx] != v[i]) {
            v[++idx] = v[i]; // store new unique element
        }
    }

    return idx + 1; // number of unique elements
}

int main() {
    vector<int> v = {1,1,2,3,3,3,4,5,6,6,7,8,8,9};

    int uniqueCount = removeDuplicates(v);

    cout << "Array after removing duplicates: ";
    for(int i = 0; i < uniqueCount; i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity:  O(n) - single pass through the array
Space Complexity: O(1) - in-place, no extra space used
*/
