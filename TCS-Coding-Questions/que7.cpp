// One programming language has the following keywords that cannot be used as 
// identifiers: 
// break, case, continue, default, defer, else, for, func, goto, if, map, range, return, 
// struct, type, var 
// Write a program to find if the given word is a keyword or not 
// Input #1:
// defer
//     Output : defer is a keyword

#include<iostream>
             using namespace std;
int main(){
    string keywords[1][16] = {"break", "case", "continue", "default", "defer", "else", "for", "func", "goto", "if", "map", "range", "return", "struct", "type", "var"};
    string input;
    cout<<"Enter a string: ";
    cin>>input;
    int flag=0;
    for(int i=0; i<16; i++){
        if(input==keywords[0][i]){
            flag=1;
            break;
        }
    }    
    if(flag==1){
        cout<<"Input string is a keyword";
    }
    else{
        cout << "Input string is not a keyword";
    }
    return 0;
}
