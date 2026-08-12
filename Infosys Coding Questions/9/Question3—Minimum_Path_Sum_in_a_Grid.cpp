#include<bits/stdc++.h>
using namespace std;

int sum(vector<vector<int>>&grid){
    int n=grid.size();
    int m=grid[0].size();
        
    priority_queue<
        pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>
    > pq;
    pq.push({grid[0][0], {0, 0}});
    
    vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
    dist[0][0]=grid[0][0];
        
    while(!pq.empty()){
        auto it=pq.top();
        int dis=it.first;
        int row=it.second.first;
        int col=it.second.second;
        pq.pop();

        if(dis>dist[row][col]) continue;

        if(row==n-1 && col==m-1) return dist[n-1][m-1];

        int delrow[]={-1, 0, +1, 0};
        int delcol[]={0, +1, 0, -1};

        for(int i=0; i<4; i++){
            int newr=row+delrow[i];
            int newc=col+delcol[i];

            if(newr>=0 && newr<n && newc>=0 && newc<m
                && dis+grid[newr][newc]<dist[newr][newc]){
                    dist[newr][newc]=dis+grid[newr][newc];
                    pq.push({dist[newr][newc],{newr, newc}});
                }
        }
    }
    return dist[n-1][m-1];
}

int main(){
    int r, c;
    cin>>r>>c;

    vector<vector<int>> grid(r, vector<int>(c));

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>grid[i][j];
        }
    }

    int ans=sum(grid);
    cout<<"Minimun path sum: "<<ans;
    return 0;
}