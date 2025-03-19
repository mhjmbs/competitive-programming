#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <random>

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
uniform_int_distribution<int> u(0,2);

int query(int i, int j, int k) {
    cout << "? " << i << ' ' << j << ' ' << k << endl;
    int ans;
    cin >> ans;
    return ans;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        
        vector<int> i = {1,2,3};
        
        while(true) {
            int ni = query(i[0],i[1],i[2]);
            if(ni == 0) break;
            i[u(rng)] = ni;
        }

        cout << "! " << i[0] << ' ' << i[1] << ' ' << i[2] << endl;
    }
}
