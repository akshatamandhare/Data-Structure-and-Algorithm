
#include <bits/stdc++.h>
using namespace std;

int frogJump(int ind, vector<int>&heights) {
    // Write your logic here
    if(ind ==0) return 0;

    int left = frogJump(ind-1, heights) + abs(heights[ind]-heights[ind-1]);

    int right = INT_MAX;
    if(ind>1) right = frogJump(ind-2, heights) + abs(heights[ind]-heights[ind-2]);
    return min(left, right);
}

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    cout << frogJump(n-1, heights) << "\n";

    return 0;
}
