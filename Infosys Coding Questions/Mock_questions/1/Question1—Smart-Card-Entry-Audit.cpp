#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<" the total number of taps recorded in the day  : ";
    int n;
    cin>>n;

    cout<<" N space-separated integers: ";
    int arr[n]={0};
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    unordered_map<int, int> mpp;

    for(int i=0; i<n; i++){
        if(mpp.find(arr[i]) != mpp.end()){
            mpp[arr[i]]++;
        }
        else{
            mpp[arr[i]]=1;
        }
    }
    
    int ans=0;
    for(int i=0; i<n; i++){
        if(mpp[arr[i]]%2 != 0){
            ans=arr[i];
        }
    }
    cout<<"Output: "<<ans;
    return 0;

}