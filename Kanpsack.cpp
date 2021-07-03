#include<bits/stdc++.h>
using namespace std;
int main() {
    int knapsackCapacity, noOfItems;
    cin >> noOfItems >> knapsackCapacity;
    vector<int> weights(noOfItems);
    vector<int> values(noOfItems);
    for(int i=0; i<noOfItems; ++i) cin >> weights[i];
    for(int i=0; i<noOfItems; ++i) cin >> values[i];
    vector<vector<int>> dp(noOfItems + 1, vector<int>(knapsackCapacity + 1, 0));

    for(int i=0; i<=noOfItems; ++i) {
        for(int j=0; j<=knapsackCapacity; ++j) {
            if(i == 0 || j == 0) continue;
            if(weights[i-1] > j) {
                dp[i][j] = dp[i][j-1];
                continue;
            }
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-weights[i-1]] + values[i-1]);
        }
    }

    for(vector<int> a : dp) {
        for(int b : a) {
            printf("%4d", b);
        }
        cout << "\n";
    }
    return 0;
}