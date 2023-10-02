#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int n, m, i, j, i2, j2, i3, j3;
string d, d2;

void find_bounce() {
    if(d == "UR") {
        if(i-1 < m-j) {
            i3 = 1;
            j3 = j + (i-1);
        }else {
            i3 = i - (m-j);
            j3 = m;
        }
    }else if(d == "UL") {
        if(i-1 < j - 1) {
            i3 = 1;
            j3 = j - (i-1);
        }else {
            i3 = i - (j-1);
            j3 = 1;
        }
    }else if(d == "DR") {
        if(n-i < m-j) {
            i3 = n;
            j3 = j + (n-i);
        }else {
            i3 = i + (m-j);
            j3 = m;
        }
    }else if(d == "DL"){
        if(n-i < j-1) {
            i3 = n;
            j3 = j - (n-i);
        }else {
            i3 = i + (j-1);
            j3 = 1;
        }
    }
}

void find_d2() {
    d2 = d;

    if(i3 == 1 && d[0] == 'U') d2[0] = 'D';
    else if (i3 == n && d[0] == 'D') d2[0] = 'U';

    if(j3 == 1 && d[1] == 'L') d2[1] = 'R';
    else if (j3 == m && d[1] == 'R') d2[1] = 'L';
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        cin >> n >> m >> i >> j >> i2 >> j2 >> d;

        set<pair<pii, string>> bounces;
        int bounce_count = 0;

        while(true) {
            find_bounce();
            find_d2();

            if(min(i,i3) <= i2 && i2 <= max(i,i3)) {
                if(min(j,j3) <= j2 && j2 <= max(j,j3)) {
                    if(abs(i2-i) == abs(j2-j)) {
                        cout << bounce_count << '\n';
                        break;
                    }
                }
            }

            if(bounces.find(make_pair(make_pair(i3,j3),d2)) != bounces.end()) {
                cout << "-1\n";
                break;
            }

            bounces.insert(make_pair(make_pair(i3,j3),d2));

            bounce_count++;
            i = i3;
            j = j3;
            d = d2;
        }
    }
}