#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long power(long long B, long long E) {
    // base case
    if(E==0) return 1;

    // calculate half
    long long halfPower = power(B, E/2);

    long long result=(halfPower*halfPower)%MOD;

    if(E%2==1){
        // even case
        return (result*B)%MOD;
    }
    else{
        // even case
        return result;
    }
}

int main(){
    long long B, E;
    cin>>B>>E;
    // Handle negative B
    B = (B % MOD + MOD) % MOD;
    long long ans=power(B, E);
    cout<<"Output: "<<ans;
    return 0;
}