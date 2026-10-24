#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;

    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<int> list;
    deque<int>dq;

    // for(int i=0; i<n; i++){
    //     if(!dq.empty() && dq.front() <= i-k){
    //         dq.pop_front();
    //     }

    //     while(!dq.empty() && arr[dq.back()]<=arr[i]){
    //         dq.pop_back();
    //     }
    //     dq.push_back(i);
    //     if(i>=k-1) list.push_back(arr[dq.front()]);
    // }

    int sum=0;
    vector<int>ans;
    for(int i=0; i<k; i++){
        sum+=arr[i];
    }
    for(int i=k+1; i<n; i++){
        sum+=arr[i-1]+arr[i+1];
        ans.push_back(sum);
    }
    cout<<"Output: ";
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}