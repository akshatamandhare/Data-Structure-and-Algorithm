#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(
    int V,
    vector<vector<pair<int, int>>>& adj,
    int S
) {
    // Write your logic here
    vector<int>dist(V, INT_MAX);
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    >pq;
    // node, dist
    pq.push({S, 0});
    dist[S]=0;

    while (!pq.empty())
    {
        int node = pq.top().first;
        int dis=pq.top().second;
        pq.pop();
        if(dis>dist[node]){ continue;};

        for(auto it: adj[node]){
            int adjnode = it.first;
            int edgewt = it.second;
            if(dis+edgewt<dist[adjnode]){
                dist[adjnode]=dis+edgewt;
                pq.push({adjnode, dist[adjnode]});
            }
        }
    }
    
    return dist;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int S;
    cin >> S;

    vector<int> ans = dijkstra(V, adj, S);

    for (int i = 0; i < V; i++) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << "\n";

    return 0;
}