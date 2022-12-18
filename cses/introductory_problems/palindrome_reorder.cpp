#include "bits/stdc++.h"

using namespace std;

int main() {
    ios::sync_with_stdio(0);

    string s;
    cin >> s;

    bool oddsize = s.size();

    vector<int> freq(26, 0);

    for(char c : s) freq[c-'A']++;
    
    int oddcount = 0;
    char oddchar = ' ';
    for(int i = 0; i < 26; i++) {
        if(freq[i] % 2 == 1) {
            oddcount++;
            oddchar = 'A'+i;
        }
    }

    if(oddcount > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    deque<char> ans;

    if(oddchar != ' ') {
        ans.push_back(oddchar);
        freq[oddchar-'A']--;
    }

    for(int i = 0; i < 26; i++) {
        while(freq[i] != 0) {
            ans.push_back('A'+i);
            ans.push_front('A'+i);
            freq[i] -= 2;
        }
    }

    while(!ans.empty()) {
        cout << ans.front();
        ans.pop_front();
        if(ans.size() == 0) cout << '\n';
    }
}