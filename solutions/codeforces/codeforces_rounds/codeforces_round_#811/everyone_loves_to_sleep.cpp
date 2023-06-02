#include "bits/stdc++.h"

using namespace std;
using pii = pair<int,int>;

int main() {
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        pii v;
        cin >> n >> v.first >> v.second;

        vector<pii> a(n);
        for(pii& alarm : a) cin >> alarm.first >> alarm.second;
        sort(a.begin(), a.end());

        pii w = {-1,-1};

        for(pii alarm : a) {
            if(alarm >= v) {
                w = alarm;
                break;
            }
        }

        if(w.first == -1) {
            w = a[0];
        }

        pii ans;

        if(w >= v) {
            ans.second = w.second - v.second;
            ans.first = w.first - v.first;
            if(ans.second < 0) {
                ans.first--;
                ans.second += 60;
            }
        }else {
            ans.second = w.second - v.second;
            ans.first = 24 - v.first + w.first;
            if(ans.second < 0) {
                ans.first--;
                ans.second += 60;
            }
            if(ans.first == -1) {
                ans.first = 23;
            }
        }

        cout << ans.first << ' ' << ans.second << '\n';
    }
}
