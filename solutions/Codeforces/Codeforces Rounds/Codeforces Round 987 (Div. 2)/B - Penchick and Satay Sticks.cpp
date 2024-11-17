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

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> p(n+1);
        for(int i = 1; i <= n; i++) cin >> p[i];

        bool yes = true;

        for(int i = 1; i <= n; i++) {
            if(p[i] == i) continue;
            else if(i+1 <= n && p[i] == i+1 && p[i+1] == i) swap(p[i],p[i+1]);
            else yes = false;
        }

        cout << (yes ? "YES" : "NO") << "\n";
    }
}