
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findUPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int findCircleNum(vector<vector<int>>& isConnected) {
    // Write your logic here
    int V=isConnected.size();
    DisjointSet ds(V);
    int cnt=0;

    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(isConnected[i][j]==1){
                ds.unionBySize(i, j);
            }
        }
    }
    for(int i=0; i<V; i++){
        if(ds.findUPar(i)==i) cnt++;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> isConnected(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> isConnected[i][j];
        }
    }

    cout << findCircleNum(isConnected) << "\n";
    return 0;
}
