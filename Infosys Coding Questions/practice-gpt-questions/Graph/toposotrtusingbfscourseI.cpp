#include <bits/stdc++.h>
using namespace std;

bool canFinish(int V, vector<vector<int>>& adj) {
    // Write your logic here
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
    if(topo.size()==V){
        return true;
    }
    else{
        return false;
    }
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

    cout << (canFinish(V, adj) ? 1 : 0) << "\n";

    return 0;
}