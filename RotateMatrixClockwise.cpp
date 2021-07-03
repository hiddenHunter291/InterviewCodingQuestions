#include<bits/stdc++.h>
using namespace std;
void dislpayMatrix(vector<vector<int>>& matrix) {
	for(auto x : matrix) {
		for(int y : x) {
			cout << y << " ";
		}
		cout << "\n";
	}
	return;
}
int main() {
	int n;
	cout << " \nEnter the size of matrix" << endl;
	cin >> n;
	vector<vector<int>> matrix(n, vector<int>(n));
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			scanf("%d", &matrix[i][j]);

	cout << "\nBefore reversal\n";

	dislpayMatrix(matrix);

	for(int i=0; i<n; ++i) {
		for(int j=0; j<i; ++j) {
			swap(matrix[i][j], matrix[j][i]);
		}
	}

	for(int i=0; i<n; ++i) {
		for(int j=0; j<n/2; ++j) {
			swap(matrix[i][j], matrix[i][n-1-j]);
		}
	}
	cout << "\nAfter reversal\n";
	dislpayMatrix(matrix);
	return 0;
}