
#include <bits/stdc++.h>
using namespace std;

int frogJump(int ind, vector<int>&heights, vector<int>&dp) {
    // Write your logic here
    int prev1=0, prev2=0, curr;
    if(ind==0) return prev1;

    for(int i=1; i<=ind; i++){
        int left = prev1 + abs(heights[i]-heights[i-1]);
        int right = INT_MAX;
        if(i>1) right = prev2 + abs(heights[i]-heights[i-2]);
        curr = min(left, right);

        prev2=prev1;
        prev1=curr;
    }
    return prev1;
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
