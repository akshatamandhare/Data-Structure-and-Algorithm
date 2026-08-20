#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    int n=s.length();
    
    unordered_map<char, int> mpp;
    for(auto x:s){
        mpp[x]++;
    }

    vector<pair<char, int>>v;
    for(auto it: mpp){
        v.push_back({it.first, it.second});
    }
    sort(v.begin(), v.end(), [](auto &a, auto &b){
        return a.second > b.second;
    });
    for(auto it: v){
        for(int i=0; i<it.second; i++){
            cout<<it.first;
        }
    }
    return 0;
}