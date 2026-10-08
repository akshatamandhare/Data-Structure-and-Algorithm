#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string>s(n);

    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    // Sort strings
    sort(s.begin(), s.end());
    string lastString = s[n-1];
    string firstString = s[0];
    string res="";
    for(int i=0; i<min(firstString.size(), lastString.size()); i++){
        if(firstString[i]==lastString[i]){
            res+=firstString[i];
        }
        else{
            break;
        }
    }
    
    if(res != "") cout<<res;
    else cout<<" ";
    return 0;
}

