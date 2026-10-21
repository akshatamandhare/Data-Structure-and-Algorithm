
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        // Write your logic here
        if(node == parent[node]){
            return node ;
        }
        return parent[node]=findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        // Write your logic here
        int ultp_u = findUPar(u);
        int ultp_v = findUPar(v);

        if(ultp_u == ultp_v) return;

        if(size[ultp_u]<size[ultp_v]){
            parent[ultp_u]=ultp_v;
            size[ultp_v]+=size[ultp_u];
        }
        else{
            parent[ultp_v]=ultp_u;
            size[ultp_u]+=size[ultp_v];
        }
    }

    bool sameSet(int u, int v) {
        // Write your logic here
        if(findUPar(u)==findUPar(v)) return true;
        else{
            return false;
        }
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    DisjointSet ds(n);

    while (q--) {
        int type, u, v;
        cin >> type >> u >> v;

        if (type == 1) {
            ds.unionBySize(u, v);
        } else {
            cout << (ds.sameSet(u, v) ? "YES" : "NO") << "\n";
        }
    }

    return 0;
}
