// Quick Sort (Ascending) using Lomuto-style partition
// Time Complexity: O(n log n) average, O(n^2) worst
// Space Complexity: O(log n) recursion stack

#include <iostream>
#include <vector>

using namespace std;

int findPivotIndex(vector<int>&v, int s,int e){
    int i = s;
    int j = e;
    int pivot = s;

    while(i<j){
        while(i<e && v[i]<=v[pivot]){
            i++;
        }
        while(j>s && v[j]>v[pivot]){
            j--;
        }

        if(i<j){
            swap(v[i],v[j]);
        }
    }
    swap(v[pivot],v[j]);
    return j;

}
void quickSort(vector<int>&v, int s, int e){
    if(s<e){
        int pivot = findPivotIndex(v,s,e);
        quickSort(v,s,pivot-1);
        quickSort(v,pivot+1,e);
    }
}

int main()
{
    vector<int> v = {43, 546, 432, 5, 2654, 35, 5, 343, 753, 54};
    int n = v.size();

    cout << "Before Sorting" << endl;
    for (int ele : v)
    {
        cout << ele << " ";
    }
    cout << endl;

    quickSort(v,0,n-1);


    cout << "After Sorting" << endl;
    for (int ele : v)
    {
        cout << ele << " ";
    }
    return 0;
}
