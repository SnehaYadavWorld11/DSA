#include <iostream>
#include <vector>
using namespace std;

// Function to find two indices i and j such that nums[i] + nums[j] = target
// Brute-force approach: check all pairs
void twoSum(vector<int>& nums, int target) {
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                cout << "Indices i and j are: " << i << " " << j << endl;
                return;
            }
        }
    }

    cout << "Not Found!" << endl;
}

int main() {
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;

    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;

    twoSum(nums1, target1);
    twoSum(nums2, target2);

    return 0;
}

/*
Time Complexity: O(n^2) - checking all pairs
Space Complexity: O(1) - no extra space used
*/


/*****************************************************************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Optimized function to find two indices i and j such that nums[i] + nums[j] = target
// Uses a hashmap to store numbers seen so far
void twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    unordered_map<int, int> mpp; // maps number -> its index

    for (int i = 0; i < n; i++) {
        int rem = target - nums[i]; // required number to reach target

        // If required number is already in map, we found the pair
        if (mpp.find(rem) != mpp.end()) {
            cout << "Indices i and j are: " << mpp[rem] << " " << i << endl;
            return;
        }

        // Store current number in map (first occurrence)
        if (mpp.find(nums[i]) == mpp.end()) {
            mpp[nums[i]] = i;
        }
    }

    cout << "Not Found!" << endl;
}

int main() {
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;

    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;

    twoSum(nums1, target1);
    twoSum(nums2, target2);

    return 0;
}

/*
Time Complexity: O(n) - iterate through array once
Space Complexity: O(n) - hashmap stores up to n elements
*/


/***************************************************************************************************************************************/
