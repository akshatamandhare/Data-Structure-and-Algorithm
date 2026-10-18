
#include <bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int>& arr, int start, int end) {
    // Write your logic here
    // priority_queue<
    //     pair<int, int>,
    //     vector<int, int>,
    //     greater<vector<int, int>>
    // >pq;

    queue<pair<int, int>>q;
    vector<int>dist(100000, INT_MAX);
    dist[start]=0;
    // {node, dist}
    q.push({start, 0});

    while (!q.empty())
    {
        int steps = q.front().second;
        int node = q.front().first;

        q.pop();

        if(node==end) return steps;

        for(auto it: arr){
            int num = (it*node)%100000;
            if(steps+1<dist[num]){
                dist[num]=steps+1;
                q.push({num, steps+1});
            }
        }

    }
    
    return -1;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int start, end;
    cin >> start >> end;

    cout << minimumMultiplications(arr, start, end) << "\n";

    return 0;
}
