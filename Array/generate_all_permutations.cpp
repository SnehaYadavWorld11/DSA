#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to generate all permutations of the given array
// Uses STL next_permutation which generates permutations in lexicographical order
void generateAllPermutation(vector<int>& nums, vector<vector<int>>& result) {

    // Sorting is important to ensure all permutations are generated
    sort(nums.begin(), nums.end());

    // Store the current permutation and move to the next one
    do {
        result.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
}

int main() {

    // Input array
    vector<int> nums = {1, 2, 3, 4, 5};

    // To store all permutations
    vector<vector<int>> result;

    // Generate permutations
    generateAllPermutation(nums, result);

    // Print all permutations
    for (auto v : result) {
        for (auto ele : v) {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Time Complexity (TC):
- Total permutations of n elements = n!
- Copying each permutation into result takes O(n)
- Overall TC = O(n! × n)

Space Complexity (SC):
- Storing all permutations requires O(n! × n)
- Extra auxiliary space (excluding output) = O(1)
*/
