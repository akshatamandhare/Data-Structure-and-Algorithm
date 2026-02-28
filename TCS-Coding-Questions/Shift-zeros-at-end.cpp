
// A chocolate factory is packing chocolates into the packets.The chocolate packets here represent
//     an array of N number of integer values.The task is to find the empty packets(0) of chocolate and push it to the end of the conveyor belt(array)
//         .Example 1 :

//     N = 8 and arr = [ 4, 5, 0, 1, 9, 0, 5, 0 ].

//                     There are 3 empty packets in the given set.These 3 empty packets represented as O should be
//                     pushed towards the end of the array

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