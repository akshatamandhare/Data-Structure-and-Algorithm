#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    int maxlen=0;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum+=arr[i];
            if(sum<=k){
                maxlen=max(maxlen, j-i+1);
            }
            else{
                break;
            }
        }
    }
    cout<<"output: "<<maxlen;
    return 0;
}