#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int V, vector<vector<int>>& adj, int S) {
    vector<int> dist(V, -1);
    queue<int> q;

    dist[S] = 0;
    q.push(S);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto it : adj[node]) {
            if (dist[it] == -1) {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }

    return dist;
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

    vector<int> ans = shortestPath(V, adj, S);

    for (int i = 0; i < V; i++) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << "\n";

    return 0;
}