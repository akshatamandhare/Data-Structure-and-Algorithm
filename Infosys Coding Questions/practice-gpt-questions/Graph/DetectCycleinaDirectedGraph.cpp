#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>>&adj,
    vector<int>&vis, vector<int>&path ){
        vis[node]=1;
        path[node]=1;

        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it, adj, vis, path)==true) return true;
            }
            else if(vis[it] && path[it]){
                return true;
            }
        }
        path[node]=0;
        return false;
    }

bool isCycle(int v, vector<vector<int>>& adj) {
    // Write your logic here

    vector<int>vis(v, 0);
    vector<int>path(v, 0);

    for(int i=0; i<v; i++){
        if(!vis[i] && !path[i]){
            if(dfs(i, adj, vis, path)) return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
    }

    cout << (isCycle(V, adj) ? 1 : 0) << "\n";

    return 0;
}