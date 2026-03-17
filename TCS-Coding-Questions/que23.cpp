// find number of subarray having sum k
// may contain negative number's
// I/P => [1, 2, -3, 7, -1]

#include<bits/stdc++.h>
using namespace std;

int getsubarrwithk(vector<int>& arr, int k){
    int count=0;
    int prefixsum=0;
    unordered_map<int, int> prefixsummap;
    prefixsummap[0] = 1;

    for(int i=0; i<arr.size(); i++){
        prefixsum+=arr[i];

        if(prefixsummap.find(prefixsum-k) != prefixsummap.end()){
            count+= prefixsummap[prefixsum - k];
        }
        prefixsummap[prefixsum]++;
        
    }
    return count;
}

int main(){
    string line;
    cout<<"Enter Array: ";
    getline(cin, line);

    line.erase(remove(line.begin(), line.end(), '['),line.end());
    line.erase(remove(line.begin(), line.end(), ']'),line.end());

    vector<int> arr;
    stringstream ss(line);

    string token;
    while(getline(ss, token, ',' )){
        arr.push_back(stoi(token));
    }
    
    int k;
    cout<<"Enter sum: ";
    cin>>k;

    int result=getsubarrwithk(arr, k);
    cout<<"Number of subarrays: "<<result;

    return 0;

}