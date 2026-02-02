#include <iostream>
#include <vector>
using namespace std;

// Function to check if the array is sorted in ascending order
void checkArraySortedOrNot(vector<int>& v){
    int n = v.size();

    if(n <= 1){
        cout << "Sorted" << endl;
        return;
    }

    for(int i = 1; i < n; i++){
        if(v[i-1] > v[i]){
            cout << "Array is Not Sorted" << endl;
            return;
        }
    }

    cout << "Array is Sorted" << endl;
}

int main()
{
    vector<int> v1 = {1,2,24,67,79};
    vector<int> v2 = {1,1,5,2,6,75};

    checkArraySortedOrNot(v1); // Output: Array is Sorted
    checkArraySortedOrNot(v2); // Output: Array is Not Sorted

    return 0;
}

/*
Time Complexity:  O(n) - single traversal of the array
Space Complexity: O(1) - no extra space used
*/
