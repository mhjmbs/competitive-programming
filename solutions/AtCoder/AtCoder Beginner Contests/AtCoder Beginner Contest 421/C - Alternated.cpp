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

ll solve(string s) {
    int n = s.size();
    ll ans = 0;
    int nxt_a = 0, nxt_b = 0;
    
    for(int i = 0; i < n; i++) {
        while(nxt_a < n && s[nxt_a] != 'A') nxt_a++;
        while(nxt_b < n && s[nxt_b] != 'B') nxt_b++;
        if(i%2 == 0) {
            ans += nxt_a-i;
            swap(s[i], s[nxt_a]);
            if(s[nxt_a] == 'B') nxt_b = min(nxt_b, nxt_a);
            nxt_a++;
        }else {
            ans += nxt_b-i;
            swap(s[i], s[nxt_b]);
            if(s[nxt_b] == 'A') nxt_a = min(nxt_a, nxt_b);
            nxt_b++;
        }
    }

    return ans;
}

int main() {
    fastio;

    int n;
    cin >> n;

    string s;
    cin >> s;

    ll ans = solve(s);
    for(char& c : s) c = (c == 'A') ? 'B' : 'A';
    ans = min(ans, solve(s));

    cout << ans << '\n';
}