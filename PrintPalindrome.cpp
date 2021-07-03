#include<bits/stdc++.h>
using namespace std;

void PrintPalindrome(int low, int high, string str) {
    for(int i=low; i<=high; ++i) {
        cout << str[i];
    }
    cout << "\n";
    return;
}
int main() {
    string str;
    cin >> str;
    vector<vector<bool>> trueGrid(str.length(), vector<bool>(str.length(), true));
    for(int i=0; i<str.length(); ++i) {
        trueGrid[i][i] = true;
    }
    for(int i=2; i<=str.length(); ++i) {
        for(int j=0; j<=str.length()-1; j++) {
            int low = j;
            int high = j+i-1;
            if(str[low] == str[high] && trueGrid[low+1][high-1]) {
                PrintPalindrome(low, high, str);
                trueGrid[low][high] = true;
            } else {
                trueGrid[low][high] = false;
            }
        }
    }
}