#include<bits/stdc++.h>
using namespace std;

int main(){
    string S, P;
    cin>>S>>P;

    int n=S.length();
    
    int hash[256]={0};

    for(int i=0; i<P.length(); i++){
        hash[P[i]]++;
    }

   int minlen = INT_MAX;
   int startinx =-1, right=0, left=0;
    int cnt=0;

    while(right<S.length()){
        if(hash[S[right]]>0){
            cnt++;

        }
        hash[S[right]]--;

        while(cnt == P.length()){
            if(right-left+1 < minlen){
                minlen=right-left+1;
                startinx=left;
            }

            hash[S[left]]++;
            
            if(hash[S[left]]>0){
                cnt--;
            }

            left++;
        }
        right++;
    }

    if (startinx == -1){
        cout<<" ";
    }else{ 
        cout<<S.substr(startinx, minlen); 
    }

    return 0;
    
}