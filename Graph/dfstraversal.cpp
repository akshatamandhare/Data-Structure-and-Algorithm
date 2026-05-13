#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ls){
    vis[node] = 1;
    ls.push_back(node);

    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, ls);
        }
    }
}
vector<int> dfsOfGraph(int n, vector<int> adj[]){
    vector<int> vis(n + 1, 0);
    vector<int> ls;
    int start = 1;
    dfs(start, adj, vis, ls);
    return ls;
}



int main(){
    int n,m;
    cout<<"Enter No of Nodes and Edges: ";
    cin>>n>>m;

    vector<int>adj[n+1];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    vector<int>ans =  dfsOfGraph(n, adj);
    cout<<"DFS traversal: ";
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;

}