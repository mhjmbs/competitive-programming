#include "bits/stdc++.h"

using namespace std;
using pci = pair<char,int>;

int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--) {
        string str;
        cin >> str;

        vector<pci> letters(str.size()-1);
        for(int i = 0; i < str.size()-1; i++) {
            letters[i] = {str[i+1], i+2};
        }

        auto compare = [&str] (pci& pa, pci& pb) {
            char a = pa.first, b = pb.first;
            int ia = pa.second, ib = pb.second;
            if(!(min(str[0], str.back()) <= a && a <= max(str[0], str.back()))) return false;
            if(!(min(str[0], str.back()) <= b && b <= max(str[0], str.back())))return true;
            if(abs(str[0]-a) < abs(str[0]-b)) return true;
            if(abs(str[0]-a) > abs(str[0]-b)) return false;
            return ia < ib;
        };

        sort(letters.begin(), letters.end(), compare);

        int counter = 1;
        bool reached = false;
        for(pci pc : letters) {
            char c = pc.first;
            if(c == str.back()) reached = true;
            else if(reached) break;
            counter++;
        }

        cout << abs(str.back() - str[0]) << ' ' << counter << '\n';
        cout << "1 ";
        for(int i = 0; i < counter-1; i++) {
            cout << letters[i].second;
            if(i != counter-2) cout << ' ';
            else cout << '\n';
        }
    }
}