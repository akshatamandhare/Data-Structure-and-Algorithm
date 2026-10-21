
#include <bits/stdc++.h>
using namespace std;

int frogJumpK(int ind, int k, vector<int>& heights, vector<int>&dp) {
    // Write your recursive logic here
    if (ind == 0) return dp[0];
    dp[0] = 0;

    for(int i=1; i<=ind; i++){
        int min_energy = INT_MAX;
        for(int j=1; j<=k; j++){
            if(i-j>=0){
                int jump = dp[i-j]+ abs(heights[i]-heights[i-j]);
                min_energy = min(min_energy, jump);
            }
        }
        dp[i] = min_energy;
    }
    return dp[ind];
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> heights(n);
    vector<int> dp(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    cout << frogJumpK(n - 1, k, heights, dp) << "\n";

    return 0;
}
