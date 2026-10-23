
#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
    // Write your logic here
    int n=nums.size();

    int prev2=0, prev1=nums[0], curr ;
    
    for(int i=1; i<n; i++){
        int take = prev2+nums[i];
        int not_take = prev1;
        curr=max(take, not_take);
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if(n==1) return nums[0];

    vector<int> temp1, temp2;

    for(int i=0; i<n; i++){
        if(i!=n-1){
            temp1.push_back(nums[i]);
        }
        if(i!=0){
            temp2.push_back(nums[i]);
        }
    }

    cout<<max(rob(temp1), rob(temp2));

    // cout << rob(nums) << "\n";

    return 0;
}
