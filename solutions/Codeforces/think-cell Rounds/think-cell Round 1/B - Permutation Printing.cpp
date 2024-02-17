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
        int n;
        cin >> n;

        vector<int> p(n);

        int curr = 1;
        int last;
        for(int i = 0; i < n; i += 2, curr++) {
            p[i] = curr; 
            last = i;
        }

        if(last == n-1) last--;
        else last++;

        for(int i = last; i >= 0; i-=2, curr++) p[i] = curr;

        for(int i = 0; i < p.size(); i++) {
            cout << p[i] << (i != p.size()-1 ? ' ' : '\n');
        }
    }
}