// A cybersecurity analyst is performing a frequency analysis attack on an encrypted message.The
//    encryption substitutes each letter with another
//     letter(a simple substitution cipher)
//         .The analyst
//     knows that in the original plaintext,
//     the most frequent letter is always 'e', the second most frequent is 't', and the third is 'a'.Given the ciphertext, decode it by : Finding the 3 most frequent letters in ciphertext Mapping the most frequent → 'e', second → 't', third → 'a' Replacing only these 3 letters in the ciphertext(others remain unchanged) Print the partially decoded text Constraints : 1 ≤ len(ciphertext) ≤ 10 ^ 5 Ciphertext contains only lowercase letters and spaces Spaces are not encrypted Input Format : Single line → Ciphertext string Output Format : First line → "Mapping: X→e Y→t Z→a"(X, Y, Z are cipher letters)Second line → Partially decoded text

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    string s;
    cout << "Enter String: ";
    getline(cin, s);
    vector<pair<int, char>>vec;

    int freq[26]={0};
    for(int i=0; i<s.size(); i++){
        if(s[i]!=' '){
            freq[s[i]-'a']++;
        }
    }
    for(int i=0; i<26; i++){
        if(freq[i]>0){
            vec.push_back({freq[i], char(i + 'a')});
        }
    }

    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());

    char first = 0, second = 0, third = 0;
    if(vec.size() > 0) first = vec[0].second;
    if(vec.size() > 1) second = vec[1].second;  
    if(vec.size() > 2) third = vec[2].second;

    cout<<"Mappig: ";
    if(first) cout<<first<<"->e ";
    if(second) cout<<second<<"->t ";        
    if(third) cout<<third<<"->a ";
    cout<<endl;

    for(int i=0; i<s.size(); i++){
        if(s[i]==first) cout<<"e";
        else if(s[i]==second) cout<<"t";
        else if(s[i]==third) cout<<"a";
        else cout<<s[i];
    }
}