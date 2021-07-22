/*
    Problem stattement : 
    Given an undirected graph and a number m, determine if the graph can be coloured with at most m colours such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. 
*/

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> solutions;
bool isOkay(int color, vector<int> nodeColors, vector<int> row) {
    bool answer = true;
    for(int i=0; i<row.size(); ++i) {
        if(nodeColors[row[i]] == color) {
            answer = false;
            break;
        }
    }
    return answer;
}

void display(vector<vector<int>> solutions) {
    for(vector<int> arr : solutions) {
        for(int a : arr) {
            cout << a << " ";
        }
        cout << endl;
    }
}

void dfs(vector<vector<int>>& graph, vector<int>& nodeColors, vector<int>& colors, int index) {
    if(index >= graph.size()) {
        solutions.push_back(nodeColors);
        return;
    }

    for(int i=0; i<colors.size(); ++i) {
        if(isOkay(colors[i], nodeColors, graph[index])) {
            nodeColors[index] = colors[i];
            dfs(graph, nodeColors, colors, index+1);
            nodeColors[index] = -1;
        }
    }
}

int main() {
    int edges, from = 0, to = 0, c;
    cout << "Enter the number of edges: ";
    cin >> edges;
    vector<vector<int>> graph(edges);
    vector<int> nodeColors(edges, -1);
    vector<bool> visited(edges, false);
    cin >> from >> to;
    while(from != -1 && to != -1) {
        graph[from].push_back(to);
        graph[to].push_back(from);   
        cin >> from >> to;                              //because it is an undirected graph
    }
    cout << "Enter the M colors: ";
    cin >> c;
    vector<int> colors(c);
    for(int i=0; i<c; ++i) {
        colors[i] = i;
    }
    dfs(graph, nodeColors, colors, 0);
    display(solutions);
    return 0;
}