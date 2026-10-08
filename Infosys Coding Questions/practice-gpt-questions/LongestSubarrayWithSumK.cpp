#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& arr, int k) {
    // Write your logic here
    int maxlen=0;
    int left=0, right=1;
    int sum=arr[0];
    int n=arr.size();
    while (right<n)
    {
        sum+=arr[right];
        while(sum>k){
            sum-=arr[left];
            left++;
        }
        maxlen=max(maxlen, right-left+1);
        right++;
    }
    cout<<"element of subarrar: ";
    for(int i=left; i<right; i++){
        cout<<arr[i]<<" /n";
    }
    return maxlen;
}

int main() {
    int n, k;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> k;

    cout << longestSubarray(arr, k);

    return 0;
}