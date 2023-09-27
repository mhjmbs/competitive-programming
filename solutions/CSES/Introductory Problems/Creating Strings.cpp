#include "bits/stdc++.h"

using namespace std;

int n;

void query(string s, vector<int> freq) {
    if(s.size() == n) {
        cout << s << '\n';
    }else {
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) {
                freq[i]--;
                query(s+char('a'+i), freq);
                freq[i]++;
            }
        }
    }
}

int fact(int x) {
    int ans = 1;

    for(int i = 1; i <= x; i++) ans *= i;

    return ans;
}

int main() {
    ios::sync_with_stdio(0);

    string s;
    cin >> s;
    n = s.size();
    vector<int> freq(26,0);

    for(char c : s) freq[c-'a']++;
    
    int ans = fact(n);
    for(int x : freq) ans /= fact(x);
    cout << ans << '\n';
    
    for(int i = 0; i < 26; i++) {
        if(freq[i] > 0) {
            freq[i]--;
            query({char('a'+i)}, freq);
            freq[i]++;
        }
    }
}