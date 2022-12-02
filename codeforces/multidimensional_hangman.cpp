#include "bits/stdc++.h"

using namespace std;
using psi = pair<string,int>;

int main() {
    ios::sync_with_stdio(0);
    int n, c;
    cin >> n >> c;

    vector<string> words(n);
    map<string, int> wordFreq;

    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }

    for(string str : words) {
        int relIndex;
        for(int i = 0; i < str.size(); i++)
            if(str[i] == '*')
                relIndex = i;
        
        for(int i = 0; i < 26; i++) {
            str[relIndex] = 'a'+i;

            if(wordFreq.count(str) == 1)
                wordFreq[str]++;
            else
                wordFreq[str] = 1;
        }
    }

    psi maxstr = {"", 0};

    for(psi word : wordFreq) {
        if(word.second > maxstr.second)
            maxstr = word;
    }

    cout << maxstr.first << " " << maxstr.second << "\n";
}