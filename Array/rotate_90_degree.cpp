#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Rotates a square matrix by 90 degrees clockwise
void rotate90Degree(vector<vector<int>>& v) {

    int n = v.size();

    // Step 1: Transpose the matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(v[i][j], v[j][i]);
        }
    }

    // Step 2: Reverse each row
    for (auto& row : v) {
        reverse(row.begin(), row.end());
    }
}

int main() {

    vector<vector<int>> v1 = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> v2 = {{1,2},{3,4}};

    rotate90Degree(v1);
    rotate90Degree(v2);

    for (auto row : v1) {
        for (int ele : row) cout << ele << " ";
        cout << endl;
    }
    cout << endl;

    for (auto row : v2) {
        for (int ele : row) cout << ele << " ";
        cout << endl;
    }

    return 0;
}

/*
TC: O(n × n)
SC: O(1)
*/
