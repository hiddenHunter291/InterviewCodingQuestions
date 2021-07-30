#include<bits/stdc++.h>
using namespace std;
int main() {
	vector<int> nums;
	int n, number, answer;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> number;
		nums.push_back(number);
	}
	vector<int> dp(nums.size(), 0);
	dp[0] = nums[0];
	for(int i = 1; i < n; ++i) {
		answer = INT_MIN;
		for(int j = 0; j < i; ++j) {
			if(nums[j] <= nums[i]) {
				answer = max(answer, dp[j] + nums[i]);
			}
		}
		dp[i] = (answer == INT_MIN) ? 0 : answer;
	}

	answer = INT_MIN;
	for(int a : dp) {
		answer = max(answer, a);
	}
	cout << "Maximum Increasing Subsequence Sum : " << answer << endl;
	return 0;
}