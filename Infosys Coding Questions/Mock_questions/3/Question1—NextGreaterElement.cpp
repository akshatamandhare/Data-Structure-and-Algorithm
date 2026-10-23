
#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr, int n) {
    // Write your code here
    vector<int>ans;

    for(int i=0; i<n; i++){
        int neg=-1;
        for(int j=i+1; j<n; j++){
            if(arr[j]>arr[i]){
                neg = arr[j];
                break;
            }
        }
        ans.push_back(neg);
    }
    return ans;

}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> ans = nextGreaterElement(arr, n);

    for (int i = 0; i < n; i++) {
        cout << ans[i];
        if (i < n - 1) cout << " ";
    }

    cout << endl;

    return 0;
}
