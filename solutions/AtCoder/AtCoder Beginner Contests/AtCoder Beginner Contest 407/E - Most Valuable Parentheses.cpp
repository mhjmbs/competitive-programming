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
        
        vector<int> a(2*n);
        for(int& ai : a) cin >> ai;
        
        ll ans = a[2*n-2];
        priority_queue<int, vector<int>, greater<int>> active;
        active.push(a[2*n-2]);

        for(int i = 2*n-4; i >= 0; i-=2) {
            if(active.top() < a[i+1]) {
                ans += a[i+1] - active.top();
                active.pop();
                active.push(a[i+1]);
            }
            active.push(a[i]);
            ans += a[i];
        }

        cout << ans << '\n';
    }
}