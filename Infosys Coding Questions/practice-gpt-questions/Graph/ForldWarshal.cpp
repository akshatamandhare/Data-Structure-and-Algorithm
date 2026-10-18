
#include <bits/stdc++.h>
using namespace std;

void shortestDistance(vector<vector<int>>& matrix) {
    // Write your logic here
    int n = matrix.size();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j]==-1){
                matrix[i][j]=INT_MAX;
            }
        }
    }

    for(int via=0; via<n; via++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][via]!= INT_MAX && matrix[via][j]!=INT_MAX) {
                    matrix[i][j]=min(matrix[i][j], matrix[i][via]+matrix[via][j]);
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j]==INT_MAX){
                matrix[i][j]=-1;
            }
        }
    }

    return;
}

int main() {
    int V;
    cin >> V;

    vector<vector<int>> matrix(V, vector<int>(V));

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> matrix[i][j];
        }
    }

    shortestDistance(matrix);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (j > 0) cout << " ";
            cout << matrix[i][j];
        }
        cout << "\n";
    }

    return 0;
}
