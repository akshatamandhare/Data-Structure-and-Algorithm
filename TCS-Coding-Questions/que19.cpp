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
    int size;
    cout<<"Enter size of arr: ";
    cin>>size;
    int arr[size];
    int k;
    cout<<"Enter k: ";
    cin>>k;
    cout<<"Enter arr element: ";
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    int left=0; 
    int right=0;

    int n=size;
    int sum=arr[0];
    int count=0;
    while(right<n){
        while (left<=right && sum>k)
        {
            sum-=arr[left];
            left++;
        }
        if(sum==k){
            count++;
        }
        right++;
        if(right<n){
            sum+=arr[right];
        }
    }
    
    cout<< "Number of subarrays: "<<count;
}