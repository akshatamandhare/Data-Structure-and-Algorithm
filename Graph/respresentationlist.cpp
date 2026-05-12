#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cout<<"Enter n vertex and m edges : ";
    cin>>n>> m;

    vector<int>adj[n+1];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(u);
        adj[v].push_back(v);
    }
    return 0;
}