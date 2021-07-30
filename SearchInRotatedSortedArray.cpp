#include<bits/stdc++.h>
using namespace std;

bool searchInRotatedSortedArray(int arr[], int target, int end) {
	int left = 0;
	int right = end;
	int first = arr[0];

	while(left <= right) {
		int mid = (left + right) >> 1;
		if(arr[mid] == target)
			return true;
		bool current_block = (first <= arr[mid]) ? true : false;
		bool target_present = (first <= target) ? true : false;
		if(current_block == target_present) {
			if(target > arr[mid]) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		} else {
			if(current_block) {
				left = mid + 1;
			} else {
				right = mid - 1;
			}
		}
	}

	return false;
}

int main() {
	int *arr, n, number;
	cin >> n;
	arr = new int[n];
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	cin >> number;
	cout << searchInRotatedSortedArray(arr, number, n-1) << endl;
	return 0;
}

