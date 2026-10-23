
#include <bits/stdc++.h>
using namespace std;

int fun(int ind, vector<int>& wt, vector<int>& val, int C, 
    vector<vector<int>>&dp){
    // // base case
    // if(ind==0){
    //     if(wt[0]<=C){
    //         return val[0];
    //     }
    //     return 0;
    // }

    // // recursion
    // int not_take = fun(ind-1, wt, val, C);
    // int take = INT_MIN;
    // if(wt[ind]<=C){
    //     take = val[ind]+fun(ind-1, wt, val, C-wt[ind]);
    // }

    // return max(take, not_take);


    // memo code 
    // base case
    if(ind==0){
        if(wt[0]<=C){
            return val[0];
        }
        return 0;
    }

    if(dp[ind][C]!=-1) return dp[ind][C];

    int not_take = fun(ind-1, wt, val, C, dp);
    int take = INT_MIN;
    if(wt[ind]<=C){
        take = val[ind]+fun(ind-1, wt, val, C-wt[ind], dp);
    }

    return dp[ind][C] = max(take, not_take);
}

void knapsackWithTracking(vector<int>& wt, vector<int>& val, int C, 
    vector<vector<int>>&dp) {
    // Your logic here
    int n=wt.size();

    for(int weight = wt[0]; weight<=C; weight++){
        dp[0][weight]=val[0];
    }

    for(int ind=1; ind<n; ind++){
        for(int weight=0; weight<=C; weight++){
            int not_take = dp[ind-1][weight];
            int take = INT_MIN;
            if(wt[ind]<=weight){
                take = val[ind]+dp[ind-1][weight-wt[ind]];
            }

            dp[ind][weight] = max(take, not_take);
        }
    }

    int ans =dp[n-1][C];

    // Reconstruct the selected indices
    vector<int> selected;
    int weight = C;

    for (int ind = n - 1; ind >= 1; ind--) {
        if (dp[ind][weight] != dp[ind - 1][weight]) {
            selected.push_back(ind + 1);
            weight -= wt[ind];
        }
    }

    // Check the first item
    if (weight >= wt[0] && dp[0][weight] > 0) {
        selected.push_back(1);
    }

    reverse(selected.begin(), selected.end());

    // Print output
    cout << ans << "\n";

    for (int i = 0; i < (int)selected.size(); i++) {
        if (i > 0) cout << " ";
        cout << selected[i];
    }
    cout << "\n";
}

int main() {
    int N, C;
    cin >> N >> C;

    vector<int> wt(N), val(N);
    vector<vector<int>>dp(N, vector<int>(C+1, 0));

    for (int i = 0; i < N; i++) {
        cin >> wt[i] >> val[i];
    }

    knapsackWithTracking(wt, val, C, dp);

    return 0;
}
