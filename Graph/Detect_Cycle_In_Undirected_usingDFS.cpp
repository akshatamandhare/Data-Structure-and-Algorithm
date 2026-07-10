#include<bits/stdc++.h>
#include<vector>
using namespace std;

bool dfs(int node, int parent,  vector<int> adj[], vector<int>& vis){
    vis[node]=1;
    for(auto adjacentnode: adj[node]){
        if(!vis[adjacentnode]){
            if(dfs(adjacentnode, node, adj, vis)==true) return true;
        }
        else if(parent!=adjacentnode) return true;
    }
    return false;
}

bool iscycle(int v, vector<int> adj[]){
    vector<int> vis(v,0);
    for(int i=0; i<v-1; i++){
        if(!vis[i]){
            vis[i]=1;
            if(dfs(i,-1, adj, vis)==true){
                return true;
            }
        }
    }
    return false;
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

    bool ans =  iscycle(n, adj);
    cout<<"Cycle or NOt : "<<ans;
    return 0;

}