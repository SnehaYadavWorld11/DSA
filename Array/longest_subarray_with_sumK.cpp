#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the length of the longest subarray with sum = k
int longestSubarrayWithSumK(vector<int>& v, int k) {
    int n = v.size();
    int maxLen = 0;

    // Brute-force approach: check all subarrays
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += v[j];  // sum of subarray [i..j]
            if (sum == k) {
                maxLen = max(maxLen, j - i + 1);  // update max length
            }
        }
    }

    return maxLen;
}

int main() {
    vector<int> v1 = {10, 5, 2, 7, 1, -10};
    int k1 = 15;

    vector<int> v2 = {-5, 8, -14, 2, 4, 12};
    int k2 = -5;

    vector<int> v3 = {10, -10, 20, 30};
    int k3 = 5;

    int len = longestSubarrayWithSumK(v1, k1);
    cout << "Maximum subarray sum length : " << len << endl;

    len = longestSubarrayWithSumK(v2, k2);
    cout << "Maximum subarray sum length : " << len << endl;

    len = longestSubarrayWithSumK(v3, k3);
    cout << "Maximum subarray sum length : " << len << endl;

    return 0;
}

/*
Time Complexity: O(n^2)
Space Complexity: O(1)
*/


/**************************************************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find the length of the longest subarray with sum = k
int longestSubarrayWithSumK(vector<int>& v, int k){
    int n = v.size();
    int maxLen = 0;
    int sum = 0;
    unordered_map<int,int> mpp; // stores first occurrence of prefix sums

    for(int i = 0; i < n; i++){
        sum += v[i]; // prefix sum

        // Subarray from index 0 to i
        if(sum == k){
            maxLen = max(maxLen, i + 1);
        }

        int remain = sum - k;
        if(mpp.find(remain) != mpp.end()){
            maxLen = max(maxLen, i - mpp[remain]);
        }

        // store first occurrence of prefix sum
        if(mpp.find(sum) == mpp.end()){
            mpp[sum] = i;
        }
    }

    return maxLen;
}

int main()
{
    vector<int> v1 = {10, 5, 2, 7, 1, -10};
    int k1 = 15;

    vector<int> v2 = {-5, 8, -14, 2, 4, 12};
    int k2 = -5;

    vector<int> v3 = {10, -10, 20, 30};
    int k3 = 5;

    int len = longestSubarrayWithSumK(v1, k1);
    cout << "Maximum subarray sum length : " << len << endl;

    len = longestSubarrayWithSumK(v2, k2);
    cout << "Maximum subarray sum length : " << len << endl;

    len = longestSubarrayWithSumK(v3, k3);
    cout << "Maximum subarray sum length : " << len << endl;

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/

/*******************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the length of the longest subarray with sum = k
// Note: This sliding window approach works only for arrays with non-negative numbers
int longestSubarrayWithSumK(vector<int>& v, int k){
    int n = v.size();
    int left = 0;        // start of the current window
    int maxLen = 0;      // maximum length of subarray found
    int sum = 0;         // current window sum

    for(int right = 0; right < n; right++){
        sum += v[right];  // include current element in sum

        // Shrink window from left while sum > k
        while(sum > k && left <= right){
            sum -= v[left];
            left++;
        }

        // If current window sum equals k, update maxLen
        if(sum == k){
            maxLen = max(maxLen, right - left + 1);
        }
    }

    return maxLen;
}

int main()
{
    vector<int> v1 = {10, 5, 2, 7, 1, -10}; // contains negative -> sliding window may fail
    int k1 = 15;

    vector<int> v2 = {-5, 8, -14, 2, 4, 12}; // contains negative -> sliding window may fail
    int k2 = -5;

    vector<int> v3 = {10, -10, 20, 30}; // contains negative -> sliding window may fail
    int k3 = 5;

    vector<int> v4 = {1, 1, 1}; // positive numbers -> sliding window works
    int k4 = 2;

    int len = longestSubarrayWithSumK(v1, k1);
    cout << "Maximum subarray sum length : " << len << endl;

    len = longestSubarrayWithSumK(v2, k2);
    cout << "Maximum subarray sum length : " << len << endl;

    len = longestSubarrayWithSumK(v3, k3);
    cout << "Maximum subarray sum length : " << len << endl;

    len = longestSubarrayWithSumK(v4, k4);
    cout << "Maximum subarray sum length : " << len << endl;

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)

Note:
- This sliding window approach works correctly only for arrays with non-negative numbers.
- For arrays containing negative numbers, use the prefix sum + hashmap approach for correct results.
*/
