// Given a list of strings representing different words, remove duplicates and print the unique words in ascending and descending order.
// Input should be taken from the user.

// Example Input:
// Watermelon, Apple, Orange, Banana, Brange, Lemon, Apple


#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cout<<"Enter inputs: ";
    getline(cin, s);
    stringstream ss(s);
    vector<string>arr;

    string token;
    set<string>st;
    while( getline(ss, token, ',')){
        st.insert(token);
    }

    vector<string>v;
    for(auto it: st){
        v.push_back(it);
    }
    sort(v.begin(), v.end());
    //Accessing order
    cout<<"Ascending Order: ";
    for(int i=0; i<st.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    //decending order
    cout<<"Descending Order: ";
    reverse(v.begin(), v.end());
    for(int i=0; i<st.size(); i++){
        cout<<v[i]<<" ";
    }
    return 0;




}