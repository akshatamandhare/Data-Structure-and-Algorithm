//A data scientist has an array of N integers.She wants to create a new array where each element at index i equals the product of all elements in the original array EXCEPT the one at index i.She cannot use division, and must solve it in O(n) time.Constraints : 2 ≤ N ≤ 10 ^ 5 - 30 ≤ arr[i] ≤ 30 Array may contain zeros Input Format : Line 1 → Integer N Line 2 → N space - separated integers Output Format : N space - separated integers(product array)

#include<iostream>
#include<vector>
using namespace std;


int main(){
    int n;
    cout<<"Enter N: ";
    cin>>n;

    int arr[n];
    cout<<"Enter elements: "<<endl;
    for(int i=0; i<n; i++) cin>>arr[i];

    vector<int> result(n);
    vector<int> prefixsum(n);
    vector<int> sufixsum(n);

    prefixsum[0]=1;
    for(int i=1; i<n; i++)
    {
        prefixsum[i]=arr[i-1]*prefixsum[i-1];
    }

    sufixsum[n-1] = 1;
    for (int j = n-2; j >=0; j--)
    {
        sufixsum[j] = arr[j + 1] * sufixsum[j + 1];
    }

    for(int i=0; i<n; i++){
        result[i]=prefixsum[i]*sufixsum[i];
        cout<<result[i]<<" ";
    }

}