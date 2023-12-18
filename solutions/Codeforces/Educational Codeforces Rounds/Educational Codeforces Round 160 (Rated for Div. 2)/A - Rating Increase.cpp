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
        string s;
        cin >> s;

        int aBegin = 0;
        int bBegin = -1;

        for(int i = 1; i < s.size(); i++) {
            if(s[i] != '0') {
                bBegin = i;
                break;
            }
        }

        if(bBegin == -1) {
            cout << -1 << '\n';
            continue;
        }
        
        int a = stoi(s.substr(aBegin, bBegin));
        int b = stoi(s.substr(bBegin, s.size()-bBegin+1));

        if(a < b) {
            cout << a << ' ' << b << '\n';
        }else {
            cout << -1 << '\n';
        }
    }
}