
#include <bits/stdc++.h>
using namespace std;

int primMST(int V, vector<vector<int>>& edges) {
    // Write your logic here
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;
    vector<vector<pair<int, int>>> adj(V);
    for(auto it: edges){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    vector<int>vis(V, 0);
    pq.push({0, 0});

    int sum=0;
    while (!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second;

        pq.pop();
        if(vis[node]==1) continue;
        vis[node]=1;
        sum+=wt;

        for(auto it : adj[node]){
            int adjnode = it.first;
            int edgewt = it.second;

            if(!vis[adjnode]){
                pq.push({edgewt, adjnode});
            }
        }
    }
    return sum;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));

    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    cout << primMST(V, edges) << "\n";

    return 0;
}
