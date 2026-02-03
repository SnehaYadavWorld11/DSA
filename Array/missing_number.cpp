#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v = {0, 1, 2, 4, 5, 6, 7, 8, 9};
    int n = v.size();

    // In this type of problem, the array contains numbers in the range [0, n] with exactly one missing value
    int expectedSum = (n * (n + 1)) / 2;

    int actualSum = 0;
    for (int ele : v) {
        actualSum += ele;
    }

    cout << "Missing Number is : " << expectedSum - actualSum;
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
