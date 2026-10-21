
#include <bits/stdc++.h>
using namespace std;

int climbStairs(int ind, vector<int>&dp) {
    // Write your logic here
    // if(n==0) return 1;
    // if(n==1) return 1;

    // int left=climbStairs(n-1);
    // int right = climbStairs(n-2);
    // return left + right;


    // // memo code
    // if(ind==0) return 1;
    // if(ind==1) return 1;

    // if(dp[ind]!=-1) return dp[ind];

    // int left=climbStairs(ind-1, dp);
    // int right = climbStairs(ind-2, dp);
    // return dp[ind] = left + right;
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);

    int prev1=1, prev2=1, curr;
    if (n <= 1) return 1;

    for(int i=2; i<=n; i++){
        int left = prev1;
        int right = prev2;
        curr=left+right;
        prev2=prev1;
        prev1=curr;
    }



    cout<< prev1;

    // cout << climbStairs(n, dp) << "\n";

    return 0;
}
