#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(
    int V,
    vector<vector<pair<int, int>>>& adj,
    int S, int D
) {
    // Write your logic here
    vector<int>dist(V, INT_MAX);
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    >pq;
    vector<int>parent(V);
    // node, dist
    pq.push({S, 0});
    dist[S]=0;

    for(int i=0; i<V; i++){
        parent[i]=i;
    }

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
                parent[adjnode]=node;
                pq.push({adjnode, dist[adjnode]});
            }
        }
    }

    if(dist[D]==INT_MAX) return {-1};
    
    vector<int>path;
    int node = D;
    while (parent[node]!=node){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(S);
    reverse(path.begin(), path.end());
    return path;
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
    int D;
    cin >> D;

    vector<int> ans = dijkstra(V, adj, S, D );

    for (int i = 0; i < V; i++) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << "\n";

    return 0;
}