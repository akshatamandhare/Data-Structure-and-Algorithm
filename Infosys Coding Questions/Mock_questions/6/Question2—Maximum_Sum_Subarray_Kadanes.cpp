#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[8]={-2, 1, -3, 4, -1, 2, 1, -5};

    int maxi=0;
    int sum=0;
    int start=-1, end=-1;

    for(int i=0; i<8; i++){
        if(sum==0) start=i;
        sum+=arr[i];
        
        if(sum>maxi){
            maxi=max(maxi, sum);
            end=i;
        }
        if(sum<0) sum=0;
    }
    cout<<maxi<<" "<<start<<" "<<end;
}

