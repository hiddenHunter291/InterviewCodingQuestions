#include<bits/stdc++.h>
using namespace std;
int main() {
	//cout << "hi"; a a 
	string s;
	cin >> s;
	cout << s.length() << endl;
	int a_pointer = 0, b_pointer = 0, max_size = INT_MIN;
	map<char,int> m;
	string temp;
	//cout << "hi";
	while(b_pointer < s.length()) {
		//cout << "hi";
		if(m.find(s[b_pointer]) == m.end()) {
			m.insert(pair<char,int>(s[b_pointer], 1));
			//cout << "hi" << endl;
			if((int)m.size() > max_size) {
				max_size = m.size();
				temp = s.substr(a_pointer, b_pointer-a_pointer+1);
			}
			b_pointer++;
		} else {
			auto it = m.find(s[a_pointer]);
			m.erase(it);
			a_pointer++;
		}
	}
	cout << "Maximum size: " << max_size << endl;
	cout << "String:       " << temp << endl;
	return 0;
}