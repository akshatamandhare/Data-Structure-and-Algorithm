#include<bits/stdc++.h>
using namespace std;

const long long  mod=1000000007;

int main(){
    string s;
    cin>>s;
    long long sum=0;
    int n=s.length();

    for(char ch=0; ch<n; ch++){
        if(s[ch] == 'a' || s[ch] == 'e' || s[ch] == 'i' ||
        s[ch] == 'o' || s[ch] == 'u'){
            sum+=((ch+1)*(n-ch))%mod;
        }
    }
    cout<<"output: "<<sum;
}