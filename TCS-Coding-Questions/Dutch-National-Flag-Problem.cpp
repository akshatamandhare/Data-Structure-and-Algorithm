// Airport security officials have confiscated several item of the passengers at the security check
//     point.All the items have been dumped into a huge box(array)
//         .Each item possesses a certain
//     amount of risk[0, 1, 2]
//         .Here,
//     the risk severity of the items represent an array[] of N number of
//     integer values.The task here is to sort the items based on their levels of risk in the array.The risk
//     values range from 0 to 2. Example : Input : 7->Value of N
//                                             [2, 1, 0, 2, 1, 0, 0, 1, 2, 0]
//                                                 ->Element of arr[0] to arr[N - 1],
//     while input each element is separated by a new line.
//         [1, 0, 2, 0, 1, 0, 2]
//             ->Element of arr[0] to arr[N - 1],
//     while input each element is separated by new line.Output : 0 0 0 1 1 2 2->Element after sorting based on risk severity

#include<iostream>
    using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>arr[i];
    }

    int l=0, m=0, h=n-1;
    while(m<=h){
        if(arr[m]==0){
            swap(arr[l], arr[m]);
            l++;
            m++;
        }
        else if(arr[m]==1){
            m++;
        }
        else{
            swap(arr[m], arr[h]);
            h--;
        }
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

}