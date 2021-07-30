#include<bits/stdc++.h>
using namespace std;
int main() {
	int *heights, n, answer = INT_MIN;
	stack<int> container;
	cin >> n;
	vector<int> left(n), right(n);
	heights = new int[n];
	for(int i = 0; i < n; ++i) {
		cin >> heights[i];
	}

	right[n-1] = n-1;
	container.push(n-1);
	for(int i = n - 2; i >= 0; --i) {
		while(!container.empty() && heights[container.top()] >= heights[i]) {
			container.pop();
		}
		if(container.empty()) {
			container.push(i);
			right[i] = n-1;
			continue;
		}
		right[i] = container.top() - 1;
		container.push(i);
	}

	while(!container.empty()) {
		container.pop();
	}

	left[0] = 0;
	container.push(0);
	for(int i = 1; i < n; ++i) {
		while(!container.empty() && heights[container.top()] >= heights[i]) {
			container.pop();
		}
		if(container.empty()) {
			container.push(i);
			left[i] = 0;
			continue;
		}
		left[i] = container.top() + 1;
		container.push(i);
	}

	for(int i = 0; i < n; ++i) {
		answer = max(answer, (right[i] - left[i] + 1) * heights[i]);
	}

	cout << "Area of Largest Rectangle: " << answer << endl;
	return 0;
}