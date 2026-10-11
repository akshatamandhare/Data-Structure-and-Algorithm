#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int>& arr) {
    // Write your logic here
    int n=arr.size();
    vector<int>ans;
    int leader = arr[n-1];
    ans.push_back(leader);
    for(int i=n-2; i>=0; i--){
        if(arr[i]>leader){
            ans.push_back(arr[i]);
            leader=arr[i];
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> ans = leaders(arr);

    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}