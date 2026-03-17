// Maximum Product of Three Numbers

#include <bits/stdc++.h>
using namespace std;

int maximumProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int product1 = nums[n-1] * nums[n-2] * nums[n-3];
    int product2 = nums[0] * nums[1] * nums[n-1];
    return max(product1, product2);
}

int main(){
    vector<int> nums = {1, 2, 3, 4};
    cout << maximumProduct(nums) << endl; // Output: 24
    return 0;
}