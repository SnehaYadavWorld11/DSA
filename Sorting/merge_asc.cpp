// Merge Sort using Divide and Conquer
// Time Complexity: O(n log n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &v, int s, int mid, int e)
{
    vector<int> temp(e-s);
    int i = s;
    int j = mid;
    int k = 0;

    while (i < mid && j < e)
    {
        if (v[i] <= v[j])
        {
            temp[k++] = v[i++];
        }
        else
        {
            temp[k++] = v[j++];
        }
    }

    while (i < mid)
    {
        temp[k++] = v[i++];
    }
    while (j < e)
    {
        temp[k++] = v[j++];
    }

    for (int idx = 0; idx < temp.size(); idx++)
    {
        v[s+idx] = temp[idx];
    }
}

void mergeSort(vector<int> &v, int s, int e)
{

    if(e-s<=1) return;
    int mid = (s + e) / 2;
    mergeSort(v, s, mid);
    mergeSort(v, mid, e);
    merge(v, s, mid, e);
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

    // Merge Sort Asending Order

    mergeSort(v, 0, n);

    cout << "After Sorting" << endl;
    for (int ele : v)
    {
        cout << ele << " ";
    }
    return 0;
}
