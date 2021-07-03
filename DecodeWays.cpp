#include<bits/stdc++.h>
using namespace std;
int main() {
	string number;
	cin >> number;
	int length = (int)number.length();
	vector<int> dp(length+1, 0);
	dp[0] = 1;
	dp[1] = number[0] - '0' >= 1 && number[0] - '0' <= 9 ? 1 : 0;
	if(dp[1] == 0) {
		cout << "0" << endl;
		return 0;
	}
	for(int i=2; i<=length; ++i) {
		int first = number[i-1] - '0';
		int second = (number[i-2] - '0') * 10 + first;
		if(first >= 1 && first <= 9) dp[i] += dp[i-1];
		if(second >= 10 && second <= 26) dp[i] += dp[i-2];
	}

	//for(int x : dp) cout << x << " ";
	cout << "\nPossible Combination : " << dp[length] << endl;
	return 0; 
}