#include<bits/stdc++.h>
using namespace std;

bool toposort(vector<vector<int>>&adj, int N){
    queue<int>q;
    vector<int>indegree(N, 0);
    for(int i=0; i<N; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    for(int i=0; i<indegree.size(); i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    int cnt=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cnt++;
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    if(cnt==N) return true;
    else return false;
}

int main(){
    int N, M;
    cin>>N>>M;
    vector<vector<int>>adj(N);
    int u,v;
    for(int i=0; i<M; i++){
        cin>>u>>v;
        
        // reverse u -> v into v -> u
        adj[v].push_back(u);
    }

    if(toposort(adj, N)){
        cout<<"Yes";
    }else{
        cout<<"No";
    }

    return 0;
}