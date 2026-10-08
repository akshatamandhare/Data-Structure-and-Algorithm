#include<bits/stdc++.h>
using namespace std;

vector<int> findPath(int V, vector<vector<pair<int, int>>>&adj, 
    int src, int dest){
    vector<int>parent(V, INT_MAX);

    for(int i=0; i<V; i++){
        parent[i]=i;
    }

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    >pq;

    pq.push({0, src});
    vector<int>dist(V, INT_MAX);
    dist[src]=0;

    while (!pq.empty())
    {
        auto it=pq.top();
        int dis=it.first;
        int node=it.second;
        pq.pop();

        if(dis>dist[node]) continue;

        for(auto it:adj[node]){
            int adjnode=it.first;
            int adjwt=it.second;

            if(dis+adjwt<dist[adjnode]){
                dist[adjnode]=dis+adjwt;
                parent[adjnode]=node;
                pq.push({dist[adjnode], adjnode});
            }
        }
    }

    if(dist[dest]==INT_MAX) return {-1};

    vector<int> path;
    int node=dest;
    while(node != src){
        path.push_back(node);
        node = parent[node];
    }
    path.push_back(src);
    reverse(path.begin(), path.end());
    return path;
}

int main(){
    int V, E;
    cin>>V>>E;

    vector<vector<pair<int, int>>> adj(V);
    int u, v, w;
    for(int i=0; i<E; i++){
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // print graph
    for (int u = 0; u < V; u++) {
        cout << u << " -> ";

        for (auto it : adj[u]) {
            cout << "(" << it.first << ", " << it.second << ") ";
        }

        cout << endl;
    }

    int src, dest;
    cin >> src >> dest;

    vector<int>result = findPath(V, adj, src, dest);
    cout<<"shortest path: "; 
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}