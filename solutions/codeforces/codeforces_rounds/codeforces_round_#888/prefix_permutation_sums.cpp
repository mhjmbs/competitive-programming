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

        vector<ll> p(n-1);
        for(ll &pi : p) cin >> pi;

        bool yes = false;

        vector<int> occur(n+1, 0), problem;
        bool is_ok = true;

        for(int i = 1; i < n-1; i++) {
            ll curr = p[i] - p[i-1];
            if(curr > n || occur[curr] > 0) {
                problem.push_back(curr);
                is_ok = false;
            }else {
                occur[curr]++;
            }
        }

        vector<int> missing;
        for(int i = 1; i <= n; i++) {
            if(occur[i] == 0) missing.push_back(i);
        }

        if(is_ok) {
            if(missing[0] + missing[1] == p[0] || missing[0] == p[0] || missing[1] == p[0]) {
                yes = true;
            }
        }else if(problem.size() == 1 && missing.size() == 3){
            if(find(missing.begin(), missing.end(), p[0]) != missing.end()) {
                missing.erase(find(missing.begin(), missing.end(), p[0]));
                if(missing[0] + missing[1] == problem[0]) {
                    yes = true;
                }
            }
        }

        if(yes) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }
}