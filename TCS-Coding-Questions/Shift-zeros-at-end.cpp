#include<iostream>
using namespace std;
int main(){
    int arr[10]={1,0,2,0,3,0,4,5,0,6};
    int i=0;
    for(int j=0; j<10; j++){
        if(arr[j]!=0){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    for(int i=0; i<10; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}