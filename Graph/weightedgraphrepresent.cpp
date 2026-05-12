#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cout<<"Enter n vertex and m edges : ";
    cin>>n>> m;
    
    //matrix 
    // int adj[n+1][n+1];
    // for(int i=0; i<m; i++){
    //     int u,v;
    //     cin>>u>>v;
    //     int wt;
    //     cin>>wt;
    //     adj[u][v]=wt;
    //     adj[v][u]=wt;
    // }

    //list
    vector<pair<int, int>> adj[n+1];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        int wt;
        cin>>wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    return 0;
}


