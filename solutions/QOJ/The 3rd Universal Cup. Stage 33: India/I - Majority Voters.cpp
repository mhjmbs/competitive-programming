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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());



int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n, q;
        cin >> n >> q;

        string s;
        cin >> s;

        vector<int> pref(n+1);
        for(int i = 1; i <= n; i++) {
            pref[i] = pref[i-1] + (s[i-1] == 'A' ? 1 : -1);
        }

        priority_queue<pii, vector<pii>, greater<pii>> prioq;
        vector<int> nxgt(n+1, n+1);

        for(int i = 0; i <= n; i++) {
            while(!prioq.empty() && pref[i] > prioq.top().first) {
                auto [sum, j] = prioq.top();
                nxgt[j] = i;
                prioq.pop();
            }
            prioq.emplace(pref[i], i);
        }

        // for(int i = 0; i <= n; i++) cout << nxgt[i] << ' ';
        // cout << '\n';

        vector<int> nxa(n+1, n+1);

        for(int i = 1, l = 0; i <= n; i++) {
            if(s[i-1] == 'A') {
                while(l <= i) {
                    nxa[l] = i;
                    l++;
                }
            }
        }

        // for(int i = 0; i <= n; i++) cout << nxa[i] << ' ';
        // cout << '\n';

        auto a_count = [&pref](int l, int r) {
            if(r < l) return 0;
            return (r-l+1 + pref[r] - pref[l-1])/2;
        };

        auto b_count = [&pref, &a_count](int l, int r) {
            if(r < l) return 0;
            return r-l+1 - a_count(l,r);
        };

        while(q--) {
            int l, r;
            cin >> l >> r;

            int bbl = l-1, bbr = min(nxa[l]-1, r), ans = -1;

            while(bbl <= bbr) {
                int mid = (bbl+bbr)/2;

                int pl = (nxgt[mid] <= r) ? nxgt[mid] : r;
                int a = a_count(mid+1, pl) + a_count(pl+1, r);
                int na = b_count(pl+1, r);
                int needed = max(0, (r-mid)/2 + 1 - a);
                
                if(needed <= na) {
                    ans = needed + (mid-l+1);
                    bbr = mid-1;
                }else {
                    bbl = mid+1;
                }
            }

            cout << ans << '\n';
        }
    }
}