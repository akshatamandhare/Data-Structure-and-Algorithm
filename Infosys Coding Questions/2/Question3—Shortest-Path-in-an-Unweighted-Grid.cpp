#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<char>>grid(n, vector<char>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }

    vector<vector<int>>vis(n, vector<int>(m, -1));

    int delrow[]={-1, 0, +1, 0};
    int delcol[]={0, +1, 0, -1};

    queue<pair<int, int>>q;
    q.push({0, 0});
    vis[0][0] = 0;
    while ( !q.empty()){
        int row=q.front().first;
        int col=q.front().second;

        q.pop();
        for(int i=0; i<4; i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
            && grid[nrow][ncol] == '.' && vis[nrow][ncol] == -1){
                q.push({nrow, ncol});
                vis[nrow][ncol] = vis[row][col] + 1;
            }
        }
    }
    cout<<"Output: "<<vis[n-1][m-1];
    return 0;
}