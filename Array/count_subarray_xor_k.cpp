#include <iostream>
#include <vector>
using namespace std;

void countSubarrayOfXorK(vector<int>& v, int k) {
    int totalSubarray = 0;

    for (int i = 0; i < v.size(); i++) {
        int xorr = 0;
        for (int j = i; j < v.size(); j++) {
            xorr ^= v[j];
            if (xorr == k) {
                totalSubarray++;
            }
        }
    }

    cout << "Number of Subarrays with XOR = " << k
         << " : " << totalSubarray << endl;
}

int main() {
    vector<int> v1 = {4, 2, 2, 6, 4};
    int k1 = 6;

    vector<int> v2 = {5, 6, 7, 8, 9};
    int k2 = 5;

    vector<int> v3 = {1, 1, 1, 1};
    int k3 = 0;

    countSubarrayOfXorK(v1, k1);
    countSubarrayOfXorK(v2, k2);
    countSubarrayOfXorK(v3, k3);

    return 0;
}
// Time Complexity: O(n^2)
// Space Complexity: O(1)

/***************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void countSubarrayOfXorK(vector<int>& v, int k) {
    unordered_map<int, int> mpp;
    mpp[0] = 1;   // base case

    int prexor = 0;
    int totalSubarray = 0;

    for (int i = 0; i < v.size(); i++) {
        prexor ^= v[i];
        int remain = prexor ^ k;

        totalSubarray += mpp[remain];
        mpp[prexor]++;
    }

    cout << "Number of Subarrays with XOR = "
         << k << " : " << totalSubarray << endl;
}

int main() {
    vector<int> v1 = {4, 2, 2, 6, 4};
    int k1 = 6;

    vector<int> v2 = {5, 6, 7, 8, 9};
    int k2 = 5;

    vector<int> v3 = {1, 1, 1, 1};
    int k3 = 0;

    countSubarrayOfXorK(v1, k1);
    countSubarrayOfXorK(v2, k2);
    countSubarrayOfXorK(v3, k3);

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
