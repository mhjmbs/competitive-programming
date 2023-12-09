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

    while(t--)
    {
        int n, k;
        cin >> n >> k;

        vector<ll> a(n);
        for(ll& ai : a) cin >> ai;
        sort(a.begin(), a.end());

        ll ans;

        if(k == 1)
        {
            ans = a[0];
            for(int i = 1; i < n; i++)
            {
                ans = min(ans, a[i] - a[i-1]);
            }
        }
        else if(k == 2)
        {
            ans = a[0];
            for(int i = 0; i < n; i++)
            {
                for(int j = i+1; j < n; j++)
                {
                    ll target = a[j] - a[i];
                    auto it = upper_bound(a.begin(), a.end(), target);

                    ll an;
                    if(it == a.end()) an = abs(*(it-1) - target);
                    else an = min(abs(*(it-1) - target), abs(*it - target));
                    ans = min({target, an, ans});
                }
            }
        }
        else
        {
            ans = 0;
        }

        cout << ans << '\n';
    }
}