
#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col,
         vector<vector<char>>& grid,
         vector<vector<int>>& vis) {
    // Write your DFS logic here
    int n = grid.size();
    int m = grid[0].size();

    vis[row][col]=1;

    int delrow[]={-1, 0, +1, 0};
    int delcol[]={0, +1, 0, -1};

    for(int i=0; i<4; i++){
        int nrow = row+delrow[i];
        int ncol = col+delcol[i];

        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
            && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                dfs(nrow, ncol, grid, vis);
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    int count = 0;

    // Write your island-counting logic here

    for(int i=0; i<n; i++){
        for (int j=0; j<m;j++){
            if(!vis[i][j] && grid[i][j]=='1'){
                count++;
                dfs(i, j, grid, vis);
            }
        }
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    cout << numIslands(grid) << "\n";
    return 0;
}
