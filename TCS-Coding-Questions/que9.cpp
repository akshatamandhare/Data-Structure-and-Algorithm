#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<endl;
    cout<<"Enter 1's and 0's: ";
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int low=0, high=n-1;
    int ans=-1;

    while (low<=high)
    {
        int mid = low + (high - low) / 2;
        if(arr[mid]==0){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    
    }
    cout<<ans+1;
}