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

    string s, t;
    cin >> s >> t;

    bool yes = false;

    int count = 0;

    for(int i = 0; i < s.size(); i++) {
        if(toupper(s[i]) == t[count]) count++;
        if(count == 3) {
            yes = true;
            break;
        }
    }

    if(count == 2 && t[2] == 'X') yes = true;

    cout << (yes ? "Yes\n" : "No\n");
}