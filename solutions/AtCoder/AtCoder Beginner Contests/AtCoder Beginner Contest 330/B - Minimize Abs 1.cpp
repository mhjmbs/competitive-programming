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

    int n, l, r;
    cin >> n >> l >> r;

    for(int i = 0; i < n; i++)
    {
        int ai;
        cin >> ai;

        int xi;
        if(ai <= l)
        {
            xi = l;
        }
        else if(r <= ai)
        {
            xi = r;
        }
        else
        {
            xi = ai;
        }

        cout << xi << (i != n-1 ? ' ' : '\n');
    }
}