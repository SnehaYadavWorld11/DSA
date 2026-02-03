#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    vector<int> v = {0, 0, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    int n = v.size();

    unordered_map<int, int> mpp;

    // Count frequency of each element
    for (int ele : v) {
        mpp[ele]++;
    }

    // Find the first element with frequency 1
    for (auto it : mpp) {
        if (it.second == 1) {
            cout << "Element: " << it.first << endl;
            return 0;
        }
    }

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/


/****************************************************************************************************************/


#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {0, 0, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    int n = v.size();

    int uniqueEle = 0;

    // XOR all elements; duplicates cancel out
    for (int ele : v) {
        uniqueEle ^= ele;
    }

    cout << "Unique Element: " << uniqueEle << endl;

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
