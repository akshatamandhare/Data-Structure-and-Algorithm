#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    // Write your logic here
    int n=prices.size();
    int min_buy = prices[0];
    int max_profit = 0 ;
    for (int i=0; i<n; i++){
        max_profit = max(max_profit, prices[i]-min_buy);
        min_buy=min(prices[i], min_buy);
    }
    return max_profit;
}

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);

    for(int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    cout << maxProfit(prices);

    return 0;
}