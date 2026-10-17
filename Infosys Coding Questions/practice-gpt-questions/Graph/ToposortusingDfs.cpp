#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>&adj, vector<int>&vis, stack<int>&st){
    vis[node]=1;

    
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, st);
        }
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<vector<int>>& adj) {
    // Write your logic here
    vector<int>vis(V);
    stack<int> st;
    for (int i=0; i<V; i++){
        if(!vis[i]){
            dfs(i, adj, vis, st);
        }
    }

    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
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

    vector<int> ans = topoSort(V, adj);

    for (int i = 0; i < (int)ans.size(); i++) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << "\n";

    return 0;
}