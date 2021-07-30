#include<bits/stdc++.h>
using namespace std;


void dfs(int node, vector<vector<pair<int,int>>> graph, vector<bool> &visited, stack<int> &container) {
	visited[node] = true;
	for(pair<int,int> currNode : graph[node]) {
		if(!visited[currNode.first]) {
			dfs(currNode.first, graph, visited, container);
		}
	}
	container.push(node);
}


int main() {
	int n, m, from, to, weight, src;
	cin >> n >> m;		
	vector<vector<pair<int,int>>> graph(n);
	for(int i = 0; i < m; ++i) {
		cin >> from >> to >> weight;
		graph[from].push_back({to, weight});
	}
	vector<bool> visited(n, false);
	stack<int> container;

	for(int node = 0; node < n; ++node) {
		if(!visited[node]) {
			dfs(node, graph, visited, container);
		}
	}

	cin >> src;
	vector<int> distance(n, INT_MAX);
	distance[src] = 0;

	while(!container.empty() && container.top() != src) {
		container.pop();
	}

	while(!container.empty()) {
		int node = container.top();
		for(pair<int,int> currNode : graph[node]) {
			if(distance[node] + currNode.second < distance[currNode.first]) {
				distance[currNode.first] = distance[node] + currNode.second;
			}
		}
		container.pop();
	}

	for(int x : distance) {
		if(x == INT_MAX)
			cout << "-1 ";
		else
			cout << x << " "; 
	}

	return 0;
}