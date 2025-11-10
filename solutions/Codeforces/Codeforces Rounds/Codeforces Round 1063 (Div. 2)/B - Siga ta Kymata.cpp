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

void apply_op(string& s, const vector<int>& p, int l, int r) {
    for(int i = l+1; i < r; i++) {
        if(min(p[l],p[r]) < p[i] && p[i] < max(p[l],p[r])) {
            s[i] = '1';
        }
    }
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for(int& pi : p) cin >> pi;
        
        string s(n,'0'), x;
        cin >> x;

        int p1 = find(p.begin(), p.end(), 1) - p.begin() + 1;
        int pn = find(p.begin(), p.end(), n) - p.begin() + 1;
    
        vector<pii> ans = {
            {1,p1},
            {1,pn},
            {p1,n},
            {pn,n},
            {min(p1,pn),max(p1,pn)}
        };

        for(auto [l,r] : ans) apply_op(s, p, l-1, r-1);

        bool yes = true;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0' && x[i] == '1') yes = false;
        }

        if(yes) {
            cout << 5 << '\n';
            for(auto op : ans) {
                cout << op.first << ' ' << op.second << '\n';
            }
        }else {
            cout << -1 << '\n';
        }
    }
}