#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(vector<int>& arr) {
    // Write your logic here
    int sum=0;
    int maxi=INT_MIN;
    int startind=0;
    int ansstart, ansend;
    for(int i=0; i<arr.size(); i++){

        if(sum==0) startind=i;
        sum+=arr[i];
        if(sum>maxi){
            ansstart=startind;
            ansend=i;
            maxi=sum;
        }

        if(sum<0){
            sum=0;
        }
    }
    return maxi;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    return maxSubarraySum(arr);
}