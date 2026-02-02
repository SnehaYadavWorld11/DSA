#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted arrays into a single sorted array without duplicates
int mergeSortedUnique(vector<int>& v1, vector<int>& v2, int n1, int n2, vector<int>& result) {
    int idx = 0; // index for result array
    int i = 0, j = 0;

    // Merge arrays while removing duplicates
    while(i < n1 && j < n2) {
        if(v1[i] <= v2[j]) {
            if(idx == 0 || result[idx - 1] != v1[i]) result[idx++] = v1[i++];
            else i++; // skip duplicate
        } else {
            if(idx == 0 || result[idx - 1] != v2[j]) result[idx++] = v2[j++];
            else j++; // skip duplicate
        }
    }

    // Copy remaining elements from v1
    while(i < n1) {
        if(result[idx - 1] != v1[i]) result[idx++] = v1[i++];
        else i++;
    }

    // Copy remaining elements from v2
    while(j < n2) {
        if(result[idx - 1] != v2[j]) result[idx++] = v2[j++];
        else j++;
    }

    return idx; // number of unique elements
}

int main() {
    vector<int> v1 = {1,1,3,5,5,7,9};
    vector<int> v2 = {2,2,4,6,6,8,10};

    int n1 = v1.size();
    int n2 = v2.size();
    vector<int> result(n1 + n2); // maximum possible size

    int idx = mergeSortedUnique(v1, v2, n1, n2, result);

    cout << "Merged sorted array without duplicates: ";
    for(int i = 0; i < idx; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity:  O(n1 + n2) - each element is processed once
Space Complexity: O(n1 + n2) - result array stores merged elements
*/
