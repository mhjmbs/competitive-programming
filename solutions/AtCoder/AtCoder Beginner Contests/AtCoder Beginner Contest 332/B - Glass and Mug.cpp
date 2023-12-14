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

    int k, g, m;
    cin >> k >> g >> m;

    int currG = 0, currM = 0;

    while(k--)
    {
        if(currG == g)
        {
            currG = 0;
        }
        else if(currM == 0)
        {
            currM = m;
        }
        else
        {
            if(currM > g - currG)
            {
                currM -= g - currG;
                currG = g;
            }
            else
            {
                currG += currM;
                currM = 0;
            }
        }
    }

    cout << currG << ' ' << currM << '\n';
}