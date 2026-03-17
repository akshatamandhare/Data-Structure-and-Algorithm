// Longest Subarray with Sum K

#include<bits/stdc++.h>
using namespace std;

int getlargestsubarr(vector<int>& arr, int k){
    map<int, int>prefixsummap;
    int result=0;
    int prefixsum=0;

    for(int i=0; i<arr.size(); i++){
        prefixsum+=arr[i];

        if(prefixsummap.find(prefixsum-k) != prefixsummap.end()){
            result=max(result, i- prefixsummap[prefixsum-k]);
        }

        if(prefixsummap.find(prefixsum) == prefixsummap.end()){
            prefixsummap[prefixsum]=i;
        }
        if(prefixsum == k)
            result = max(result, i + 1);
    }
    
    return result;
}

int main(){

    vector<int> arr;
    string line;
    cout<<"Enter array: ";
    getline(cin, line);

    line.erase(remove(line.begin(), line.end(), '['), line.end());
    line.erase(remove(line.begin(), line.end(), ']'), line.end());

    stringstream ss(line);
    string token;
    while(getline( ss, token, ',')){
        arr.push_back(stoi(token));
    }
    // for(int it: arr){
    //     cout<<it<<" ";
    // }
    // cout<<endl;

    int k;
    cout<<"Enter k: ";
    cin>>k;

    int result= getlargestsubarr(arr, k);
    cout<<result;
    return 0;
}

