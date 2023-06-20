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

int n, m;
vector<int> queries;
vector<pii> intervals;

bool check(int m) {
    vector<int> pref(n+1, 0);
    for(int i = 0; i < m; i++) {
        pref[queries[i]] = 1;
    }

    int sum = 0;

    for(int i = 1; i <= n; i++) {
        pref[i] += sum;
        sum = pref[i];
    }

    for(pii interval : intervals) {
        auto [l, r] = interval;
        if(pref[r] - pref[l-1] > (r - l + 1)/2) {
            return true;
        }
    }

    return false;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {

        cin >> n >> m;

        intervals.resize(m);
        for(pii &x : intervals) cin >> x.first >> x.second;

        int q;
        cin >> q;
        
        queries.resize(q);
        for(int &qi : queries) cin >> qi;

        int l = 0, r = q, ans = -1;

        while(l <= r) {
            int mid = (l+r)/2;

            if(check(mid)) {
                ans = mid;
                r = mid-1;
            }else {
                l = mid+1;
            }
        }

        cout << ans << '\n';
    }
}