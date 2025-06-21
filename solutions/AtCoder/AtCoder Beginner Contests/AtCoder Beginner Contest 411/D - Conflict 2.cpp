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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());



int main() {
    fastio;

    int n, q;
    cin >> n >> q;

    
    vector<tuple<int,int,string>> queries(q);
    
    for(int i = 0; i < q; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        string s;
        
        if(p1 == 1) {
            p1 = 0;
        } else if(p1 == 2) {
            p1 = -1;
            cin >> s;
        }else {
            p1 = p2;
            p2 = 0;
        }
        queries[i] = {p1,p2,s};
    }
    
    int curr = 0;
    string ans;

    for(int i = q-1; i >= 0; i--) {
        auto [p1,p2,s] = queries[i];
        if(p2 != curr) continue;

        if(!s.empty()) {
            reverse(s.begin(), s.end());
            ans.append(s);
        }else {
            curr = p1;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans << '\n';
}