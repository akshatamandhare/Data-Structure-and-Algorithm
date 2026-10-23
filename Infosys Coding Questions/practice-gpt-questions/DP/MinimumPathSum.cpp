
#include <bits/stdc++.h>
using namespace std;

int get_min_path_sum(int i, int j, vector<vector<int>>&grid,
    vector<vector<int>>&dp){
    
    // Recurrence code
    // if(i==0 && j==0){
    //     return grid[i][j];
    // }
    // if(i<0 || j<0){
    //     return INT_MAX / 2;
    // }
    // int up = get_min_path_sum(i-1, j, grid);
    // int down = get_min_path_sum(i, j-1, grid);
    
    // return grid[i][j] + min(up, down); 

    // memo code
    // if(i==0 && j==0){
    //     return grid[i][j];
    // }
    // if(i<0 || j<0){
    //     return INT_MAX / 2;
    // }

    // if(dp[i][j]!=-1) return dp[i][j];

    // int up = get_min_path_sum(i-1, j, grid, dp);
    // int down = get_min_path_sum(i, j-1, grid, dp);
    
    // return dp[i][j] = grid[i][j] + min(up, down); 


    // tabulation code
    // int m = grid.size();
    // int n = grid[0].size();

    // dp[0][0]=grid[0][0];
    
    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){

    //         if (i == 0 && j == 0) {
    //             continue;
    //         }

    //         int up = INT_MAX / 2;
    //         int left = INT_MAX / 2;
    //         if(i>0) up = dp[i-1][j];
    //         if(j>0) left = dp[i][j-1];
    //         dp[i][j]  = grid[i][j] + min(up,left);
    //     }
    // }

    // Space optimizationc code
    int m = grid.size();
    int n = grid[0].size();

    vector<int>prev(n), temp(n);
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            temp[j]=0;
            if (i == 0 && j == 0) {
                temp[j] = grid[0][0];
                continue;
            }

            int up = INT_MAX / 2;
            int left = INT_MAX / 2;
            if(i>0) up = prev[j];
            if(j>0) left = temp[j-1];
            temp[j]  = grid[i][j] + min(up,left);
        }
        prev=temp;
    }

    return prev[n-1];
}

int minPathSum(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));
    return get_min_path_sum(m-1, n-1, grid, dp);
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << minPathSum(grid) << endl;

    return 0;
}
