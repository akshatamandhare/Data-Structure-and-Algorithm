// If Target is present in the array then return index 
// If Target is not present in the array Insert at the position such that array should be sorted

#include <bits/stdc++.h>
using namespace std;

int lowerbound(int arr[], int target, int n){
    int low=0, high=n-1;
    int ans=n;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>=target){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int main(){
    int arr[10]={10,40,50,20,90,80,46,53,78,100};
    int n=10;
    int target;
    cout<<"Enter arr element to search: ";
    cin>>target; 
    sort(arr, arr+n);  
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    } 

    int ans = lowerbound(arr, target, n);
    cout<<endl<<ans+1;
}