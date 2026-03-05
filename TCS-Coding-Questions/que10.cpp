// A bioinformatics lab is analyzing DNA sequences(strings of A, C, G, T).A suspicious repeat is defined as any substring of length exactly L that appears more than once in the sequence.Find all such repeated substrings of length L and print them in lexicographic order.If none, print "No Repeat Found ".
// Constraints : 1 ≤ len(DNA) ≤ 10 ^ 5 1 
// ≤ L ≤ len(DNA) / 2 
// Input Format : First line → DNA string 
// Second line → Integer L Output 
// Format : Repeated substrings in lexicographic order, one per line

#include<iostream>
#include<vector>
#include<algorithm>
#include <map>

using namespace std;
int main(){
    string DNA;
    cout<<"Enter DNA string: ";
    getline(cin, DNA);

    int L;
    cout<<"Enter length of substring: ";
    cin>>L;
    vector<string> vec;
    
    //generate substrings and push them into map
    int i=0, j=L;
    string substring;
    map<string, int> mpp;
    for (i = 0; i <= DNA.length() - L; i++){
        substring = DNA.substr(i, L);
        mpp[substring]++;
    }

    // count how many time each substring with freq>=2
    vector<string> result;
    for(auto it: mpp){
        if(it.second>=2){
            result.push_back(it.first);
        }
    }

    //print all of them, if none exist-> print "No repeat found"
    if(!result.empty())
    {
        cout<<"Output: " ;
        for (auto str : result)
        {
            cout << str << " ";
        }
    }
    else{
        cout << "No Repeats Found";
    }

}