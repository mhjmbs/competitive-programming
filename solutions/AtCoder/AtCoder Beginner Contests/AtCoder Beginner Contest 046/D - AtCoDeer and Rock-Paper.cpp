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

    int score = 0;
    int p = s.size()/2;
    int g = s.size() - p;

    for(char c : s) {
        if(p != 0) {
            score += c == 'g' ? 1 : 0;
            p--;
        }else {
            score += c == 'p' ? -1 : 0;
            g--;
        }
    }

    cout << score << '\n';
}