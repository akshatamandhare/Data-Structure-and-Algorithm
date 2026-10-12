
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>&vis, vector<vector<int>>&adjlist){
    vis[node]=1;

    for(auto it: adjlist[node]){
        if(!vis[it]){
            dfs(it, vis, adjlist);
        }
    }
}

int numProvinces(vector<vector<int>>& isConnected, int V) {
    // Write your logic here
    vector<int> vis(V, 0);
    int count=0;
    vector<vector<int>>adjlist(V);

    for(int i=0; i<V; i++){
        for (int j=0; j<V; j++){
            if(isConnected[i][j]==1 && i!=j){
                adjlist[i].push_back(j);
            }
        }
    }

    for(int i=0; i<V; i++){
        if(!vis[i]){
            count++;
            dfs(i , vis, adjlist );
        }
    }
    return count;
}

int main() {
    int V;
    cin >> V;

    vector<vector<int>> isConnected(V, vector<int>(V));

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> isConnected[i][j];
        }
    }

    cout << numProvinces(isConnected, V) << "\n";
    return 0;
}
