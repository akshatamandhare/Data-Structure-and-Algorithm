
#include <bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>>& dist) {
    // Write your logic here
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> dist(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    floydWarshall(dist);

    int q;
    cin >> q;

    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << dist[u][v] << "\n";
    }

    return 0;
}
