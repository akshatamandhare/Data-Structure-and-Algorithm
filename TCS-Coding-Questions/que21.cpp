// A data analytics system continuously records the number of transactions processed by a server every minute. Due to fluctuating traffic, the operations team wants to monitor the minimum load observed over every consecutive block of K minutes to detect potential performance bottlenecks.

// You are given an integer array A of size N, where:

// A[i] represents the number of transactions processed in the i-th minute.

// A fixed integer K represents the size of the observation window.

// For every contiguous subarray (window) of size K, determine the minimum number of transactions recorded within that window.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter Size of Array: ";
    cin>>n;
    int arr[n];

    cout<<"Enter array element: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;

    int result=0;

    for(int i=0; i<k; i++){
        result=min(result, arr[i]);
    }
    cout<<k-0+1<<" : "<<result;
    int i=0, j=k+1;
    while(j<n){
        int result=min(result, arr[i]);
        
    }

}