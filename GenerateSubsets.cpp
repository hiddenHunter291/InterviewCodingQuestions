#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n; 
    vector<int> numbers(n);
    for(int i=0; i<n; ++i) {
        cin >> numbers[i];
    }
    vector<int> answer;
    for(int i=0; i<pow(2,n); ++i) {
        for(int j=0; j<n; ++j) {
            if((1 << j) & i) {
                answer.push_back(numbers[j]);
            }
        }
        cout << "[";
        for(int x : answer) {
            cout << x << "";
        }
        cout << "]\n";
        answer.clear();
    }
}