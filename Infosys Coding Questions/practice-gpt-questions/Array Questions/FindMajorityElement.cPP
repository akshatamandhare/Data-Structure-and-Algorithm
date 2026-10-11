#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& arr) {
    // Write your logic here
    int n=arr.size();
    map<int, int>freq;

    for(int i=0; i<n; i++){
        freq[arr[i]]++;
    }

    int max_occurance = 0;
    int max_occurance_ele = 0;

    
    for(auto it: freq){
        int element = it.first;
        int freq_element = it.second;

        if(freq_element > max_occurance && freq_element>n/2){
            max_occurance_ele=element;
            max_occurance = freq_element;
        }
    }
    return max_occurance_ele;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << majorityElement(arr);

    return 0;
}