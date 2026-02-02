#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    vector<int> v = {43, 546, 432, 5, 2654, 35, 5, 343, 753, 54};
    int n = v.size();

    // Handle empty array
    if (n == 0)
    {
        cout << "Array is empty!" << endl;
        return 0;
    }

    int smallest = INT_MAX;        // Initialize smallest to maximum possible integer
    int secondSmallest = INT_MAX;  // Initialize second smallest to maximum possible integer

    // Traverse array to find smallest and second smallest elements
    for (int i = 0; i < n; i++)
    {
        if (v[i] < smallest)
        {
            secondSmallest = smallest; // old smallest becomes second smallest
            smallest = v[i];           // new smallest found
        }
        else if (v[i] > smallest && v[i] < secondSmallest)
        {
            secondSmallest = v[i];     // update second smallest if in between
        }
    }

    if (secondSmallest != INT_MAX)
        cout << "Second Smallest Element in the Array is : " << secondSmallest << endl;
    else
        cout << "No second smallest element exists." << endl; // all elements might be equal

    return 0;
}

/*
Time Complexity:  O(n) - single pass through the array
Space Complexity: O(1) - only two extra variables used
*/
