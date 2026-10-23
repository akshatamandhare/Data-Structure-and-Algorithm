
#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int day, int last,
                  vector<vector<int>>& points, 
                    vector<vector<int>>& dp) {
    // // Write your recursive logic here
    // int n=points.size();
    // if(day==0){
    //     int maxi=0;
    //     for(int i=0; i<3; i++){
    //         if(i!=last){
    //             int task = points[day][i];
    //             maxi=max(maxi, task);
    //         }
    //     }
    //     return maxi;
    // }

    // int maxi=0;
    // for(int i=0; i<3; i++){
    //     if(i!=last){
    //         int task = points[day][i]+ninjaTraining(day-1, i, points);
    //         maxi = max(maxi, task);
    //     }
    // }
    // return maxi;


    // memo code
    int n=points.size();
    if(day==0){
        int maxi=0;
        for(int i=0; i<3; i++){
            if(i!=last){
                int task = points[day][i];
                maxi=max(maxi, task);
            }
        }
        return dp[day][last] = maxi;
    }

    if(dp[day][last]!=-1) return dp[day][last];
    int maxi=0;
    for(int i=0; i<3; i++){
        if(i!=last){
            int task = points[day][i]+ninjaTraining(day-1, i, points, dp);
            maxi = max(maxi, task);
        }
    }
    return dp[day][last] = maxi;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(3));
    vector<vector<int>>dp(n, vector<int>(n+1, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> points[i][j];
        }
    }

    // // tabulation code
    // dp[0][0] = max(points[0][1], points[0][2]);
    // dp[0][1] = max(points[0][0], points[0][2]);
    // dp[0][2] = max(points[0][0], points[0][1]);
    // dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    // for(int day=1; day<n; day++){
    //     for(int last=0; last<4; last++){
    //         int maxi=0;
    //         dp[day][last]=0;
    //         for(int task=0; task<3; task++){
    //             if(task!=last){
    //                 int rewards = points[day][task]+dp[day-1][task];
    //                 maxi = max(maxi, rewards);
    //             }
    //         }
    //          dp[day][last]= maxi;
    //     }
    // }

    // cout<<dp[n-1][3];

    // Space optimised
    vector<int>prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day=1; day<n; day++){
        vector<int>temp(4, 0);
        for(int last=0; last<4; last++){
            temp[last]=0;
            for(int task=0; task<3; task++){
                if (task != last) {
                    int reward = points[day][task] + prev[task];
                    temp[last] = max(temp[last], reward);
                }
            }
        }
        prev=temp;
    }

    cout<<prev[3]; 

    // cout << ninjaTraining(n - 1, 3, points, dp) << "\n";

    return 0;
}
