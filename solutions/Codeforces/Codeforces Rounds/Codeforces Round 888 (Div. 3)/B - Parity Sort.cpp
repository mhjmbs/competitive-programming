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

        vector<int> a(n);
        priority_queue<int, vector<int>, greater<int>> pairs, odds;
        
        for(int i = 0, ai; i < n; i++) {
            cin >> ai;
            if(ai % 2 == 0) {
                pairs.push(ai);
                a[i] = 0;
            }else {
                odds.push(ai);
                a[i] = 1;
            }
        }

        for(int i = 0; i < n; i++) {
            if(a[i] == 0) {
                a[i] = pairs.top();
                pairs.pop();
            }else {
                a[i] = odds.top();
                odds.pop();
            }
        }

        bool yes = true;

        for(int i = 1; i < n; i++) {
            if(a[i-1] > a[i]) {
                yes = false;
            }
        }

        if(yes) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }
}