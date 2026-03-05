// Problem Statement : A school maintains marks of students in multiple subjects in a 2D matrix.Each row represents one student.Each column represents one subject.You are given integers N and M followed by N × M integers representing marks.

//                     A student is considered 'Passed' if the average of marks is strictly greater than 50.

//                     Print the total number of students who passed.

//                     Input
//                     Format(TCS Coding Platform Format)

//                         First line contains two space
//     - separated integers : N M

//                            Next N lines contain M space
//                            -
//                            separated integers each.

//                            Output Format

//                            Print a single integer representing the number of students who passed.


#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){

    
        int n, m;
        cin>>n>>m;
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=0; j<m; j++){
                int marks; 
                cin>>marks;
                sum+=marks;
            }
            if(sum/m>50){
                cout<<i<<" Student has passed"<<endl;
            }
            else{
                cout<<i<<" Student has failed"<<endl;
            }
        }
    }
}