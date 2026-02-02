#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {5, 24, 74, 32, 243, 768, 43, 6564, 32};

    cout << "Before Sorting" << endl;
    for (int ele : v) {
        cout << ele << " ";
    }
    cout << endl;

    // Selection Sort
    for (int i = 0; i < v.size(); i++) {
        int minIndex = i;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }
        swap(v[minIndex], v[i]);
    }

    cout << "After Sorting" << endl;
    for (int ele : v) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}

