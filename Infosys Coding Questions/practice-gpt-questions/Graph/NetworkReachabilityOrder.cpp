
#include <bits/stdc++.h>
using namespace std;

vector<int> bfsTraversal(int V, vector<vector<int>>& adj, int S) {
    // Write your logic here
    int vis[V] = {0};
    vis[S]=1;

    queue<int>q;
    q.push(S);

    vector<int>bfs;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int S;
    cin >> S;

    for (int i = 0; i < V; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    vector<int> ans = bfsTraversal(V, adj, S);

    for (int node : ans) {
        cout << node << " ";
    }
    cout << "\n";

    return 0;
}
