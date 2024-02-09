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

    string sa, sb, sc;
    cin >> sa >> sb >> sc;

    int ai = 0, bi = 0, ci = 0;
    char ans;
    char turn = 'a';

    while(true) {
        if(turn == 'a') {
            if(ai == sa.size()) {
                ans = 'A';
                break;
            }
            turn = sa[ai];
            ai++;
        }else if(turn == 'b') {
            if(bi == sb.size()) {
                ans = 'B';
                break;
            }
            turn = sb[bi];
            bi++;
        }else {
            if(ci == sc.size()) {
                ans = 'C';
                break;
            }
            turn = sc[ci];
            ci++;
        }
    }

    cout << ans << '\n';
}