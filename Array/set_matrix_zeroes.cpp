#include <iostream>
#include <vector>
using namespace std;

// Marks all elements in the given row (except zeros) as -1
void setRow(int row, vector<vector<int>>& v) {
    for (int j = 0; j < v[0].size(); j++) {
        if (v[row][j] != 0) {
            v[row][j] = -1;
        }
    }
}

// Marks all elements in the given column (except zeros) as -1
void setCol(int col, vector<vector<int>>& v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i][col] != 0) {
            v[i][col] = -1;
        }
    }
}

// Sets entire row and column to zero if an element is zero
void setMatrixZeros(vector<vector<int>>& v) {

    int rows = v.size();
    int cols = v[0].size();

    // First pass: mark rows and columns using -1
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (v[i][j] == 0) {
                setRow(i, v);
                setCol(j, v);
            }
        }
    }

    // Second pass: convert all -1 to 0
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (v[i][j] == -1) {
                v[i][j] = 0;
            }
        }
    }
}

int main() {

    vector<vector<int>> v1 = {{1,1,1},{1,0,1},{1,1,1}};
    setMatrixZeros(v1);

    for (auto vec : v1) {
        for (int ele : vec) {
            cout << ele << " ";
        }
        cout << endl;
    }

    vector<vector<int>> v2 = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setMatrixZeros(v2);

    for (auto vec : v2) {
        for (int ele : vec) {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Time Complexity (TC):
- For each zero, entire row and column are traversed
- Worst case TC = O((m × n) × (m + n))

Space Complexity (SC):
- No extra data structures used
- SC = O(1)
*/

/*******************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// Sets entire row and column to zero if an element is zero
void setMatrixZeros(vector<vector<int>>& v) {

    int rows = v.size();
    int cols = v[0].size();

    // Marker arrays for rows and columns
    vector<int> row(rows, 0);
    vector<int> col(cols, 0);

    // First pass: mark rows and columns containing zero
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (v[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // Second pass: update matrix based on markers
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (row[i] || col[j]) {
                v[i][j] = 0;
            }
        }
    }
}

int main() {

    vector<vector<int>> v1 = {{1,1,1},{1,0,1},{1,1,1}};
    setMatrixZeros(v1);

    for (auto vec : v1) {
        for (int ele : vec) {
            cout << ele << " ";
        }
        cout << endl;
    }

    vector<vector<int>> v2 = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setMatrixZeros(v2);

    for (auto vec : v2) {
        for (int ele : vec) {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Time Complexity (TC):
- Two full traversals of the matrix
- TC = O(m × n)

Space Complexity (SC):
- Extra row and column marker arrays
- SC = O(m + n)
*/
