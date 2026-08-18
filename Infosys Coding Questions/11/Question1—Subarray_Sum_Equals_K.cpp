#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    unordered_map<int, int>mpp;
    int prefixsum=0;
    mpp[0]=1;
    int cnt=0;

    for(int i=0; i<n; i++){
        prefixsum+=arr[i];
        int removal=prefixsum-k;
        cnt+=mpp[removal];
        mpp[prefixsum]+=1;
        
    }

    cout<<"Count of Subarray: "<<cnt;

    return 0;

}
