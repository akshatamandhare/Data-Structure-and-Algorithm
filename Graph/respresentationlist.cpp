#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cout<<"Enter n vertex and m edges : ";
    cin>>n>> m;


    //undirected graph
    vector<int>adj[n+1];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(u);
        adj[v].push_back(v);
    }

    // directed graph
    vector<int>adj[n+1];
    for(int i=0; i<m; i++){
        int u;
        cin>>u;
        adj[u].push_back(u);
    }

    return 0;
}