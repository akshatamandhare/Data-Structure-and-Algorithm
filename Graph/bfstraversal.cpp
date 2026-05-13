#include<bits/stdc++.h>
using namespace std;

vector<int> bgfoggraph(int n, vector<int>adj[]){
    // int vis[n]={0};
    vector<int> vis(n+1,0);
    vis[1]=1;
    queue<int> q;
    q.push(1);
    vector<int> bfs;

    while (!q.empty())
    {
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }   
        }
    }
    return bfs;
    
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

    vector<int>ans =  bgfoggraph(n, adj);
    cout<<"BFS traversal: ";
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;

}