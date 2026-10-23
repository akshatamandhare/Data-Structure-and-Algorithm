#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[8]={-2, 1, -3, 4, -1, 2, 1, -5};

    int n=8;
    int maxi=0;
    int sum=0;
    int start=-1;
    int beststart =-1;
    int bestend=-1;

    for(int i=0; i<n; i++){
        if(sum==0) start=i;
        sum+=arr[i];
        if(sum>maxi){
            maxi=sum;
            beststart=start;
            bestend=i;
        }
        if(sum<0){
            sum=0;
        }
    }
    cout<<"Sum: "<<maxi;
    cout<<"\nStart and End: "<<beststart<<" "<<bestend;
}

