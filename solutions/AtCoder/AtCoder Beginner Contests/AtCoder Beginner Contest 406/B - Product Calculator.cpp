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

ll exp(ll a, ll b) {
    ll ans = 1;
    for(int i = 0; i < b; i++) ans *= a;
    return ans;
}

int main() {
    fastio;

    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for(ll& ai : a) cin >> ai;
    
    ll ans = 1, max = exp(10,k)-1;

    for(ll ai : a) {
        if(ai <= max/ans) ans *= ai;
        else ans = 1;
    }

    cout << ans << '\n';
}