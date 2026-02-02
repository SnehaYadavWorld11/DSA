#include <iostream>
#include <vector>

using namespace std;

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

    // insertion sort - desending order 

    for(int i=1;i<n;i++){
        int j = i;
        while(j>0 && v[j]>v[j-1]){
            swap(v[j],v[j-1]);
            j--;
        }
    }
    cout << "After Sorting" << endl;
    for (int ele : v)
    {
        cout << ele << " ";
    }
    return 0;
}
