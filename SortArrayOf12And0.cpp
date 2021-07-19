#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for(int i=0; i<n; ++i) {
        cin >> numbers[i];
    }
    int mid = 0, low = 0, high = n-1;
    while(mid <= high) {
        switch(numbers[mid]) {
            case 0 : 
                swap(numbers[mid], numbers[low]);
                low++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(numbers[mid], numbers[high]);
                high--;
                break;
        }
    }
    for(int a : numbers) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}