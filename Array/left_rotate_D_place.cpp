#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to rotate a vector to the left by d positions
void rotateVector(vector<int>& v, int d) {
    int n = v.size();
    if(n == 0) return;

    d = d % n; // handle d > n

    // Reverse first d elements
    reverse(v.begin(), v.begin() + d);

    // Reverse remaining elements
    reverse(v.begin() + d, v.end());

    // Reverse the entire vector
    reverse(v.begin(), v.end());
}

int main() {
    vector<int> v = {1,1,2,3,3,3,4,5,6,6,7,8,8,9};
    int d = 5;

    rotateVector(v, d);

    cout << "Vector after rotating by " << d << " positions: ";
    for(int num : v) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity:  O(n) - each reverse operation is O(n)
Space Complexity: O(1) - in-place rotation, no extra space used
*/
