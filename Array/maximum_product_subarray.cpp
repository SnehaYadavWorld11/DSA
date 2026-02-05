#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void findMaximumProductSubarray(const vector<int>& v) {
    int n = v.size();
    long long pre = 1, suf = 1;
    long long result = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        if (pre == 0) pre = 1;
        if (suf == 0) suf = 1;

        pre *= v[i];
        suf *= v[n - i - 1];

        result = max(result, max(pre, suf));
    }

    cout << "Maximum Product of Subarray : " << result << endl;
}

int main() {
    vector<int> v1 = {2, 3, -2, 4};
    vector<int> v2 = {-2, 0, -1};

    findMaximumProductSubarray(v1);
    findMaximumProductSubarray(v2);

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
