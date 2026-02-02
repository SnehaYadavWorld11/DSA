#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    // Input array
    vector<int> v = {43, 546, 432, 5, 2654, 35, 5, 343, 753, 54};
    int n = v.size();

    // Check for empty array
    if (n == 0)
    {
        cout << "Array is empty!" << endl;
        return 0;
    }

    int largest = INT_MIN; // Initialize largest to minimum integer

    // Traverse the array to find the largest element
    for (int i = 0; i < n; i++)
    {
        if (v[i] > largest)
        {
            largest = v[i];
        }
    }

    cout << "Largest Element in the Array is : " << largest << endl;

    return 0;
}

/*
Time Complexity:  O(n) - traverse the array once
Space Complexity: O(1) - only a single variable 'largest' used
*/
