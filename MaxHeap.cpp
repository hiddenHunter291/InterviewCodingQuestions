#include<bits/stdc++.h>
using namespace std;
void heapify(int index, vector<int>& numbers) {
    int left = (2*index) + 1;
    int right = (2*index) + 2;
    int maxIndex = index;
    if(left < numbers.size() && numbers[left] > numbers[maxIndex]) {
        maxIndex = left;
    }
    if(right < numbers.size() && numbers[right] > numbers[maxIndex]) {
        maxIndex = right;
    }
    if(maxIndex != index) {
        swap(numbers[maxIndex], numbers[index]);
        heapify(maxIndex, numbers);
    }

}
int main() {
    vector<int> numbers{7, 8, 3, 2, 1, 9};
     for(int i=(numbers.size()/2)-1; i >= 0; --i) {
        heapify(i, numbers);
    }
    for(int x : numbers) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}