
#include <bits/stdc++.h>
using namespace std;

int spreadInfection(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    // Queue stores {time, {row, col}}
    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    // Step 1: Count healthy samples and add
    // all initially infected samples to the queue
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==2){
                q.push({0, {i, j}});
                vis[i][j]=2;
            }
            else{
                vis[i][j]=0;
            }
        }
    }

    // Step 2: Define four directions
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};
    int tm = 0;
    // Step 3: Perform multi-source BFS
    while (!q.empty())
    {
        int r = q.front().second.first;
        int c = q.front().second.second;
        int t = q.front().first;

        q.pop();

        tm = max(tm, t);
        for(int i=0; i<4; i++){
            int nrow = r+delrow[i];
            int ncol = c+delcol[i];

            if( nrow>=0 && nrow<n && ncol>=0 && ncol<m
                && grid[nrow][ncol]==1 && vis[nrow][ncol]!=2){
                    q.push({t+1,{nrow, ncol}});
                    vis[nrow][ncol]=2;
                }
        }

    }
    
    // Step 4: Return the minimum time,
    // or -1 if healthy samples remain
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j]!=2 && grid[i][j]==1){
                return -1;
            }
        }
    }
    return tm;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    cout << spreadInfection(grid) << "\n";

    return 0;
}
