#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> heights(n);
	vector<int> left(n), right(n);
	for(int i = 0; i < n; ++i) {
		cin >> heights[i];
	}
	stack<int> container;

	for(int i = n - 1; i >= 0; --i) {
		if(container.empty()) {
			container.push(n - 1);
			left[i] = n - 1;
			continue;
		}
		while(!container.empty() && heights[container.top()] >= heights[i]) {
			container.pop();
		}
		if(container.empty()) {
			container.push(i);
			left[i] = n - 1;
		} else {
			left[i] = container.top() - 1;
			container.push(i);
		}
	}

	while(!container.empty())
		container.pop();

	for(int i = 0; i < n; ++i) {
		if(container.empty()) {
			container.push(0);
			right[i] = 0;
			continue;
		}
		while(!container.empty() && heights[container.top()] >= heights[i]) {
			container.pop();
		}
		if(container.empty()) {
			container.push(i);
			right[i] = 0;
		} else {
			right[i] = container.top() + 1;
			container.push(i);
		}
	}

	for(int a : left)
		cout << a << " ";
	cout << endl;
	for(int a : right) 
		cout << a << " ";
	
	return 0;
}