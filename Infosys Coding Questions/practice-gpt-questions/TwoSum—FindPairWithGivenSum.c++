#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& arr, int k) {
    // Write your logic here
    int n=arr.size();
    int i =0;
    int j=1;
    int sum=0;
    vector<int>ans;

    while (j<n)
    {
        sum=arr[i]+arr[j];
        if(sum>k){
            sum-=arr[i];
            i++;
        }
        if(sum==k){
            ans.push_back(i);
            ans.push_back(j);
        }
        j++;
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> k;

    vector<int> ans = twoSum(arr, k);

    cout << ans[0] << " " << ans[1];

    return 0;
}