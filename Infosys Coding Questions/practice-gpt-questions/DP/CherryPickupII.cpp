
#include <bits/stdc++.h>
using namespace std;

int cherryPickup(int i, int j1, int j2,
                 vector<vector<int>>& grid, vector<vector<vector<int>>> &dp) {
    // Write your recursive logic here

    int n=grid.size();
    int m=grid[0].size();

    // if(j1<0 || j1>=m || j2<0 || j2>=m) return INT_MIN/2;

    // if(i==n-1){
    //     if(j1==j2){
    //         return grid[i][j1]; 
    //     }
    //     else{
    //         return grid[i][j1]+grid[i][j2];
    //     }
    // }
    // int maxi = INT_MIN / 2;
    // int dj[]={-1, 0, +1};
    // for(int dj1=-1; dj1<=1; dj1++){
    //     for(int dj2=-1; dj2<=1; dj2++){
    //         if(j1==j2){
    //             maxi = max(maxi, grid[i][j1]+cherryPickup(i+1, j1+dj1, j2+dj2, grid));
    //         }
    //         else{
    //             maxi = max(maxi, grid[i][j1] + grid[i][j2]+ cherryPickup(i+1, j1+dj1, j2+dj2, grid));
    //         }
    //     }
    // }
    // return maxi;

    // Memo code
    if(j1<0 || j1>=m || j2<0 || j2>=m) return INT_MIN/2;

    if(i==n-1){
        if(j1==j2){
            return grid[i][j1]; 
        }
        else{
            return grid[i][j1]+grid[i][j2];
        }
    }

    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

    int maxi = INT_MIN / 2;
    int dj[]={-1, 0, +1};
    for(int dj1=-1; dj1<=1; dj1++){
        for(int dj2=-1; dj2<=1; dj2++){
            if(j1==j2){
                maxi = max(maxi, grid[i][j1]+cherryPickup(i+1, j1+dj1, j2+dj2, grid, dp));
            }
            else{
                maxi = max(maxi, grid[i][j1] + grid[i][j2]+ cherryPickup(i+1, j1+dj1, j2+dj2, grid, dp));
            }
        }
    }
    return dp[i][j1][j1] = maxi;
}

int main() {
    int m, n;
    cin >> m >> n;
    // row, col
    vector<vector<int>> grid(m, vector<int>(n));
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Tabulation code
    for (int j1 = 0; j1 < n; j1++) {
        for (int j2 = 0; j2 < n; j2++) {
            if(j1==j2){
                dp[m-1][j1][j2] = grid[m-1][j1];
            }else{
                dp[m-1][j1][j2] = grid[m-1][j1]+grid[m-1][j2];
            } 
        }
    }
    for(int i=m-2; i>=0; i--){
        for(int j1=0; j1<n; j1++){
            for(int j2=0; j2<n; j2++){

                int maxi=INT_MIN/2;
                int value=0;
                for(int dj1=-1; dj1<=1; dj1++){
                    for(int dj2=-1; dj2<=1; dj2++){
                        if(j1==j2){
                            value = grid[i][j1];
                        }
                        else{
                            value = grid[i][j1]+grid[i][j2];
                        }

                        
                        if(j1+dj1>=0 && j1+dj1<n && j2+dj2>=0 && j2+dj2<n){
                            value+=dp[i+1][j1+dj1][j2+dj2];
                        }
                        else{
                            value=INT_MIN/2;
                        }

                        maxi = max(maxi, value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }

    cout<<dp[0][0][n-1];

    // cout << cherryPickup(0, 0, n - 1, grid, dp) << endl;
    return 0;
}
