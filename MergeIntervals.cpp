#include<bits/stdc++.h>
using namespace std;

static bool compare(const pair<int,int> &A, const pair<int,int> &B) {
	return A.second < B.second;
}

int main() {
	vector<pair<int,int>> intervals;
	vector<pair<int,int>> answer;
	int n, index = 0, from, to;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> from >> to;
		intervals.push_back({from, to});
	}
	sort(intervals.begin(), intervals.end(), compare);
	
	while(index < n) {
		if(!answer.empty() && answer.back().second >= intervals[index].first && answer.back().first >= intervals[index].first) {
			answer.pop_back();
		} else if(!answer.empty() && answer.back().second >= intervals[index].first) {
			int start = answer.back().first;
			int end = intervals[index].second;
			answer.pop_back();
			answer.push_back({start, end});
			index++;
		} else {
			answer.push_back({intervals[index].first, intervals[index].second});
			index++;
		}
	}

	for(pair<int,int> curr : answer) {
		cout << "[" << curr.first << "," << curr.second << "] "; 
	}
	return 0;
}