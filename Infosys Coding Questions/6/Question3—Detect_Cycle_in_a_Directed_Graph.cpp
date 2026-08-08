#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    int u,v;
    vector<vector<int>> adj(n);
    
    for(int i=0; i<m; i++){
        cin>>u>>v;
        adj[u].push_back(v);
    }

    //indegree arr
    vector<int> indegree(n, 0);
    for(int i=0; i<n; i++){
        for(auto it :adj[i]){
            indegree[it]++;
        }
    }

    //if indegree 0 then push into queue;
    queue<int>q;
    for(int i=0; i<n; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    int cnt=0;
    vector<int>topo;
    while (!q.empty()){
        int node=q.front();
        q.pop();
        cnt++;
        topo.push_back(node);
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }

    if(cnt == n) cout << "No";   // no cycle
    else cout << "Yes";          // cycle exists
    return 0;
    
}