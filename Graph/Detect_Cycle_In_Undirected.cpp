#include<bits/stdc++.h>
using namespace std;


bool detect(int src, vector<int> adj[], vector<int> &vis){
    vis[src]=1;
    queue<pair<int, int>>q;
    q.push({src, -1});
    while (!q.empty())
    {
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();

        for(auto adjacentnode : adj[node]){
            if(!vis[adjacentnode]){
                vis[adjacentnode]=1;
                q.push({adjacentnode, node});
            }
            else if(parent != adjacentnode){
                return true;                
            }
        }
    }
    return false;

}
bool iscycle(int v, vector<int>adj[]){
    vector<int> vis(v,0);
    for(int i=0; i<v-1; i++){
        if(!vis[i]){
            vis[i]=1;
            if(detect(i, adj, vis)==true){
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