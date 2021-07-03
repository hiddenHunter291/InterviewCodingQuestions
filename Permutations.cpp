#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> answer;
void permutate(vector<int>& nums, int index) {
    if(index == nums.size()-1) {
        answer.push_back(nums);
        return;
    }
    for(int i=index; i<(int)nums.size(); ++i) {
        swap(nums[index], nums[i]);
        permutate(nums,index+1);
        swap(nums[index], nums[i]);
    }
}
void display(vector<vector<int>> answer) {
    for(int row = 0; row < answer.size(); ++row) {
        for(int col = 0; col < answer[0].size(); ++col) {
            cout << answer[row][col] << " ";
        }
        cout << "\n";
    }
    return;
}
int main() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for(int i=0; i<(int)nums.size(); ++i) {
        cin >> nums[i];
    }
    permutate(nums, 0);
    display(answer);
    return 0;
}