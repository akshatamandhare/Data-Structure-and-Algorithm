
#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights,
                      int src, int dst, int k) {
    // Write your logic here
    vector<vector<int>>adj[n];
    for(auto &it: flights){
        int u=it[0];
        int v=it[1];
        int wt=it[2];

        adj[u].push_back({v, wt});
    }

    vector<int>dist(n, INT_MAX);
    queue<pair<int, pair<int, int>>>q;

    dist[src]=0;
    // {stops, {node, cost}}
    q.push({0, {src, 0}});

    while (!q.empty())
    {
        auto it = q.front();
        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        q.pop();

        if(stops>k){continue;};

        for( auto it: adj[node]){
            int adjnode = it[0];
            int edgewt = it[1];

            if(cost+edgewt<dist[adjnode]){
                dist[adjnode]=cost+edgewt;
                q.push({stops+1, {adjnode, dist[adjnode]}});
            }
        }
    }
    if(dist[dst]==INT_MAX) return -1;
    return dist[dst];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> flights(m, vector<int>(3));

    for (int i = 0; i < m; i++) {
        cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
    }

    int src, dst, k;
    cin >> src >> dst >> k;

    cout << findCheapestPrice(n, flights, src, dst, k) << "\n";

    return 0;
}
