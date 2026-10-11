#include <bits/stdc++.h>
using namespace std;

int findSingle(vector<int>& arr) {
    // Write your logic here
    int number =0 ;
    for(int i=0; i<arr.size(); i++){
        number = number ^ arr[i];
    }
        return number;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << findSingle(arr);

    return 0;
}