
#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(
    int i, int j, vector<vector<int>>& obstacleGrid, vector<vector<int>>&dp
) {
    // Write your recursive logic here
    // Tabulation code

    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){

            if(obstacleGrid[i][j]==1){
                dp[i][j]=0;
            }
            else if(i==0 && j==0){
                dp[i][j]=1;
            }
            else{
                int up=0;
                int left=0;
                if(i>0) up = dp[i-1][j];
                if(j>0) left = dp[i][j-1];
                dp[i][j]  = up+left;
            }
        }
    }
    return dp[m-1][n-1];
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> obstacleGrid(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> obstacleGrid[i][j];
        }
    }

    vector<vector<int>>dp(m, vector<int>(n, 0));
    cout << uniquePathsWithObstacles(
        m - 1, n - 1, obstacleGrid, dp
    ) << endl;

    return 0;
}
