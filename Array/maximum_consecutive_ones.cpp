#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v = {0,1,1,1,0,0,4,5,6,7,1,1,1,1,1,4,5,6,7,8,1,1,1,1,1,1,1,7,8};
    int n = v.size();

    int maximum = 0;  // stores maximum consecutive 1s
    int current = 0;  // stores current consecutive 1s streak

    // Traverse array to count consecutive 1s
    for (int ele : v) {
        if (ele == 1) {
            current++;
            maximum = max(current, maximum);
        } else {
            current = 0;
        }
    }

    cout << "Maximum Consecutives : " << maximum;
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
