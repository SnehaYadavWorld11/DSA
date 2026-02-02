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

    int largest = INT_MIN;
    int secondLargest = -1;

    // Traverse array to find largest and second largest
    for (int i = 0; i < n; i++)
    {
        if (v[i] > largest)
        {
            secondLargest = largest;
            largest = v[i];
        }
        else if (v[i] < largest && v[i] > secondLargest)
        {
            secondLargest = v[i];
        }
    }

    cout << "Second Largest Element in the Array is : " << secondLargest << endl;

    return 0;
}

/*
Time Complexity:  O(n) - single pass through the array
Space Complexity: O(1) - only two extra variables used
*/
