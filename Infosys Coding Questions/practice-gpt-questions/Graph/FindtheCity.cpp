
#include <bits/stdc++.h>
using namespace std;

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    // Write your logic here
    vector<vector<int>>dist(n, vector<int>(n, INT_MAX));

    for(auto it : edges){
        dist[it[0]][it[1]]=it[2];
        dist[it[1]][it[0]]=it[2];
    }

    for(int i=0; i<n; i++){
        dist[i][i]=0;
    }

    //forld warshel algo
    for(int via=0; via<n; via++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(dist[i][via]==INT_MAX || dist[via][j]==INT_MAX) {continue;};
                dist[i][j]=min(dist[i][via]+dist[via][j], dist[i][j]);
            }
        }
    }

    int cnt=0;
    int citycount=n;
    int cityNo=-1;

    for(int city=0; city<n; city++){
        cnt=0;
        for(int adjcity=0; adjcity<n; adjcity++){
            if(dist[city][adjcity]<=distanceThreshold && adjcity != city){
                cnt++;
            }
        }

        if(cnt<=citycount){
            citycount=cnt;
            cityNo=city;
        }
    }
    return cityNo;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(3));

    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int distanceThreshold;
    cin >> distanceThreshold;

    cout << findTheCity(n, edges, distanceThreshold) << "\n";

    return 0;
}
