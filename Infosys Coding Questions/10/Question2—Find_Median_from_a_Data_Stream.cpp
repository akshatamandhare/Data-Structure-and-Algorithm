#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cout<<"Enter No of operations: ";
    cin>>q;

    string operation;
    priority_queue<int>left_max_heap;//max heap
    priority_queue<int, vector<int>, greater<int>>right_min_heap; //minheap;
    float median=0;
    vector<double>output;

    for(int i=0; i<q; i++){
        cin>>operation;
        if(operation=="INSERT"){
            int x;
            cin>>x;

            if(left_max_heap.empty() || x < left_max_heap.top()){
                left_max_heap.push(x);
            }
            else{
                right_min_heap.push(x);
            }

            if(abs((int)left_max_heap.size() - (int)right_min_heap.size()) > 1){
                right_min_heap.push(left_max_heap.top());
                left_max_heap.pop();
            }else if(left_max_heap.size() < right_min_heap.size()){
                left_max_heap.push(right_min_heap.top());
                right_min_heap.pop();
            }
        }
        else if(operation=="GET_MEDIAN"){
            if(left_max_heap.size() == right_min_heap.size()){
                median = (left_max_heap.top()+right_min_heap.top())/2.0;
            }
            else{
                median = left_max_heap.top();
            }
            output.push_back(median);
        }
    }
    for(int i=0; i<output.size(); i++){
        cout<<output[i]<<" "<<endl;
    }
    return 0;
}