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

ll d;

ll f(ll x, ll y)
{
    return abs(x*x + y*y - d);
}

int main() {
    fastio;

    cin >> d;

    ll ans = LONG_LONG_MAX;

    for(int x = 0; x <= 1e6; x++)
    {
        int l = 0, r = 1e12;
        ll currAns = LONG_LONG_MAX;

        while(l <= r)
        {
            int m = (l+r)/2;
            currAns = min(currAns, f(x,m));

            if(f(x, m) < f(x, m+1))
            {
                r = m-1;
            }
            else
            {
                l = m+1;
            }
        }

        ans = min(ans, currAns);
    }
    
    cout << ans << '\n';
}