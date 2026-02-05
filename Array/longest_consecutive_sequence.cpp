#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Checks if an element exists in the array
bool isPresent(int ele, const vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        if (ele == nums[i]) return true;
    }
    return false;
}

// Finds the length of the longest consecutive sequence
int longestConsecutiveSequence(const vector<int>& nums) {

    int longest = 0;

    for (int i = 0; i < nums.size(); i++) {
        int currLength = 1;
        int ele = nums[i];

        // Check for consecutive elements
        while (isPresent(++ele, nums)) {
            currLength++;
        }

        longest = max(longest, currLength);
    }

    return longest;
}

int main() {

    vector<int> nums1 = {2, 6, 1, 9, 4, 5, 3};
    vector<int> nums2 = {1, 1, 1, 2, 2, 3};
    vector<int> nums3 = {100, 4, 200, 1, 3, 2};

    cout << "Longest Consecutive Sequence: "
         << longestConsecutiveSequence(nums1) << endl;

    cout << "Longest Consecutive Sequence: "
         << longestConsecutiveSequence(nums2) << endl;

    cout << "Longest Consecutive Sequence: "
         << longestConsecutiveSequence(nums3) << endl;

    return 0;
}

/*
Time Complexity (TC):
- Outer loop runs O(n)
- For each element, isPresent() runs O(n)
- while loop can run up to O(n) times
- Overall TC = O(n^3)

Space Complexity (SC):
- No extra data structures used
- SC = O(1) (excluding input)
*/


/***************************************************************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Returns the length of the longest consecutive sequence
int longestConsecutiveSequence(const vector<int>& nums) {

    unordered_set<int> st;
    int longest = 0;

    // Insert all elements into the set
    for (int ele : nums) {
        st.insert(ele);
    }

    // Check only starting elements of sequences
    for (int ele : nums) {
        if (st.find(ele - 1) == st.end()) {
            int currLength = 1;
            int current = ele;

            // Count consecutive numbers
            while (st.find(current + 1) != st.end()) {
                current++;
                currLength++;
            }

            longest = max(longest, currLength);
        }
    }

    return longest;
}

int main() {

    vector<int> nums1 = {2, 6, 1, 9, 4, 5, 3};
    vector<int> nums2 = {1, 1, 1, 2, 2, 3};
    vector<int> nums3 = {100, 4, 200, 1, 3, 2};

    cout << "Longest Consecutive Sequence: "
         << longestConsecutiveSequence(nums1) << endl;

    cout << "Longest Consecutive Sequence: "
         << longestConsecutiveSequence(nums2) << endl;

    cout << "Longest Consecutive Sequence: "
         << longestConsecutiveSequence(nums3) << endl;

    return 0;
}

/*
Time Complexity (TC):
- Inserting into unordered_set: O(n)
- Each element is processed at most once in sequence expansion
- Overall TC = O(n)

Space Complexity (SC):
- unordered_set stores n elements
- SC = O(n)
*/
