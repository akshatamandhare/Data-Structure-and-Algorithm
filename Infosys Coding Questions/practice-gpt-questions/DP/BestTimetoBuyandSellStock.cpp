
#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n=prices.size();
    int minPrice = prices[0];
    int profit = 0;

    for(int i=1; i<n; i++){
        int cost=prices[i]-minPrice;
        profit = max(profit, cost);
        minPrice = min(minPrice, prices[i]); //dp
    }

    return profit;
}

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    cout << maxProfit(prices) << '\n';
    return 0;
}
