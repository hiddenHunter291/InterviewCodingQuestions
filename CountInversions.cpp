#include<bits/stdc++.h>
using namespace std;

int merge(int arr[], int low, int mid, int high) {
	vector<int> temp;
	int left = low;
	int right = mid + 1;
	int count = 0;
	while(left <= mid && right <= high) {
		if(arr[left] > arr[right]) {
			temp.push_back(arr[right++]);
			count += mid - left + 1;
		} else {
			temp.push_back(arr[left++]);
		}
	}

	while(left <= mid) {
		temp.push_back(arr[left++]);
	}

	while(right <= high) {
		temp.push_back(arr[right++]);
	}

	for(int i = low; i <= high; ++i) {
		arr[i] = temp[i - low];
	}

	return count;
}

int countInversions(int arr[], int low, int high) {
	if(low >= high)
		return 0;
	int mid = (low + high) >> 1;
	int left = countInversions(arr, low, mid);
	int right = countInversions(arr, mid + 1, high);
	int count = merge(arr, low, mid, high);

	return count + right + left;
}

int main() {
	int *arr, n;
	cin >> n;
	arr = new int[n];
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	cout << countInversions(arr, 0, n-1) << "\n";

}