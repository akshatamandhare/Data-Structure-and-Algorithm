#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cout<<"Enter n vertex and m edges : ";
    cin>>n>> m;

    int adj[n+1][n+1];
    //undirected graph
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }

    // directed graph
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
    }

    return 0;
}