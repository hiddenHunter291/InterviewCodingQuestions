#include<bits/stdc++.h>
using namespace std;
int main() {
        string S;
        cin >> S;
        int size = S.length();
        vector<int> frequency(26);
        for(int i=0; i<size; ++i) {
            frequency[S[i] - 'a']++;
            if(frequency[S[i] - 'a'] > (size+1)/2) {
                cout << " " << endl;
                return 0;
            }
        }
        priority_queue<pair<int,char>> q;
        for(int i=0; i<26; ++i) {
            if(frequency[i] > 0) {
                char ch = i + 'a';
                int count = frequency[i];
                //cout << count << "-->" << ch << endl;
                q.push(pair<int,char>(count, ch));
            }
        }
        char first,second;
        int count_first, count_second;
        string ans = "";
        while(!q.empty()) {
            first = q.top().second;
            count_first = q.top().first;
            q.pop();
            ans += first;
            if(!q.empty()) {
                second = q.top().second;
                count_second = q.top().first;
                q.pop();
                ans += second;
            }
            //cout << ans << endl;
            count_first--;
            count_second--;
            if(count_first > 0) q.push(pair<int,char>(count_first, first));
            if(count_second > 0) q.push(pair<int,char>(count_second, second));
        }
        cout << ans << endl;
        return 0;
}