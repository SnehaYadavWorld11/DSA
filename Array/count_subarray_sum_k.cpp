#include <iostream>
#include <vector>
using namespace std;

void countSubarrayOfSumK(vector<int>& v, int k) {
    int totalSubarray = 0;

    for (int i = 0; i < v.size(); i++) {
        int sum = 0;
        for (int j = i; j < v.size(); j++) {
            sum += v[j];
            if (sum == k) {
                totalSubarray++;
            }
        }
    }

    cout << "Number of Subarray Sum Equals K : "
         << totalSubarray << endl;
}

int main() {
    vector<int> v1 = {1, 1, 1};
    int k1 = 2;

    vector<int> v2 = {1, 2, 3};
    int k2 = 3;

    countSubarrayOfSumK(v1, k1);
    countSubarrayOfSumK(v2, k2);

    return 0;
}

/*
Time Complexity: O(N^2)
- Two nested loops to check all possible subarrays

Space Complexity: O(1)
- No extra space used apart from variables
*/

/***********************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to count the number of subarrays whose sum equals k
void countSubarrayOfSumK(const vector<int>& v, int k) {
    unordered_map<long long, int> prefixSumCount;
    prefixSumCount[0] = 1;   // To handle subarrays starting from index 0

    long long prefixSum = 0;
    int totalSubarray = 0;

    for (int i = 0; i < v.size(); i++) {
        prefixSum += v[i];

        long long remaining = prefixSum - k;

        // If remaining prefix sum exists, add its frequency
        if (prefixSumCount.find(remaining) != prefixSumCount.end()) {
            totalSubarray += prefixSumCount[remaining];
        }

        // Store/update current prefix sum frequency
        prefixSumCount[prefixSum]++;
    }

    cout << "Number of Subarray Sum Equals K : " << totalSubarray << endl;
}

int main() {
    vector<int> v1 = {1, 1, 1};
    int k1 = 2;

    vector<int> v2 = {1, 2, 3};
    int k2 = 3;

    countSubarrayOfSumK(v1, k1);
    countSubarrayOfSumK(v2, k2);

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)

Explanation:
- Uses Prefix Sum + Hash Map approach.
- Works for positive, negative, and zero values.
- Counts all possible subarrays whose sum equals k.
*/
