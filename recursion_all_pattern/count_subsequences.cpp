#include<bits/stdc++.h>
using namespace std;

int prints(int ind, int s, int sum, int arr[], int n){
    //base case
    if(ind==n){
        if(s==sum) return 1;
        return 0;
    }
    s+=arr[ind];

    int left = prints(ind+1, s, sum, arr, n);

    s-=arr[ind];

    //not pick
    int right = prints(ind+1, s, sum, arr, n);

    return left+right;

}

int main(){
    int arr[3]={1,2,1};
    int n=3;
    int sum=2;

    vector<int> ds;
    int ans = prints(0, 0, sum, arr, n);
    cout<<"Print No. of Counts: "<<ans<<endl;
    return 0;
}