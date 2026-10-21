
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

    bool isRoot(int node) {
        return findUPar(node) == node;
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

int makeConnected(int n, vector<vector<int>>& connections) {
    // Write your logic here
    DisjointSet ds(n);

    int countextra=0;
    for(auto it : connections){
        int u=it[0];
        int v=it[1];
        if(ds.findUPar(u)==ds.findUPar(v)) countextra++;
        else ds.unionBySize(u, v);
    }

    int countC=0;
    for(int i=0; i<n; i++){
        if(ds.isRoot(i)){
            countC++;
        }
    }

    int ans=countC-1;
    if(countextra>=ans) return ans;
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> connections(m, vector<int>(2));

    for (int i = 0; i < m; i++) {
        cin >> connections[i][0] >> connections[i][1];
    }

    cout << makeConnected(n, connections) << "\n";
    return 0;
}
