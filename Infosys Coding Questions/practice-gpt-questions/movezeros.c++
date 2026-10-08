#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& arr) {
    // Write your logic here
    int j=0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]!=0){
            swap(arr[i], arr[j]);
            j++;
        }
    }
    return;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    moveZeroes(arr);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}