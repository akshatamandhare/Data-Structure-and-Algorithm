#include<bits/stdc++.h>
using namespace std;

vector<int> findNSE(vector<int>&arr){
    int n=arr.size();
    stack<int> st;
    vector<int>nse(n);
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        nse[i]=st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
}

vector<int> findPSE(vector<int>&arr){
    int n=arr.size();
    stack<int>st;
    vector<int>pse(n);
    for(int i=0; i<n; i++){
        while (!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        pse[i]=st.empty()?-1:st.top();
        st.push(i);
    }
    return pse;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    // vector<int>nse = findNSE(arr);
    // vector<int>pse = findPSE(arr);
    // int maxi=0;
    // for(int i=0; i<n-1; i++){
    //     maxi=max(maxi, arr[i]*(nse[i]-pse[i]-1));
    // }

    stack<int>st;
    int maxarea=0;

    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            int element=st.top();
            st.pop();
            int nse=i;
            int pse=st.empty()?-1:st.top();
            maxarea=max(arr[element]*(nse-pse-1), maxarea);
        }

        st.push(i);
    }

    //remaining in st;
    while (!st.empty())
    {
        int nse=n;
        int element=st.top();
        st.pop();
        int pse=st.empty()?-1:st.top();
        maxarea=max(arr[element]*(nse-pse-1), maxarea);
    }
    

    cout<<"Maximum Area: "<<maxarea;
    return 0;

}