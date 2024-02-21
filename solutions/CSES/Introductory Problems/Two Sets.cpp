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

    ll n;
    cin >> n;

    if(n*(n+1)/2 % 2 == 1) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    int curr = 1;

    vector<int> group1, group2;

    if((n-3)%4 == 0) {
        group1.push_back(1);
        group1.push_back(2);
        group2.push_back(3);
        curr = 4;
    }

    while(curr <= n) {
        group1.push_back(curr);
        group1.push_back(curr+3);
        group2.push_back(curr+1);
        group2.push_back(curr+2);
        curr += 4;
    }

    cout << group1.size() << '\n';
    for(int x : group1) cout << x << ' ';
    cout << '\n';

    cout << group2.size() << '\n';
    for(int x : group2) cout << x << ' ';
    cout << '\n';
}