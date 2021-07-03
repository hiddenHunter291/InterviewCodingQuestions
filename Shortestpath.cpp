#include<bits/stdc++.h>
using namespace std;
int min_distance = INT_MAX;
void dfs(int i, int j, int steps, vector<vector<int>> grid, vector<vector<bool>> visited) {
    if(i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0) return;
    if(grid[i][j] == 0 || visited[i][j]) return;
    if(grid[i][j] == 9) {
        min_distance = min(steps, min_distance);
        return;
    }
    visited[i][j] = true;
    steps++;
    dfs(i, j+1, steps, grid, visited);  //right
    dfs(i, j-1, steps, grid, visited);  //left
    dfs(i+1, j, steps, grid, visited);   //downwards
    dfs(i-1, j, steps, grid, visited);   //upwards

    visited[i][j] = false;
}
int main() {
    int rows,cols;
    cin >> rows >> cols;
    vector<vector<int>> grid(rows, vector<int>(cols));
    vector<vector<bool>> visited(rows, vector<bool>(cols));
    for(int i=0; i<rows; ++i) {
        for(int j=0; j<cols; ++j) {
            cin >> grid[i][j];
        }
    }
    dfs(0, 0, 0, grid, visited);
    cout << min_distance << endl;
    return 0;
}