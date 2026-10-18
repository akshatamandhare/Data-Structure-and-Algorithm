
#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>>& roads) {
    // Write your logic here
    int MOD=1000000007;
    vector<vector<int>>adj[n];
    vector<int>ways(n, 0);
    vector<int>dist(n, INT_MAX);

    for(auto it: roads){
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    >pq;

    //{dist, node}
    pq.push({0, 0});
    dist[0]=0;
    ways[0]=1;

    while (!pq.empty())
    {
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        for(auto it: adj[node]){
            int adjnode = it[0];
            int edgewt = it[1];

            if(dis+edgewt<dist[adjnode]){
                dist[adjnode]=dis+edgewt;
                pq.push({dist[adjnode], adjnode});
                ways[adjnode]=ways[node];
            }
            else if (dis+edgewt==dist[adjnode]){
                ways[adjnode]=(ways[adjnode]+ways[node])%MOD;
            }
        }
    }
    return ways[n-1];

}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> roads(m, vector<int>(3));

    for (int i = 0; i < m; i++) {
        cin >> roads[i][0] >> roads[i][1] >> roads[i][2];
    }

    cout << countPaths(n, roads) << "\n";

    return 0;
}
