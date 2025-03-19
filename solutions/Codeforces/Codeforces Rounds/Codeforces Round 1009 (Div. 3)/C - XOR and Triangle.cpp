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

bool check(ll a, ll b) {
    ll c = a^b;
    return c < a+b && c > b-a && c > a-b;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        ull x;
        cin >> x;

        int i = (1<<__lg(x));

        bool smaller = false;
        
        ull y = 0;

        while(i > 0) {
            if(x&i) {
                if(smaller) y |= i;
                else smaller = true;
            }else {
                y |= i;
            }
            i >>= 1;
        }

        if(check(x,y)) cout << y << '\n';
        else cout << -1 << '\n';
    }
}
