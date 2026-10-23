
#include <bits/stdc++.h>
using namespace std;

vector<int> kthLargestStream(vector<int>& arr, int k) {
    // Your logic here
    int n=arr.size();
    priority_queue<
        int, 
        vector<int>,
        greater<int>
    >pq;
    vector<int> ans;

    for(int i=0; i<n; i++){
        pq.push(arr[i]);
        if(pq.size()>k){
            pq.pop();
            // ans.push_back(pq.top());
        }
        if(pq.size()<k){
            ans.push_back(-1);
        }
        else {
            ans.push_back(pq.top());
        }
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> ans = kthLargestStream(arr, k);

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << "\n";

    return 0;
}
