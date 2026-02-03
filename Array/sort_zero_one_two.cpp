#include <iostream>
#include <vector>
using namespace std;

// Function to sort an array containing only 0s, 1s, and 2s
// Uses counting approach
void sortZeroOneTwo(vector<int>& nums){
    int n = nums.size();
    int zero = 0, one = 0, two = 0;

    // Count number of 0s, 1s, and 2s
    for(int ele : nums){
        if(ele == 0) zero++;
        else if(ele == 1) one++;
        else two++;
    }

    // Print sorted array using counts
    while(zero--) cout << "0 ";
    while(one--) cout << "1 ";
    while(two--) cout << "2 ";

    cout << endl;
}

int main(){
    vector<int> nums = {0,1,1,2,2,0,0,0,1,2,0,1,1,1,0,0,0,2,2,2};

    sortZeroOneTwo(nums);

    return 0;
}

/*
Time Complexity: O(n) - single pass to count and another to print
Space Complexity: O(1) - only three counters used
*/

/*************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// Function to sort an array of 0s, 1s, and 2s using Dutch National Flag Algorithm
void sortZeroOneTwo(vector<int>& nums) {
    int low = 0, mid = 0;
    int high = nums.size() - 1;

    while(mid <= high) {
        if(nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if(nums[mid] == 1) {
            mid++;
        } else { // nums[mid] == 2
            swap(nums[mid], nums[high]);
            high--;
        }
    }

    // Print sorted array
    for(int ele : nums) {
        cout << ele << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {0,1,1,2,2,0,0,0,1,2,0,1,1,1,0,0,0,2,2,2};

    sortZeroOneTwo(nums);

    return 0;
}

/*
Time Complexity: O(n) - each element is processed at most once
Space Complexity: O(1) - in-place sorting with no extra space
*/
