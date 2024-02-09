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
        ull a, b, r;
        cin >> a >> b >> r;

        ull x = 0;

        for(int i = 63; i >= 0; i--) {
            if((a&(1LL<<i)) ^ (b&(1LL<<i))) {
                if(b&(1LL<<i)) swap(a,b);
                for(int j = i-1; j >= 0; j--) {
                    if((a&(1LL<<j)) && !(b&(1LL<<j)) && (x | (1LL<<j)) <= r) x |= (1LL<<j);
                }
                break;
            }
        }

        cout << (a^x) - (b^x) << '\n';
    }
}