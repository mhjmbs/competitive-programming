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

//000 0
//011 3
//110 5
//101 7

const ll md = 998244353;

ll add(ll a, ll b) {
    ll ans = a+b;
    if(ans < md) return ans;
    return ans - md;
}

int main() {
    fastio;
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int& ai : a) cin >> ai;
    
    vector<vector<ll>> dp(n, vector<ll>(8));
    ll zr, ones;
    ones = (a[0]%2) + (a[1]%2);
    zr = 2-ones;
    vector<ll> cnt(4);
    cnt[(a[0]%2)*2 + (a[1]%2)] = 1;

    for(int i = 2; i < n; i++) {
        for(int msk = 0; msk < 8; msk++) {
            if(msk != 0 && msk != 3 && msk != 5 && msk != 6) continue;
            dp[i][msk] = dp[i-1][msk];
            if((msk&1) != (a[i]&1)) continue;
            int old1 = (msk&6) / 2; // sem primeiro
            int old2 = old1 + 4;
            dp[i][msk] = add(dp[i][msk], dp[i-1][old1]);
            dp[i][msk] = add(dp[i][msk], dp[i-1][old2]);
            dp[i][msk] = add(dp[i][msk], cnt[(msk&6) >> 1]);
        }
        if(a[i] % 2 == 0) {
            cnt[0] = add(cnt[0], zr);
            cnt[2] = add(cnt[2], ones);
            zr++;
        }else {
            cnt[1] = add(cnt[1], zr);
            cnt[3] = add(cnt[3], ones);
            ones++;
        }
    }

    ll ans = 0;
    for(int msk = 0; msk < 8; msk++) {
        ans = add(ans, dp[n-1][msk]);
    }

    cout << ans << '\n';
}