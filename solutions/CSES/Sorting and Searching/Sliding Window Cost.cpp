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

    int n, k;
    cin >> n >> k;

    vector<int> x(n);
    for(int& xi : x) cin >> xi;

    multiset<int> g1, g2;
    ll sum1 = 0, sum2 = 0;

    int l = 0, r = -1;

    while(r-l+1 < k) {
        r++;
        g2.insert(x[r]);
        sum2 += x[r];
    }

    while(g2.size() > g1.size()) {
        int curr = *g2.begin();
        g1.insert(curr);
        g2.erase(g2.begin());
        sum2 -= curr;
        sum1 += curr;
    }

    while(r < n) {
        int m = *g1.rbegin();

        cout << m*g1.size() - sum1 + sum2 - m*g2.size() << ' ';

        if(g1.count(x[l])) {
            g1.erase(g1.lower_bound(x[l]));
            sum1 -= x[l];
        }else {
            g2.erase(g2.lower_bound(x[l]));
            sum2 -= x[l];
        }
        l++;
        
        r++;
        if(r == n) continue;

        if(x[r] > m) {
            g2.insert(x[r]);
            sum2 += x[r];
        }else {
            g1.insert(x[r]);
            sum1 += x[r];
        }

        while(g2.size() > g1.size()) {
            int curr = *g2.begin();
            g1.insert(curr);
            g2.erase(g2.lower_bound(curr));
            sum2 -= curr;
            sum1 += curr;
        }

        while(g2.size() < g1.size()-1) {
            int curr = *g1.rbegin();
            g2.insert(curr);
            g1.erase(g1.lower_bound(curr));
            sum2 += curr;
            sum1 -= curr;
        }
    }
    cout << '\n';
}