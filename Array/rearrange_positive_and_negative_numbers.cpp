#include <iostream>
#include <vector>
using namespace std;

void rearrangePositiveAndNegativeNumber(vector<int>& nums) {
    vector<int> pos;
    vector<int> neg;

    // Separate positive and negative numbers
    for (int num : nums) {
        if (num < 0) {
            neg.push_back(num);
        } else {
            pos.push_back(num);
        }
    }

    // Merge back into original array
    int idx = 0;
    for (int num : neg) {
        nums[idx++] = num;
    }

    for (int num : pos) {
        nums[idx++] = num;
    }

    // Output result
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums1 = {12, 11, -13, -5, 6, -7, 5, -3, -6};
    vector<int> nums2 = {11, -13, 6, -7, 5};

    rearrangePositiveAndNegativeNumber(nums1);
    rearrangePositiveAndNegativeNumber(nums2);

    return 0;
}

/*
Problem: Rearrange Positive and Negative Numbers
Platform: GeeksforGeeks
Link: https://www.geeksforgeeks.org/dsa/rearrange-positive-and-negative-numbers/

Approach:
- Store negative numbers in one array and positive numbers in another.
- Copy them back to the original array with negatives first.

Time Complexity: O(n)
Space Complexity: O(n)  // Extra space used
*/


