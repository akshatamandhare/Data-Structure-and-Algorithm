// Question :Cryptic Number

//                  Problem Statement : You are given two integers L and R representing a range of
//                                      numbers(inclusive)
//                                          .A number is called a Cryptic Number if it satisfies ALL of the following :

//     It is divisible by 7.

//     It is NOT divisible by 5.

//     It is NOT a palindrome.

//     It does NOT contain any repetitive digits.

//     Print all Cryptic Numbers in the given range.If no such number exists,
//     print - 1.

#include<iostream>
#include <set>
using namespace std;
bool ispalindrom(int n){
    int rev=0, rem=0;
    int num=n;
    while(n>0){
        rem = n % 10;
        rev=rev*10+rem;
        n=n/10;
    }
    return num==rev;
}

int getnoofdigits(int n){
    int ans=0;
    while(n>0){
        ans++;
        n/=10;
    }
    return ans;
}

bool isrepeat(int n)
{
    set<int> st;
    int digits=getnoofdigits(n);
    while(n>0){
        st.insert(n%10);
        n=n/10;
    }
    return st.size()==digits;
}

int main()
{
    int t;
    cin>>t;

    while(t--){
        int l, r;
        bool found = false;
        cin>>l>>r;
        for(int i=l; i<=r; i++){
            if(i%7==0 && i%5!=0 && ispalindrom(i)==false && isrepeat(i)==true){
                cout<<i<<" ";
                found=true;
            }
        }
        if(!found){
            cout<<-1;
        }
    }
}