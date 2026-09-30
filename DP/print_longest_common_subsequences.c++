#include <bits/stdc++.h>
using namespace std;


int main(){
    string s1, s2;
    cout<<"Enter s1: ";
    cin>>s1;
    cout<<"Enter s2: ";
    cin>>s2;


    int n=s1.length(), m = s2.length();
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    
    //basecase
    
    for(int j=0; j<=m; j++) dp[0][j] = 0;
    for(int i=0; i<=n; i++) dp[i][0] = 0;
    
    
    for(int ind1=1; ind1<=n; ind1++){
        for(int ind2 =1; ind2<=m; ind2++){
            //match string
            if(s1[ind1-1] == s2[ind2-1]){
                dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            }
            else{
                //not match string
                dp[ind1][ind2] = (0 + max(dp[ind1-1][ind2], dp[ind1][ind2-1]));
            }
        }
    }
    
    int len_comm_str = dp[n][m];
    
    int index = len_comm_str - 1;
    string s="";

    for(int i=0; i<len_comm_str; i++) s+='$'; 

    int i = n, j = m;
    while (i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1]){
            s[index]=s1[i-1];
            index--;
            i--, j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            i=i-1;
        }else{
            j=j-1;
        }
    }
    cout<<"Common string: "<<s;
    
    return 0;
}

