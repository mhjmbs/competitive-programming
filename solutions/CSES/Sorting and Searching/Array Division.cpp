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

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int& ai : a) cin >> ai;

    ll l = *max_element(a.begin(), a.end()), r = 1e15, ans = -1;

    while(l <= r) {
        ll mid = (l+r)/2;

        int count = 1;
        ll sum = 0;

        for(int i = 0; i < n; i++) {
            if(sum+a[i] > mid) {
                sum = 0;
                count++;
            }
            sum += a[i];
        }

        if(count <= k) {
            ans = mid;
            r = mid-1;
        }else {
            l = mid+1;
        }
    }

    cout << ans << '\n';
}