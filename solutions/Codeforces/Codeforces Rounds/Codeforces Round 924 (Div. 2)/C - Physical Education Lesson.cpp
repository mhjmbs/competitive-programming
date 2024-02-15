#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio ios::sync_with_stdio(0), cin.tie(nullptr)

using ll = long long;
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
        ll n, x;
        cin >> n >> x;
        n--, x--;

        set<ll> k;

        for(ll div = 1, div2 = n-x; div*div <= n-x; div++, div2 = (n-x)/div) {
            if((n-x) % div != 0) continue;
            if(div % 2 == 0 && x < (n-x)/div + 1) k.insert((n-x)/div + 1);
            if(div2 % 2 == 0 && x < (n-x)/div2 + 1) k.insert((n-x)/div2 + 1);
        }

        for(ll div = 1, div2 = n+x; div*div <= n+x; div++, div2 = (n+x)/div) {
            if((n+x) % div != 0) continue;
            if(div % 2 == 0 && x < (n+x)/div + 1) k.insert((n+x)/div + 1);
            if(div2 % 2 == 0 && x < (n+x)/div2 + 1) k.insert((n+x)/div2 + 1);
        }

        cout << k.size() << '\n';
    }
}