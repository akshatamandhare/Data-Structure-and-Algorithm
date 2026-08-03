#include<bits/stdc++.h>
using namespace std;
long long fun(int ind, vector<int>& arr, int k){
    if (ind < k)
        return arr[ind];

    long long ans = LLONG_MAX;

    for (int prev = ind - k; prev <= ind - 1; prev++) {

        if (prev >= 0) {
            ans = min(ans, fun(prev, arr, k));
        }
    }

    return arr[ind] + ans;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int>arr(n, 0);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<fun(n-1, arr, k);
    return 0;
}