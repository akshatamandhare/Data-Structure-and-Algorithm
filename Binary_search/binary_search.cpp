#include <bits/stdc++.h>
using namespace std;

int binarysearch(int arr[], int target, int n){
    int low=0, high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]>target){
            high=mid-1;
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else if(arr[mid]==target){
            return mid;
        }
    }
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

    int ans = binarysearch(arr, target, n);
    cout<<endl<<ans+1;
}