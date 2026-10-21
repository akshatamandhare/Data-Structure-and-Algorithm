
#include <bits/stdc++.h>
using namespace std;

int maxNonAdjacentSum(int ind, vector<int>& arr, vector<int>&dp) {
    // Write your recursive logic here
    // if(ind == 0) return arr[ind];
    // if(ind < 0) return 0;

    // int pick = arr[ind]+maxNonAdjacentSum(ind-2, arr);

    // int not_pick = 0+maxNonAdjacentSum(ind-1, arr);

    // return max(pick, not_pick);


    //moemo code
    if(ind == 0) return arr[0];
    if(ind < 0) return 0;

    if(dp[ind]!=-1) return dp[ind];

    int pick = INT_MIN;
    if(ind>=1) pick = arr[ind]+maxNonAdjacentSum(ind-2, arr, dp);

    int not_pick = 0+maxNonAdjacentSum(ind-1, arr, dp);

    return dp[ind] =  max(pick, not_pick);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> dp(n+1, -1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Tabulation
    // dp[0] = arr[0];
    // dp[1] = max(arr[1], arr[0]);

    // for(int i=2; i<n; i++){
    //     int pick = arr[i]+dp[i-2];
    //     int not_pick = 0+dp[i-1];
    //     dp[i]=max(pick, not_pick);
    // }
    // cout<< dp[n-1];

    //space optimization
    int prev1=arr[0];
    int prev2=0;
    int curr;

    for(int i=1; i<n; i++){
        int pick = arr[i]+prev2;
        int not_pick = 0+prev1;
        curr=max(pick, not_pick);
        prev2=prev1;
        prev1=curr;
    }
    cout<< prev1;

    // cout << maxNonAdjacentSum(n - 1, arr, dp) << "\n";

    return 0;
}
