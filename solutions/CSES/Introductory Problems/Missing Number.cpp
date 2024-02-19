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

    int n;
    cin >> n;

    vector<int> a(n-1);
    for(int&ai : a) cin >> ai;

    sort(a.begin(),a.end());

    int ans = n;

    for(int i = 0; i < n-1; i++) {
        if(a[i] != i+1) {
            ans = i+1;
            break;
        }
    }

    cout << ans << '\n';
}