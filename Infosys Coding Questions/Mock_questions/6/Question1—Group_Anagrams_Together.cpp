#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (auto str : strs) {
            string key = str;
            sort(key.begin(), key.end());

            mp[key].push_back(str);
        }

        vector<vector<string>> ans;

        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
}

int main(){
    int n;
    cin >> n;

    vector<string> str(n);

    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    vector<vector<string>> ans = groupAnagrams(str);

    for (auto group : ans) {
        for (auto word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;

    
}