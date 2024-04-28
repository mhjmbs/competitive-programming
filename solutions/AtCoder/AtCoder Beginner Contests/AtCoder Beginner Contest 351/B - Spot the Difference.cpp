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

    vector<string> a(n), b(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }    

    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    pii ans;    

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] != b[i][j]) {
                ans = {i,j};
            }
        }
    }

    cout << ans.first+1 << ' ' << ans.second+1 << '\n';
}
