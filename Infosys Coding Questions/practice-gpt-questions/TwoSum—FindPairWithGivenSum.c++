#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& arr, int k) {
    // Write your logic here
    int n=arr.size();
    int left=0;
    int right=n-1;
    int sum=0;
    int left_value = 0, right_value =0;
    vector<pair<int, int>> nums;
    // Store value and original index
    for (int i = 0; i < n; i++) {
        nums.push_back({arr[i], i});
    }

    sort(nums.begin(), nums.end());

    while (right<n && left < right)
    {
        int sum = nums[left].first + nums[right].first;

        if (sum == k) {
            return {nums[left].second, nums[right].second};
        }
        else if (sum>k){
            right--;
        }
        else if(sum<k){
            left++;
        }
    }
    return {-1, -1};
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