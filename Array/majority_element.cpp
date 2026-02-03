#include <iostream>
#include <vector>
using namespace std;

// Function to find the majority element (appears more than n/2 times) using brute-force
void majorityElement(vector<int>& nums) {
    int n = nums.size();

    for(int i = 0; i < n; i++) {
        int count = 0;
        // Count occurrences of nums[i]
        for(int j = 0; j < n; j++) {
            if(nums[i] == nums[j]) {
                count++;
            }
        }

        // Check if it appears more than n/2 times
        if(count > n / 2) {
            cout << "Majority Element: " << nums[i] << endl;
            return;
        }
    }

    cout << "Not Found! : " << -1 << endl;
}

int main() {
    vector<int> nums1 = {1, 1, 2, 1, 3, 5, 1};
    vector<int> nums2 = {2, 13};
    vector<int> nums3 = {7};

    majorityElement(nums1);
    majorityElement(nums2);
    majorityElement(nums3);

    return 0;
}

/*
Time Complexity: O(n^2) - nested loop to count occurrences
Space Complexity: O(1) - no extra space used
*/


/*************************************************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find the majority element (appears more than n/2 times) using hashmap
void majorityElement(vector<int>& nums) {
    unordered_map<int, int> mpp;

    // Count frequency of each element
    for (int ele : nums) {
        mpp[ele]++;
    }

    // Check for element with count > n/2
    for (int i = 0; i < nums.size(); i++) {
        if (mpp[nums[i]] > nums.size() / 2) {
            cout << "Majority Element: " << nums[i] << endl;
            return;
        }
    }

    cout << "Not Found!" << endl;
}

int main() {
    vector<int> nums1 = {1, 1, 2, 1, 3, 5, 1};
    vector<int> nums2 = {2, 13};
    vector<int> nums3 = {7};

    majorityElement(nums1);
    majorityElement(nums2);
    majorityElement(nums3);

    return 0;
}

/*
Time Complexity: O(n) - one pass to count + one pass to check
Space Complexity: O(n) - hashmap stores element counts
*/
