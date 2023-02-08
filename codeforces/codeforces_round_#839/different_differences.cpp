#include "bits/stdc++.h"

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int k, n;
        cin >> k >> n;

        set<int> notused;
        for(int i = 1; i <= n; i++) notused.insert(i);
        vector<int> ans(k, -1);

        for(int i = 0, curr = 1, currinc = 1; i < k && curr <= n; i++) {
            if(notused.count(curr) == 1) {
                ans[i] = curr;
                notused.erase(curr);
            }else {
                break;
            }
            curr += currinc;
            currinc++;
        }

        for(int &x : ans) {
            if(x == -1) {
                auto it = notused.end();
                it--;
                x = *it;
                notused.erase(it);
            }
        }

        sort(ans.begin(), ans.end());

        for(int i = 0; i < k; i++) {
            cout << ans[i];
            if(i != k-1) cout << ' ';
            else cout << '\n';
        }
    }
}