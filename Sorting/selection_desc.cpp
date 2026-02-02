#include<iostream>
#include<vector>
using namespace std;


int main(){
    vector<int>v={5,24,74,32,243,768,43,6564,32};
    int n = v.size();
    cout<<"Before Sorting"<<endl;
    for(int ele:v){
        cout<<ele<<" ";
    }
    cout<<endl;

    // Selection Sort - Descending Order
    for(int i=0;i<n;i++){
        int maxiIndex = i;
        for(int j=i+1;j<n;j++){
            if(v[j]>v[maxiIndex]){
                maxiIndex = j;
            }
        }
        swap(v[i],v[maxiIndex]);
    }
    cout<<"After Sorting"<<endl;
    for(int ele:v){
        cout<<ele<<" ";
    }
    return 0;
}
