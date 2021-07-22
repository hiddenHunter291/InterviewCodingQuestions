#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for(int i=0; i<n; ++i) {
        cin >> numbers[i];
    }
    int pref_min = INT_MAX, answer = INT_MIN;
    for(int i=0; i<numbers.size(); ++i) {
        if(pref_min > numbers[i]) {
            pref_min = numbers[i];
            continue;
        } else {
            answer = max(answer, numbers[i] - pref_min);
        }
    }
    cout << answer << " ";
    return 0;
}