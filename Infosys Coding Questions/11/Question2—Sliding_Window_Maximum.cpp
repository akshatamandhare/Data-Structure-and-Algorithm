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

    for(int i=0; i<n; i++){
        if(!dq.empty() && dq.front() <= i-k){
            dq.pop_front();
        }

        while(!dq.empty() && arr[dq.back()]<=arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1) list.push_back(arr[dq.front()]);
    }
    cout<<"Output: ";
    for(int i=0; i<list.size(); i++){
        cout<<list[i]<<" ";
    }
    return 0;
}