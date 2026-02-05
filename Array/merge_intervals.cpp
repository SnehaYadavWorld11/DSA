#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void mergeIntervals(vector<vector<int>>& v) {
    sort(v.begin(), v.end());
    vector<vector<int>> result;

    for (int i = 0; i < v.size(); i++) {
        if (result.empty() || v[i][0] > result.back()[1]) {
            result.push_back(v[i]);
        } else {
            result.back()[1] = max(result.back()[1], v[i][1]);
        }
    }

    for (auto& vec : result) {
        cout << vec[0] << " " << vec[1] << "   ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> v1 = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> v2 = {{1,4},{4,5}};
    vector<vector<int>> v3 = {{4,7},{1,4}};

    mergeIntervals(v1);
    mergeIntervals(v2);
    mergeIntervals(v3);

    return 0;
}

/*
Time Complexity: O(n log n)
Space Complexity: O(n)
*/
