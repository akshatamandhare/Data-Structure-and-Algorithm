#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int>& old_arr) {
    // Write your logic here
    int n=old_arr.size();
    vector<int>arr(n);
    int pos_ind=0, neg_index=1;

    for (int i=0; i<n; i++){
        if(old_arr[i]>0){
            arr[pos_ind] = old_arr[i];
            pos_ind+=2;
        }
        else if(old_arr[i]<0){
            arr[neg_index] = old_arr[i];
            neg_index+=2;
        }
    }
    return arr;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> ans = rearrangeArray(arr);

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}