
#include <bits/stdc++.h>
using namespace std;

int fib(int n, vector<int>& dp) {
    // if (n <= 1) return dp[n] = n;
    // if (dp[n] != -1) return dp[n];
    
    int prev1=1, prev2=0, curr;

    if(n<=1) return n;
    for(int i=2; i<=n; i++){
        int left = prev1;  
        int right = prev2; 
        curr = right + left;

        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, -1);

    cout << fib(n, dp) << "\n";

    return 0;
}
