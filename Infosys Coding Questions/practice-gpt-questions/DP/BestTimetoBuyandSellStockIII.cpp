
#include <bits/stdc++.h>
using namespace std;

int fun(int ind, int buy, vector<int>& prices, int C,
        vector<vector<vector<int>>>& dp){
    // int n=prices.size();
    // int profit = 0; 

    // if(C==0) return 0;
    // if(ind==n) return 0;

    // if(buy){
    //     profit = max(-prices[ind]+fun(ind+1, 0, prices, C), 
    //                     0+fun(ind+1, 1, prices, C));
    // }
    // else{
    //     profit = max(prices[ind]+fun(ind+1, 1, prices, C-1), 
    //                     0+fun(ind+1, 0, prices, C));
    // }
    // return profit;


    int n=prices.size();
    int profit = 0; 
    
    if(C==0) return 0;
    if(ind==n) return 0;

    if(dp[ind][buy][C]!=-1){
        return dp[ind][buy][C];
    }

    if(buy){
        profit = max(-prices[ind]+fun(ind+1, 0, prices, C, dp), 
                        0+fun(ind+1, 1, prices, C, dp));
    }
    else{
        profit = max(prices[ind]+fun(ind+1, 1, prices, C-1, dp), 
                        0+fun(ind+1, 0, prices, C, dp));
    }
    dp[ind][buy][C] = profit;
}

int maxProfit(vector<int>& prices) {
    int n=prices.size();
    vector<vector<vector<int>>>dp(n+1,
        vector<vector<int>>(2, 
        vector<int>(3, -1))
    );

    int C = 2;
   
    // base cases
    // if(C==0)
    for(int ind =0 ; ind<n; ind++){
        for(int buy=0; buy<=1; buy++){
            dp[ind][buy][0]=0;
        }
    }
    // if(ind==n)
    for(int C=0 ; C<=2; C++){
        for(int buy=0; buy<=1; buy++){
            dp[n][buy][C]=0;
        }
    }
    // if(buy->0, 1)
    for(int ind =0 ; ind<n; ind++){
        for(int c=0 ; C<=2; C++){
            dp[ind][0][C]=0;
            dp[ind][1][C]=0;
        }
    }

    for(int ind=n-1; ind>=0; ind--){
        int profit=0;
        for(int buy=0; buy<=1; buy++){
            for(int C=1; C<=2; C++){
                if(buy){
                    profit = max(-prices[ind]+dp[ind+1][0][C], 
                                    dp[ind+1][1][C]);
                }
                else{
                    profit = max(prices[ind]+dp[ind+1][1][C-1], 
                                    dp[ind+1][0][C]);
                }
                dp[ind][buy][C] = profit;
            }
        }
    }
    return dp[0][1][2];
    // return fun(0, 1, prices, C, dp);;
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
