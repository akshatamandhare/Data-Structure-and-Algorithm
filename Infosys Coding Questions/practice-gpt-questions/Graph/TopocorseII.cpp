#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int V, vector<vector<int>>& adj) {
    // Write your logic here]
    vector<int>indegree(V);
    queue<int>q;

    for(int i=0; i<V; i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }

    for(int i=0; i<V; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int>topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    if (topo.size() != V) return {};
    return topo;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> ans = findOrder(V, adj);

    if (ans.empty() && V > 0) {
        cout << -1 << "\n";
    } else {
        for (int i = 0; i < (int)ans.size(); i++) {
            if (i > 0) cout << " ";
            cout << ans[i];
        }
        cout << "\n";
    }

    return 0;
}