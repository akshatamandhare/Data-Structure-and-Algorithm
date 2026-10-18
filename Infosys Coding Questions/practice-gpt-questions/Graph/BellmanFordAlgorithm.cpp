#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int S) {
    // Write your logic here
    vector<int>dist(V, INT_MAX);
    dist[S]=0;
    //realx n-1 vertex
    for(int i=0; i<V-1; i++){
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u]!=INT_MAX && dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
            }
        }
    }

    // Detect a reachable negative-weight cycle
    for(auto it:edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        if(dist[u]!=INT_MAX && dist[u]+wt<dist[v]){
            return {};
        }
    }

     // Mark unreachable vertices as -1
    for(int i=0; i<V; i++){
        if(dist[i]==INT_MAX) dist[i]=-1;
    }

    return dist;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    int S;
    cin >> S;

    vector<int> ans = bellmanFord(V, edges, S);

    if (ans.empty()) {
        std::cout << -1 << "\n";
    } else {
        for (int i = 0; i < (int)ans.size(); i++) {
            if (i > 0) std::cout << " ";
            std::cout << ans[i];
        }
        std::cout << "\n";
    }

    return 0;
}