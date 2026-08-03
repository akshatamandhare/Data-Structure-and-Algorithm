#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter No. of Stalls and Generators: ";
    int n, m;
    cin>>n>>m;

    vector<int> stalls(n, 0);
    vector<int> generators(m, 0);

    cout<<"Enter Stalls and Generators: ";
    for(int i=0; i<n; i++){
        cin >> stalls[i];
    }

    sort(stalls.begin(), stalls.end());
    
    for(int i=0; i<m; i++){
        cin >> generators[i];
    }

    sort(generators.begin(), generators.end());

    int i=0, j=0, cnt=0;
    while (i<n && j<m)
    {
        if(generators[i] >= stalls[i]){
            cnt++;
            i++;
            j++;
            continue;
        }
        j++;
    }
    cout<<"Output: "<<cnt;
}