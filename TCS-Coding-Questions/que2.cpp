// Jack is always excited about sunday.It is favourite day, when he gets to play all day.And goes to cycling with his friends.So every time when the months starts he counts the number of sundays he will get to enjoy.Considering the month can start with any day, be it Sunday, Monday….Or so on.Count the number of Sunday jack will get within n number of days.Example 1 :

//     Input

//         mon->input String denoting the start of the month.

//     13->input integer denoting the number of days from the start of the month.

//     Output :

//     2->number of days within 13 days.

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