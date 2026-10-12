
#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

pair<int, int> JobScheduling(vector<Job>& jobs) {
    // Write your logic here

}

int main() {
    int n;
    cin >> n;

    vector<Job> jobs(n);

    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id
            >> jobs[i].deadline
            >> jobs[i].profit;
    }

    pair<int, int> ans = JobScheduling(jobs);

    cout << ans.first << " " << ans.second << endl;

    return 0;
}
