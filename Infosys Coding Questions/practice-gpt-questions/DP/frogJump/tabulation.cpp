
#include <bits/stdc++.h>
using namespace std;

int frogJump(int ind, vector<int>&heights, vector<int>&dp) {
    // Write your logic here
    if (ind == 0) return dp[1];
    dp[0] = 0;

    for(int i=1; i<=ind; i++){
        int left = dp[i-1] + abs(heights[i]-heights[i-1]);
        int right = INT_MAX;
        if(i>1) right = dp[i-2] + abs(heights[i]-heights[i-2]);
        dp[i] = min(left, right);
    }
    return dp[ind];
}

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    vector<int> dp(n+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    cout << frogJump(n-1, heights, dp) << "\n";

    return 0;
}
