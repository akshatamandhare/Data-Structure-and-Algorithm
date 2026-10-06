#include <bits/stdc++.h>
using namespace std;

int fun(string &s1, string &s2, vector<vector<int>>&dp){
    //basecase
    int n=s1.length();
    int m=s2.length();

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
    
    return dp[n][m];
}

int main() {
    string s1;

    cout << "Enter s1: ";
    cin >> s1;

    string t = s1;

    reverse(t.begin(), t.end());

    int n = s1.length();
    int m = t.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int ans = fun(s1, t, dp);

    cout << "Longest Palindromic Subsequence: " << ans << endl;

    return 0;
}

