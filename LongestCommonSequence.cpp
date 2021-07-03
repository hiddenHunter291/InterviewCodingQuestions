#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    string a, b;
public:
    vector<vector<int>> dp;
    void getStrings() {
        cout << "String a: " << a << endl;
        cout << "String b: " << b << endl;
    }
    void setStrings(string a, string b) {
        this->a = a;
        this->b = b;
    }
    void printDpVector() {
        for(vector<int> a : dp) {
            for(int b : a) {
                cout << b << " ";
            }
            cout << "\n";
        }
    }
    int recursiveSolution(int len1, int len2) {
        if(len1 >= a.length() || len2 >= b.length()) return 0;
        if(a[len1] == b[len2]) {
            return 1 + recursiveSolution(len1+1, len2+1);
        } else {
            return max(recursiveSolution(len1+1, len2), recursiveSolution(len1, len2+1));
        }
    }
    int dynamicSolution() {
        int len1 = a.length();
        int len2 = b.length();
        dp = vector<vector<int>>(len1+1, vector<int>(len2+1, 0));
        for(int i=1; i<=len1; ++i) {
            for(int j=1; j<=len2; ++j) {
                if(a[i-1] == b[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[len1][len2];
    }

};

int main() {
    Solution s;
    s.setStrings("ABCDGH", "AEDFHR");
    cout << s.recursiveSolution(0, 0) << endl;
    cout << s.dynamicSolution() << endl;
    return 0;
}