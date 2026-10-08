#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin>>N>>M;

    int u, v, wt;
    vector<vector<long long>> dist(N + 1, vector<long long>(N + 1, LLONG_MAX));

    
    for (int i = 1; i <= N; i++) {
        dist[i][i] = 0;
    }

    // Take input
    for (int i = 0; i < M; i++) {
        int u, v;
        long long wt;
        cin >> u >> v >> wt;

        // u--;
        // v--;

        dist[u][v] = min(dist[u][v], wt);
    }
    
    //calculate dist via each node k
    //foldwarshal algo
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if (dist[i][k] == LLONG_MAX || dist[k][j] == LLONG_MAX)
                    continue;
                dist[i][j]=min(dist[i][k] + dist[k][j], dist[i][j]);
            }
        }
    }

    //if dist goes negative then cycle presssent
    for(int i=1; i<=N; i++){
        if(dist[i][i]<0){ 
            cout<<"Negative Cycle";
            return 0;
        }
    }

    // Print result
    cout<<"Output; "<<endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++){
            if (dist[i][j] == LLONG_MAX)
                cout << -1;
            else
                cout << dist[i][j];

            if (j != N)
                cout << " ";
        }
        cout << "\n";
    }
    return 0;
}


