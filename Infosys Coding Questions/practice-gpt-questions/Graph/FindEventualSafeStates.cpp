#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>>& adj, 
    vector<int>&vis , vector<int>&path, vector<int>&check){

    vis[node]=1;
    path[node]=1;
    check[node]=0;

    for(auto it: adj[node]){
        if(!vis[it]){
            if (dfs(it, adj, vis, path, check)) {
                path[node] = 0;
                return true;
            }
        }
        else if(vis[it] && path[it]){
            path[node] = 0;
            return true;
        }
    } 
    path[node]=0;
    check[node]=1;
    return false;  
}


vector<int> eventualSafeNodes(int v, vector<vector<int>>& adj) {
    // Write your logic here
    vector<int>vis(v, 0);
    vector<int>path(v, 0);
    vector<int>check(v, 0);

    vector<int>ans;

    for(int i=0; i<v; i++){
        if(!vis[i]){
            dfs(i, adj, vis, path, check);
        }
    }

    for(int i=0; i<check.size(); i++){
        if(check[i]==1){
            ans.push_back(i);
        }
    }
    return ans;
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

    vector<int> ans = eventualSafeNodes(V, adj);

    for (int i = 0; i < (int)ans.size(); i++) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << "\n";

    return 0;
}