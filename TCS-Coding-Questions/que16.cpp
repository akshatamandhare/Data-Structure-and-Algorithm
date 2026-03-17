// A person has many shoes of different sizes and wants to arrange them into pairs.
// A pair consists of one left shoe (L) and one right shoe (R) of the same size.

// Input:
// N = 8
// Shoes:
// 7L 7R 7L 8L 6R 7R 8R 6R

// Output: 3

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore();


    string Shoes;
    getline(cin, Shoes);

    stringstream ss(Shoes);
    vector<string> shoe;
    string token;

    while(ss >> token){
        shoe.push_back(token);
    }

    map<int, int> leftCount;
    map<int, int> rightCount;

    for(string s:shoe){
        int size = stoi(s.substr(0, s.size() - 1));
        char type = s.back();

        if(type == 'L')
            leftCount[size]++;
        else
            rightCount[size]++;
    }
    
    int pairs = 0;

    for(auto it: leftCount){
        int size = it.first;
        pairs += min(leftCount[size], rightCount[size]);
    }

    cout << pairs << endl;
    return 0;
}