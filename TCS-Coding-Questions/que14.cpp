// Problem 2 — The Automobile Factory
// Problem Statement : An automobile company manufactures both two - wheelers(TW) and four - wheelers(FW).The factory manager needs to calculate how many of each type to manufacture based on the following data :

//     V = Total number of vehicles(TW + FW)
//     W = Total number of wheels across all vehicles

//     Using these two values,
//     determine the exact number of two - wheelers and four - wheelers to be manufactured.If the values of V and W do not produce valid positive integer results(i.e., no valid solution exists), print "INVALID INPUT".Constraints : 1 ≤ V ≤ 1000 1 ≤ W ≤ 4000 Input Format : First line → Integer V(total vehicles) Second line → Integer W(total wheels) Output Format : First line → Number of two - wheelers Second line → Number of four - wheelers OR "INVALID INPUT" if no valid solution exists

#include<iostream>
using namespace std;

int main(){
    int v;
    cout<<"No of Vehicles: ";
    cin>>v;
    int w;
    cout<<"No of wheels: ";
    cin>>w;

    int tw;
    int fw;

    if (w < 2 * v || w > 4 * v || w % 2 != 0)
        cout<<"INVALID INPUT";
        return 0;
    if (w % 2 == 0)
        {
            tw = (w - 2 * v) / 2;
            fw = v - tw;
        }

    cout<<"Two wheeler: "<<tw<<endl;
    cout<<"Four Wheeler: "<<fw<<endl;
}