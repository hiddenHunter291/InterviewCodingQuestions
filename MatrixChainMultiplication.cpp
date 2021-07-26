#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; ++i) {
        cin >> nums[i];
    }
    vector<vector<int>> dp(n-1, vector<int>(n-1, 0));
    for(int i=2; i<=n-1; ++i) {
        for(int j=0; j<n-i; ++j) {
            int low = j;
            int high = i+j-1;
            dp[low][high] = min(dp[low+1][high] + (nums[low] * nums[low+1] * nums[high+1]), dp[low][high-1] + (nums[low] * nums[high] * nums[high+1]));
        }
    }
    for(vector<int> arr : dp) {
        for(int a : arr) {
            printf("%3d", a);
        }
        cout << "\n";
    }
    return 0;
}