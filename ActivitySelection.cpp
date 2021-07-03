#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int>& a, pair<int,int>& b) {
    return a.second < b.second;
}
int main() {
    int n, maxJobs;
    cin >> n;
    vector<pair<int,int>> time(n);
    for(int i=0; i<n; ++i) {
        cin >> time[i].first >> time[i].second;
    }
    sort(time.begin(), time.end(), compare);
    vector<int> dp(n, 0);
    dp[0] = 1;
    for(int i=1; i<n; ++i) {
        maxJobs = INT_MIN;
        for(int j=0; j<i; ++j) {
            if(time[j].second < time[i].first) {
                maxJobs = max(maxJobs, dp[j] + 1);
            }
        }
        dp[i] = (maxJobs == INT_MIN) ? 0 : maxJobs;
    }
    for(int a : dp) {
        cout << a << " ";
    }
    return 0;
}