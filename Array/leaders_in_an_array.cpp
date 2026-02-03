#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void leadersInAnArray(vector<int>& nums) {
    vector<int> result;

    // Last element is always a leader
    int currentLeader = nums[nums.size() - 1];
    result.push_back(currentLeader);

    // Traverse from right to left
    for (int i = nums.size() - 2; i >= 0; i--) {
        if (nums[i] > currentLeader) {
            result.push_back(nums[i]);
            currentLeader = nums[i];
        }
    }

    // Sort leaders in descending order (optional)
    sort(result.begin(), result.end(), greater<int>());

    // Print leaders
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums1 = {16, 17, 4, 3, 5, 2};
    vector<int> nums2 = {1, 2, 3, 4, 5, 2};

    leadersInAnArray(nums1);
    leadersInAnArray(nums2);

    return 0;
}

/*
Approach:
- Traverse the array from right to left.
- Keep track of the maximum element seen so far.
- If current element is greater than max, it is a leader.
- Store leaders and sort before printing.

Time Complexity: O(n log n)  // due to sorting
Space Complexity: O(n)       // extra space for result
*/
