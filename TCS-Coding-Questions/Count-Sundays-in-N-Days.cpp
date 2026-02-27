#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of days: ";
    cin>>n;
    string start_day;
    cout<<"Enter the starting day of the week: ";
    cin>>start_day;
    int count=0;
    map<string, int> day_map;
    day_map["Monday"]=0;
    day_map["Tuesday"]=1;
    day_map["Wednesday"]=2;
    day_map["Thursday"]=3;
    day_map["Friday"]=4;
    day_map["Saturday"]=5;
    day_map["Sunday"]=6;
    int day_to_sunday=(7-day_map[start_day]+day_map["Sunday"])%7;
    if(day_to_sunday<n){
        count++;
        int remaining_days = n - day_to_sunday - 1;
        count += remaining_days / 7;
    }
    else{
        count=0;
    }
    

    cout<<"Number of Sundays in "<<n<<" days: "<<count;
    return 0;
}