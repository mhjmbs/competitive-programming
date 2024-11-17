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

pii query(vector<int>& v) {
    cout << "? " << count(v.begin()+1, v.end(), 1) << ' ';
    for(int i = 1; i < v.size(); i++) {
        if(v[i]) cout << i << ' ';
    }
    cout << endl;
    int m1, m2;
    cin >> m1 >> m2;
    if(m1 > m2) swap(m1,m2);
    return {m1,m2};
}

int solve() {
    int n;
    cin >> n;

    int m1 = n/2, m2 = n/2+1;
    vector<int> q(n+1, 1), d(3,-1), r;

    uniform_int_distribution<int> uid(1,n);
    while(d[1] == -1 && d[2] == -1) {
        d[1] = uid(rng);
        do{
            d[2] = uid(rng);
        }while(d[1] == d[2]);

        q[d[1]] = q[d[2]] = 0;
        auto [c1,c2] = query(q);
        q[d[1]] = q[d[2]] = 1;

        if(c1 != m1 || c2 != m2) d[1] = d[2] = -1;
    }

    fill(q.begin(), q.end(), 0);
    q[d[1]] = q[d[2]] = 1;
    int i = -1, j = 0;

    while(true) {
        while(i <= j || i == d[1] || i == d[2]) i++;
        while(j <= i || j == d[1] || j == d[2]) j++;
        if(j > n) break;

        q[i] = q[j] = 1;
        auto [c1,c2] = query(q);
        q[i] = q[j] = 0;

        if(c1 == m1 && c2 == m2) {
            cout << "! " << i << ' ' << j << endl;
            return 0;
        }else if(m1 == c1 || m1 == c2 || m2 == c1 || m2 == c2) {
            r.push_back(i);
            r.push_back(j);
        }
    }

    for(int i = 0; i < 4; i++) {
        for(int j = i+1; j < 4; j++) {
            q[r[i]] = q[r[j]] = 1;
            auto [c1,c2] = query(q);
            q[r[i]] = q[r[j]] = 0;
            if(c1 == m1 && c2 == m2) {
                cout << "! " << r[i] << ' ' << r[j] << endl;
                return 0;
            }
        }
    }

    return 0;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}