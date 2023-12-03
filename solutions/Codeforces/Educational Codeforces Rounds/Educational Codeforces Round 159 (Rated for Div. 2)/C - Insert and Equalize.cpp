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
        int n;
        cin >> n;

        vector<ll> a(n);
        for(ll& ai : a)
        {
            cin >> ai;
        }

        if(a.size() == 1)
        {
            cout << "1\n";
            continue;
        }

        sort(a.begin(), a.end());
        int target = a.back();

        int x = 0;
        for(int i = 1; i < a.size(); i++) {
            x = gcd(a[i]-a[i-1], x);
        }

        ll toAdd = target-x;
        for(int i = a.size()-1; i >= 0; i--)
        {
            if(a[i] < toAdd)
            {
                break;
            }
            else if(a[i] == toAdd)
            {
                toAdd -= x;
            }
        }

        a.push_back(toAdd);

        ll ans = 0;
        for(ll ai : a)
        {
            ans += (target-ai)/x;
        }

        cout << ans << '\n';
    }
}