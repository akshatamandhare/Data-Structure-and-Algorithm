// A person has many shoes of different sizes and wants to arrange them into pairs.
// A pair consists of one left shoe (L) and one right shoe (R) of the same size.

// Input
// N = 8
// Shoes:
// 7L 7R 7L 8L 6R 7R 8R 6R

// Output: 3

#include<bits/stdc++.h>
using namespace std;

int main(){
    // int n;
    // cout<<"Enter N: ";
    // cin>>n;

    string shoes;
    cout<<"Enter Shoes: ";
    getline(cin, shoes);

    stringstream ss(shoes);
    string token;
    vector<string> arr;

    unordered_map<int, int> leftshoes;
    unordered_map<int, int> rightshoes;

   

    while(ss >> token){
        int size=stoi(token.substr(0, token.length()-1));
        char side=token.back();

        if(side=='L'){
            leftshoes[size]++;
        }
        else{
            rightshoes[size]++;
        }
    }

    int pairs =0;
    for(auto it: leftshoes){
        int size=it.first;
        pairs+=min(leftshoes[size], rightshoes[size]);
    }
    cout<<pairs;
}