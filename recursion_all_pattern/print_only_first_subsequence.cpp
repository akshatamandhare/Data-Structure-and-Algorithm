#include<bits/stdc++.h>
using namespace std;

bool prints(int ind, vector<int>&ds, int s, int sum, int arr[], int n){
    //base case
    if(ind==n){
        if(s==sum){
            for(auto it: ds) cout<<it<<" ";
            cout<<endl;
            return true;
        }
        else return false;
    }
    
    ds.push_back(arr[ind]);
    s+=arr[ind];

    if(prints(ind+1, ds, s, sum, arr, n)==true) return true;

    s-=arr[ind];
    ds.pop_back();

    //not pick
    if(prints(ind+1, ds, s, sum, arr, n)==true) return true;

    return false;

}

int main(){
    int arr[3]={1,2,1};
    int n=3;
    int sum=2;

    vector<int> ds;
    prints(0, ds, 0, sum, arr, n);
}