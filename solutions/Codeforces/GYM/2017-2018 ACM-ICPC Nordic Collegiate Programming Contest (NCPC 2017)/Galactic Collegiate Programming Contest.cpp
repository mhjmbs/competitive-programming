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
using ordered_multiset = tree<pii, null_type, less_equal<pii>, rb_tree_tag, tree_order_statistics_node_update>;



int main() {
    fastio;

    int n, m;
    cin >> n >> m;

    vector<pii> team(n+1, {0,0});
    ordered_multiset oms;
    map<pair<int,int>, int> occur;

    for(int i = 1; i <= n; i++)
    {
        oms.insert(team[i]);
        occur[team[i]]++;
    }

    for(int i = 0, t, p; i < m; i++)
    {
        cin >> t >> p;

        oms.erase(oms.upper_bound(team[t]));
        occur[team[t]]--;

        team[t].first++;
        team[t].second -= p;

        oms.insert(team[t]);
        occur[team[t]]++;

        cout << n - (oms.order_of_key(team[1]) + (occur[team[1]]-1)) << '\n';
    }
}