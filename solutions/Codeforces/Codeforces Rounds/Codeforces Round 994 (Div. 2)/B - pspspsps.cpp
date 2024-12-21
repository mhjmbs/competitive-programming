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

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        bool yes = true;

        if(s[0] == 'p' && s[n-1] == 's') {
            yes = false;
        }

        char c = (s[0] == 'p') ? 'p' : '.';

        for(int i = 1; i < n-1; i++) {
            if(c != '.' && s[i] != '.' && s[i] != c) {
                yes = false;
            }else if(c == '.' && s[i] != '.') {
                c = s[i];
            }
        }

        if(c == 'p' && s[n-1] == 's') yes = false;

        cout << (yes ? "YES" : "NO") << '\n';
    }
}