#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using tiii = tuple<int,int,int>;
using tlll = tuple<ll,ll,ll>;

using ordered_set = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>;



int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n+1);
        for(int i = 1; i <= n; i++) cin >> a[i];

        vector<ll> pref(n+1, 0);
        for(int i = 1; i <= n; i++) pref[i] = pref[i-1] + a[i];

        vector<vector<int>> st(int(log2(n))+1, vector<int>(n+1)), st2(int(log2(n))+1, vector<int>(n+1));

        for(int i = 1; i <= n; i++) st[0][i] = st2[0][i] = a[i];

        for(int i = 1; i <= int(log2(n)); i++) {
            for(int j = 1; j+(1<<i)-1 <= n; j++) {
                st[i][j] = max(st[i-1][j], st[i-1][j+(1<<(i-1))]);
                st2[i][j] = min(st2[i-1][j], st2[i-1][j+(1<<(i-1))]);
            }
        }

        for(int i = 1; i <= n; i++) {
            int l = 1, r = n-i, ansR = INT_MAX;

            while(l <= r) {
                int mid = (l+r)/2;

                ll sum = pref[i+mid] - pref[i];
                int mx = max(st[log2(mid)][i+1], st[log2(mid)][i+mid - (1<<int(log2(mid))) + 1]);
                int mn = min(st2[log2(mid)][i+1], st2[log2(mid)][i+mid - (1<<int(log2(mid))) + 1]);

                bool can = false;
                int time = INT_MAX;

                if(mx == mn && mx > a[i]) {
                    can = true;
                    time = 1;
                }else if(mx != mn && sum > a[i]) {
                    can = true;
                    time = mid;
                }

                if(can) {
                    ansR = time;
                    r = mid-1;
                }else {
                    l = mid+1;
                }
            }

            l = 1, r = i-1;
            int ansL = INT_MAX;

            while(l <= r) {
                int mid = (l+r)/2;

                ll sum = pref[i-1] - pref[i-mid-1];
                int mx = max(st[log2(mid)][i-mid], st[log2(mid)][i-1 - (1<<int(log2(mid))) + 1]);
                int mn = min(st2[log2(mid)][i-mid], st2[log2(mid)][i-1 - (1<<int(log2(mid))) + 1]);

                bool can = false;
                int time = INT_MAX;

                if(mx == mn && mx > a[i]) {
                    can = true;
                    time = 1;
                }else if(mx != mn && sum > a[i]) {
                    can = true;
                    time = mid;
                }

                if(can) {
                    ansL = time;
                    r = mid-1;
                }else {
                    l = mid+1;
                }
            }

            if(ansL == INT_MAX && ansR == INT_MAX) {
                cout << -1 << ' ';
            }else {
                cout << min(ansL, ansR) << ' ';
            }
        }

        cout << '\n';
    }
}