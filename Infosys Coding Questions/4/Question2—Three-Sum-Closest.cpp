#include<bits/stdc++.h>
using namespace std;

int closest3Sum(vector<int> &arr, int target) {
        // code here
        int n=arr.size();
        int sum=0;
        sort(arr.begin(), arr.end());
        int bestSum = arr[0] + arr[1] + arr[2];
        for(int i=0; i<n-2 ;i++){
            int left=i+1, right=n-1;
            while(left<right){
                
                sum = arr[i] + arr[left] + arr[right];

                // Update closest sum
                if (abs(sum - target) < abs(bestSum - target)) {
                    bestSum = sum;
                }
                else if (abs(sum - target) == abs(bestSum - target)) {
                    bestSum = max(bestSum, sum);
                }
                
                if(sum>target) right--;
                if(sum<target) left++;
                if(sum==target) return sum;
            }
        }
        return bestSum;
    }

int main(){
    int n, t;
    cin>>n>>t;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"Output: "<<closest3Sum(arr, t);
}

