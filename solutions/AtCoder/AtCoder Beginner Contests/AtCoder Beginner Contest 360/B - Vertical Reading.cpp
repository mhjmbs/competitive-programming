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

    string s,t;
    cin >> s >> t;

    bool yes = false;

    for(int w = 1; w < s.size(); w++) {
        for(int c = 0; c < w; c++) {
            string result;
            for(int i = 0; i+c < s.size(); i += w) {
                result.push_back(s[i+c]);
            }
            yes = yes || t == result;
        }
    }

    cout << (yes ? "Yes\n" : "No\n");
}