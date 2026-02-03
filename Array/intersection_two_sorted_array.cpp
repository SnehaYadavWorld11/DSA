#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    vector<int> v1 = {1, 2, 2, 3, 3, 4, 5, 6};
    vector<int> v2 = {2, 3, 3, 5, 6, 6, 7};
    vector<int> result;

    map<int, int> mpp1, mpp2;

    // Count frequency of elements in both arrays
    for (int ele : v1) mpp1[ele]++;
    for (int ele : v2) mpp2[ele]++;

    // Add common elements based on minimum frequency
    for (const auto &it : mpp1) {
        int ele = it.first;

        if (mpp2.find(ele) != mpp2.end()) {
            int freq = min(mpp1[ele], mpp2[ele]);
            while (freq--) {
                result.push_back(ele);
            }
        }
    }

    // Output the result
    for (int ele : result) {
        cout << ele << " ";
    }

    return 0;
}

/*
Time Complexity: O((n + m) log (n + m))
Space Complexity: O(n + m)
*/


/********************************************************************************************************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1 = {1, 2, 2, 3, 3, 4, 5, 6};
    vector<int> v2 = {2, 3, 3, 5, 6, 6, 7};
    vector<int> result;

    int n1 = v1.size();
    int n2 = v2.size();

    int i = 0, j = 0;

    // Two-pointer approach to find intersection
    while (i < n1 && j < n2) {
        if (v1[i] < v2[j]) {
            i++;
        } else if (v2[j] < v1[i]) {
            j++;
        } else {
            result.push_back(v1[i]);
            i++;
            j++;
        }
    }

    // Print result
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}

/*
Time Complexity: O(n + m)
Space Complexity: O(1)  (excluding result vector)
*/
