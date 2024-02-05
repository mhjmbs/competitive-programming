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

    string s;
    cin >> s;

    int l = -2, r = -2;

    for(int i = 0; i < s.size()-1; i++) {
        if(s[i] == s[i+1]) {
            l = i;
            r = i+1;
        }
    }

    for(int i = 0; i < s.size()-2; i++) {
        if(s[i] == s[i+2]) {
            l = i;
            r = i+2;
        }
    }


    cout << l+1 << ' ' << r+1 << '\n';
}