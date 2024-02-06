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
        int n, m, k;
        cin >> n >> m >> k;

        set<int> a, b;

        for(int i = 0; i < n; i++) {
            int ai;
            cin >> ai;
            a.insert(ai);
        }

        for(int i = 0; i < m; i++) {
            int bi;
            cin >> bi;
            b.insert(bi);
        }

        int aR = k/2, bR = k/2, anyC = 0;
        bool yes = true;

        for(int i = 1; i <= k; i++) {
            if(a.count(i) == 1 && b.count(i) == 1) anyC++;
            else if(a.count(i) == 1 && aR > 0) aR--;
            else if(b.count(i) == 1 && bR > 0) bR--;
            else yes = false;
        }

        if(!yes) {
            cout << "NO\n";
            continue;
        }

        if(anyC <= aR + bR) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }
}