#include<bits/stdc++.h>
using namespace std;
double result(double mid, int n) {
    double answer = 1.0;
    for(int i=0; i<n; ++i) {
        answer *= mid;
    }
    return answer;
}
int main() {
    int number, n;
    cout << "Enter the number: ";
    cin >> number;
    cout << "Enter the nth root: ";
    cin >> n;
    double low = 1, high = number;
    while(high-low > 1e-6) {
        double mid = (low + high)/2;
        if(number > result(mid, n)) {
            low = mid;
        } else {
            high = mid;
        }

    }
    cout << high << endl; 
    return 0;
}