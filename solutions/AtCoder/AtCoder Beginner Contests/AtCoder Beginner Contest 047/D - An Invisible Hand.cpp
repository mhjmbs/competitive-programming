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

    int n, t;
    cin >> n >> t;

    if(t % 2 == 1) t--;

    vector<ll> a(n+1, 0);
    for(int i = 1; i <= n; i++) cin >> a[i];

    map<ll,ll> freq, numOfWays;
    freq[a[1]] = 1;

    for(int i = 2; i <= n; i++) {
        ll best = a[i] * t/2 - freq.begin()->first * t/2;
        numOfWays[best] += freq.begin()->second;
        freq[a[i]]++;
    }

    cout << numOfWays.rbegin()->second << '\n';
}