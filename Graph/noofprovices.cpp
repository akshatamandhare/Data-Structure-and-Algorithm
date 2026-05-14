#include<bits/stdc++.h>
using namespace std;


void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(vis[it] == 0) {
            dfs(it, adj, vis);
        }
    }
}
int countConnected(int v, vector<vector<int>>& edges) {
    int count=0;
    vector<vector<int>> adj(v);

    for(auto it : edges) {

        int u = it[0];
        int v = it[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(v, 0);
    for(int i = 0; i < v; i++) {
        if(vis[i] == 0) {
            count++;
            dfs(i, adj, vis);
        }
    }
    return count;
}
int main() {

    int n, m;

    cout << "Enter No of Nodes and Edges: ";
    cin >> n >> m;

    vector<vector<int>> edges;

    cout << "Enter edges:\n";

    for(int i = 0; i < m; i++) {

        int u, v;
        cin >> u >> v;

        edges.push_back({u, v});
    }

    int ans = countConnected(n, edges);

    cout << "Number of Connected Components: " << ans << endl;

    return 0;
}