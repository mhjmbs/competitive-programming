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

int cnt = 0;

int query(int l, int r) {
    cnt++;
    assert(cnt <= 30);
    cout << "? " << l << ' ' << r << endl;
    int mex;
    cin >> mex;
    return mex;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n, q;
        cin >> n >> q;
        cnt = 0;

        vector<pii> or_rg(q);
        for(auto& [l,r] : or_rg) cin >> l >> r;

        sort(or_rg.begin(), or_rg.end(), [](pii a, pii b) {
            if(a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        });

        vector<pii> rg;

        for(int i = 0, r = -1; i < q; i++) {
            if(r < or_rg[i].second) {
                rg.push_back(or_rg[i]);
                r = or_rg[i].second;
            }
        }

        q = rg.size();

        int l = 0, r = q-1, ans = -1;

        while(l <= r) {
            int mid = (l+r)/2;

            int ans1 = query(rg[l].first, rg[mid].second);
            int ans2 = query(rg[mid].first, rg[r].second);
            ans = max(ans, min(ans1,ans2));
            if(ans1 > ans2) {
                r = mid-1;
            }else {
                l = mid+1;
            }
        }

        cout << "! " << ans << endl;
    }
}