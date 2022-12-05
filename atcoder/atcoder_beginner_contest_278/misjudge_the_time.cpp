#include "bits/stdc++.h"

using namespace std;
using pii = pair<int,int>;
using ll = long long;

pii confuse(pii t) {
    int h = t.first, m = t.second;
    int nh = (h/10)*10 + m/10;
    int nm = (h%10)*10 + m%10;
    return make_pair(nh, nm);
}

bool check(pii nt) {
    if(0 <= nt.first && nt.first <= 23 && 0 <= nt.second && nt.second <= 59) return true;
    return false;
}

void increment(pii& t) {
    t.second++;
    if(t.second == 60) {
        t.first++;
        t.second = 0;

        if(t.first == 24) t.first = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);

    pii t;
    cin >> t.first >> t.second;

    bool printed = false;

    do {
        pii nt = confuse(t);
        if(check(nt)) {
            cout << t.first << ' ' << t.second << '\n';
            printed = true;
        }else {
            increment(t);
        }
    }while(!printed);
}