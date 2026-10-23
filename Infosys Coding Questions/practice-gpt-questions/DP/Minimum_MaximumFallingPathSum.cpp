
#include <bits/stdc++.h>
using namespace std;

int minFallingPathSum(int i, int j, int n, vector<vector<int>>& matrix,
vector<vector<int>>& dp) {
    // // Write your recursive logic here
    // if(i<0 || j<0 || i>=n || j>=n) return INT_MAX/2;

    // if(i==0) return matrix[i][j];

    // int up = matrix[i][j]+minFallingPathSum(i-1, j, n, matrix);
    // int up_left = matrix[i][j]+minFallingPathSum(i-1, j-1, n, matrix);
    // int up_right = matrix[i][j]+minFallingPathSum(i-1, j+1, n, matrix);

    // return min(up, min(up_left, up_right));

    // memo code
    if(i<0 || j<0 || i>=n || j>=n) return INT_MAX/2;

    if(i==0) return matrix[i][j];

    if(dp[i][j]!=-1) return dp[i][j];

    int up = matrix[i][j]+minFallingPathSum(i-1, j, n, matrix, dp);
    int up_left = matrix[i][j]+minFallingPathSum(i-1, j-1, n, matrix, dp);
    int up_right = matrix[i][j]+minFallingPathSum(i-1, j+1, n, matrix, dp);

    int mini = min(up, min(up_left, up_right));
    return dp[i][j] = mini;
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Tabulation code
    for(int j=0; j<n; j++){
        dp[0][j] = matrix[0][j];
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
 
            int up = matrix[i][j]+dp[i-1][j];

            int up_left = INT_MAX / 2;
            if (j > 0) {
                up_left = matrix[i][j] + dp[i - 1][j - 1];
            }

            int up_right = INT_MAX / 2;
            if (j < n - 1) {
                up_right = matrix[i][j] + dp[i - 1][j + 1];
            }
            int mini = min(up, min(up_left, up_right));
            dp[i][j] = mini;
        }
    }

    int ans = INT_MAX;

    for (int j = 0; j < n; j++) {
        // ans = min(ans, minFallingPathSum(n-1, j, n, matrix, dp));
        ans = min(ans, dp[n-1][j]);
    }

    cout << ans << endl;
    return 0;
}
