#include <bits/stdc++.h>
using namespace std;

void topo(int node, vector<vector<pair<int, int>>>& adj, 
    vector<int>&vis, stack<int>&st
){
    vis[node]=1;

    for(auto it: adj[node]){
        int adjnode=it.first;
        if(!vis[adjnode]){
            topo(adjnode, adj, vis, st);
        }
    }
    st.push(node);
}

vector<int> shortestPath(
    int V,
    vector<vector<pair<int, int>>>& adj,
    int S
) {
    // Write your logic here
    vector<int>vis(V, 0);
    vector<int>dist(V, INT_MAX);
    stack<int>st;
    dist[S]=0;


    for(int i=0; i<V; i++){
        if(!vis[i]){
            topo(i, adj, vis, st);
        }
    }

    while(!st.empty()){
        int node = st.top();
        st.pop();
        for(auto it: adj[node]){
            int v = it.first;
            int wt = it.second;

            if(dist[node]!=INT_MAX && dist[node]+wt<dist[v]){
                dist[v]=wt+dist[node];
            }
        }
    }


    for(int i=0; i<V; i++){
        if(dist[i]==INT_MAX){
            dist[i]=-1;
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