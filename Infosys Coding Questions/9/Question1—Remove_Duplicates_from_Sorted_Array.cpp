#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int>arr(N);
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }

    vector<int>result;

    for(int i=0; i<N; i++){
        if(arr[i-1] != arr[i]){
            result.push_back(arr[i]);
        }
    }
    cout<<"K:"<<result.size();
    cout<<endl;
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}
