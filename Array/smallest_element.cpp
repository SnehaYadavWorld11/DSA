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

    int smallest = INT_MAX; // Initialize smallest to maximum integer

    // Traverse array to find the smallest element
    for (int i = 0; i < n; i++)
    {
        if (v[i] < smallest)
        {
            smallest = v[i];
        }
    }

    cout << "Smallest Element in the Array is : " << smallest << endl;

    return 0;
}

/*
Time Complexity:  O(n) - single pass through the array
Space Complexity: O(1) - only one extra variable used
*/
