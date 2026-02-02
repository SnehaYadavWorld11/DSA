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

    // Bubble Sort - Desending Order

    for(int i=0;i<n;i++){
        for(int j=1;j<n-i;j++){
            if(v[j-1]<v[j]){
                swap(v[j-1],v[j]);
            }
        }
    }
    cout << "After Sorting" << endl;
    for (int ele : v)
    {
        cout << ele << " ";
    }
    return 0;
}
