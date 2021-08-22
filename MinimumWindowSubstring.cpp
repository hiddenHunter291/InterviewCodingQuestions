#include<bits/stdc++.h>
using namespace std;
int main() {
	string s, t, result = "";
	int answer = INT_MAX;
	cin >> s >> t;
	vector<int> freqT(26, 0);
	vector<int> freqS(26, 0);
	for(char a : t) {
		freqT[a - 'a']++;
	}
	int start = 0, end = 0, count = 0;

	while(end < s.length()) {
		if(count == t.length()) {
			if(answer > end - start) {
				answer = end - start;
				result = s.substr(start, end - start);
			}
			freqS[s[start] - 'a']--;
			if(freqS[s[start] - 'a'] < freqT[s[start] - 'a']) {
				count--;
			}
			start++;
		} else {
			freqS[s[end] - 'a']++;
			if(freqS[s[end] - 'a'] <= freqT[s[end] - 'a']) {
				count++;
			}
			end++;
		}
	}

	while(count == t.length()) {
		if(answer > end - start) {
			answer = end - start;
			result = s.substr(start, end - start);
		}
		freqS[s[start] - 'a']--;
		if(freqS[s[start] - 'a'] < freqT[s[start] - 'a']) {
			count--;
		}
		start++;
	}

	cout << result << endl;
	return 0;
}
