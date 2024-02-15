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

    while(t--) {
        int n;
        cin >> n;

        ll sum = 0;
        vector<int> a(n);
        for(int& ai : a) {
            cin >> ai;
            sum += ai;
        }

        ll target = sum/n;

        for(int i = 0; i < n-1; i++) {
            if(a[i] > target) {
                a[i+1] += a[i] - target;
                a[i] -= a[i] - target;
            }
        }

        cout << (all_of(a.begin(), a.end(), [target](int x) {return x == target;}) ? "YES\n" : "NO\n");
    }
}