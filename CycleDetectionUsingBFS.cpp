#include<bits/stdc++.h>
using namespace std;

bool bfs(int node, int parent, vector<vector<int>> graph, vector<bool>& visited) {
    queue<pair<int,int>> q;
    q.push({node, parent});
    visited[node] = true;
    while(!q.empty()) {
        int curr = q.front().first;
        int parent = q.front().second;
        for(int a : graph[curr]) {
            if(!visited[a]) {
                q.push({a, curr});
                visited[a] = true;
            } else if(a != parent) {
                return true;
            }
        }
        q.pop();
    }
    return false;
}
int main() {
    int n, m, from, to;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for(int i = 0; i < m; ++i) {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    vector<bool> visited(n, false);
    for(int i = 0; i < n; ++i) {
        if(!visited[i] && bfs(i, -1, graph, visited)) {
            printf("Contains Cycle\n");
            return 0;
        } 
    }
    printf("Doesn't contain cycle\n");
    return 0;
}
