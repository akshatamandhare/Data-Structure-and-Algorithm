
#include <bits/stdc++.h>
using namespace std;

int fun(int ind, int buy, vector<int>& prices, vector<vector<int>>&dp){
    // int n=prices.size();
    // int profit =0;
    // if(ind==n){
    //     return 0;
    // }

    // if(buy){
    //     profit= max(-prices[ind]+fun(ind+1, 0, prices), 
    //                 0+fun(ind+1, 1, prices));
    // }
    // else{
    //     profit= max(prices[ind]+fun(ind+1, 1, prices), 
    //                 0+fun(ind+1, 0, prices));
    // }
    // return profit;


    // memo code 
    int n=prices.size();
    int profit =0;
    if(ind==n){
        return 0;
    }

    if(dp[ind][buy]!=-1) return dp[ind][buy];

    if(buy){
        profit= max(-prices[ind]+fun(ind+1, 0, prices, dp), 
                    0+fun(ind+1, 1, prices, dp));
    }
    else{
        profit= max(prices[ind]+fun(ind+1, 1, prices, dp), 
                    0+fun(ind+1, 0, prices, dp));
    }
    return dp[ind][buy] = profit;
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>>dp(n+1,vector<int>(2, 0));

    // dp[n][1]=0;
    // dp[n][0]=0;

    // for(int ind =n-1; ind>=0; ind--){

    //     for(int buy=0 ; buy<=1; buy++){
    //         int profit =0;

    //         if(buy){
    //             profit= max(-prices[ind]+dp[ind+1][0], 
    //                         0+dp[ind+1][1]);
    //         }
    //         else{
    //             profit= max(prices[ind]+dp[ind+1][1], 
    //                         0+dp[ind+1][0]);
    //         }
    //         dp[ind][buy] = profit;
    //     }

    // }
    // return dp[0][1];


    // space optimised
    // return fun(0, 1, prices, dp);
}

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    cout << maxProfit(prices) << '\n';
    return 0;
}
