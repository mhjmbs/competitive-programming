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
    
    string s;
    cin >> s;

    string t;
    cin >> t;

    bool inv_v = false, inv_h = false, rev = false;

    for(char op : t) {
        if(op == 'v') {
            inv_v = !inv_v;
        }else if(op == 'h'){
            inv_h = !inv_h;
            rev = !rev;
        }else {
            inv_v = !inv_v;
            inv_h = !inv_h;
            rev = !rev;
        }
    }

    if(rev) reverse(s.begin(), s.end());

    vector<int> iv(256), ih(256);
    iv['b'] = 'p';
    iv['d'] = 'q';
    iv['p'] = 'b';
    iv['q'] = 'd';
    ih['b'] = 'd';
    ih['d'] = 'b';
    ih['p'] = 'q';
    ih['q'] = 'p';

    for(char& c : s) {
        if(inv_v) c = iv[c];
        if(inv_h) c = ih[c];
    }

    cout << s << '\n';
}
