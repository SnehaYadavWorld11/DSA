#include <iostream>
#include <vector>
using namespace std;

// Function to find maximum subarray sum using Kadane's Algorithm
void maximumSubarraySum(vector<int>& nums) {
    int sum = 0;
    int maxSum = nums[0]; // initialize to first element for negative arrays

    for(int i = 0; i < nums.size(); i++) {
        if(sum < 0) {
            sum = 0; // reset current sum if negative
        }

        sum += nums[i];

        if(sum > maxSum) {
            maxSum = sum; // update max sum
        }
    }

    cout << "Maximum Subarray Sum: " << maxSum << endl;
}

int main() {
    vector<int> nums1 = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums2 = {1};
    vector<int> nums3 = {5,4,-1,7,8};

    maximumSubarraySum(nums1);
    maximumSubarraySum(nums2);
    maximumSubarraySum(nums3);

    return 0;
}

/*
Time Complexity: O(n) - single pass through the array
Space Complexity: O(1) - no extra space used
*/

/*******************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// Function to find maximum subarray sum along with start and end indices
void maximumSubarraySum(vector<int>& nums) {
    int sum = 0;
    int maxSum = nums[0]; // Initialize to first element for arrays with negatives
    int start = 0;         // potential start index
    int end = 0;           // end index of max subarray
    int tempStart = 0;     // temporary start when sum resets

    for (int i = 0; i < nums.size(); i++) {
        if (sum < 0) {
            sum = 0;
            tempStart = i; // start new subarray
        }

        sum += nums[i];

        if (sum > maxSum) {
            maxSum = sum;
            start = tempStart;
            end = i;
        }
    }

    cout << "Maximum Subarray Sum: " << maxSum << endl;
    cout << "Start and Ending Indices: " << start << " " << end << endl;
}

int main() {
    vector<int> nums1 = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums2 = {1};
    vector<int> nums3 = {5,4,-1,7,8};

    maximumSubarraySum(nums1);
    maximumSubarraySum(nums2);
    maximumSubarraySum(nums3);

    return 0;
}

/*
Time Complexity: O(n) - single pass through the array
Space Complexity: O(1) - no extra space used
*/

