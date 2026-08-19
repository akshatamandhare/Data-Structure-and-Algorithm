#include<bits/stdc++.h>
using namespace std;

vector<int> calculateDist(vector<vector<int>>&edges, int src, int n){
    vector<int>dist(n, INT_MAX);
    dist[src]=0;
    for(auto it: edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];
        if(dist[u]+wt<dist[v] && dist[u]!=INT_MAX){
            dist[v]=dist[u]+wt;
        }
    }

    //nth relaxitation to check negative cycle 
    for(auto it : edges){
        int u=it[0];
        int v=it[1];
        int wt=it[2];

        if( dist[u]!=INT_MAX  && dist[u]+wt < dist[v])
            return {-1};
    }
    return dist;
}

int main(){
    int n, m;
    cin>>n>>m;

    int u, v, wt;
    vector<vector<int>> edges;
    for(int i=0; i<n; i++){
        cin>>u>>v>>wt;
        edges.push_back({u, v, wt});
    }
    int src=0;

    vector<int>dist = calculateDist(edges, src, n);
    if (dist.size() == 1 && dist[0] == -1) {
        cout << "Negative cycle detected";
    }
    else {
        for (int i = 0; i < n; i++) {
            cout << dist[i] << " ";
        }
    }

    return 0;
}