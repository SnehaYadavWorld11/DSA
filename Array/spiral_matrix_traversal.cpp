#include <iostream>
#include <vector>
using namespace std;

// Prints the elements of the matrix in spiral order
void spiralMatrix(const vector<vector<int>>& v) {

    int rows = v.size();
    int cols = v[0].size();

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {

        // Traverse top row
        for (int i = left; i <= right; i++) {
            cout << v[top][i] << " ";
        }
        top++;

        // Traverse right column
        for (int i = top; i <= bottom; i++) {
            cout << v[i][right] << " ";
        }
        right--;

        // Traverse bottom row
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                cout << v[bottom][i] << " ";
            }
            bottom--;
        }

        // Traverse left column
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << v[i][left] << " ";
            }
            left++;
        }
    }

    cout << endl;
}

int main() {

    vector<vector<int>> v1 = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> v2 = {{1,2},{3,4}};

    spiralMatrix(v1);
    spiralMatrix(v2);

    return 0;
}

/*
Time Complexity (TC):
- Every element is visited exactly once
- TC = O(m × n)

Space Complexity (SC):
- No extra data structures used
- SC = O(1) (excluding output)
*/
