#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, maxLength;
    cin >> n;
    vector<int> numbers(n);
    for(int i=0; i<n; ++i) {
        cin >> numbers[i];
    }
    vector<int> dp(n, 1);
    for(int i=1; i<n; ++i) {
        maxLength = INT_MIN;
        for(int j=0; j<i; ++j) {
            if(numbers[j] <= numbers[i]) {
                maxLength = max(maxLength, dp[j] + 1);
            }
        }
        dp[i] = maxLength == INT_MIN ? 0 : maxLength;
    }
    for(int x : dp) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}