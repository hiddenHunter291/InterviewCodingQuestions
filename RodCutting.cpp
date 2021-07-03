#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, maximum;
    cin >> n;
    vector<int> length(n+1, 0);
    vector<int> prices(n+1, 0);
    for(int i=1; i<n; ++i) {
        cin >> prices[i];
    }
    vector<int> dp(n+1, 0);
    for(int i=1; i<=n; ++i) {
        maximum = INT_MIN;
        for(int j=1; j<=i; ++j) {
            maximum = max(maximum, length[i-j] + prices[j]);
        }
        length[i] = maximum;
    }
    for(int a : length) {
        cout << a << " ";
    }
    cout << length[n] << endl;
    return 0;
}