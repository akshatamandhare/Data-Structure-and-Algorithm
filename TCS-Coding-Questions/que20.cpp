// Question:
// Given an array of integers and an integer K, find the number of subarrays whose sum is equal to K.

// Example:
// Array = [1, 2, 3]
// K = 3

// Subarrays with sum = 3 → [1,2], [3]

// Output → 2

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cin>>k;
    unordered_map<int, int> mp;
    mp[0]=1;

    int sum=0, count=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        if(mp.find(sum-k)!=mp.end()){
            count+=mp[sum-k];
        }
        mp[sum]++;
    }

    cout<<count;
    return 0;
}