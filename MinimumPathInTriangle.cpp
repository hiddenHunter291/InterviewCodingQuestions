#include<bits/stdc++.h>
using namespace std;
int main() {
	int rows;
	cout << "Enter the size of the triangle" << endl;
	cin >> rows;
	vector<vector<int>> triangle(rows);
	int cols = 1;
	for(int i=0; i<rows; ++i) {
		triangle[i] = vector<int>(cols);
		for(int j=0; j<(int)triangle[i].size(); ++j) {
			cin >> triangle[i][j];
		}
		cols++;
	}
	cols = 1;
	vector<vector<int>> dp(rows);
	for(int i=0; i<rows; ++i) {
		dp[i] = vector<int>(cols);
		cols++;
	}
	for(auto x : triangle) {
		for(auto y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
	dp[0][0] = triangle[0][0];
	for(int i=1; i<rows; ++i) {
		for(int j=0; j<triangle[i].size(); ++j) {
			if(j == 0) {
				dp[i][j] = dp[i-1][j] + triangle[i][j];
				continue;
			}
			if(j == triangle[i-1].size()) {
				dp[i][j] = dp[i-1][j-1] + triangle[i][j];
				continue;
			}
			dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
		}
	}
	cout << "\n\n";
	for(auto x : dp) {
		for(auto y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
	int answer = INT_MAX;
	for(int number : dp[rows-1])
		answer = min(answer, number);
	cout << "\n\nMinimum path required = " << answer << endl;
	return 0;
}