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

int n;

bool check(vector<vector<int>>& k) {
    bool ok = true;

    for(int i = 0; i < n; i++) {
        for(int j = 1; j < n; j++) {
            ok = ok && k[i][j-1] < k[i][j];
        }
    }

    for(int j = 0; j < n; j++) {
        for(int i = 1; i < n; i++) {
            ok = ok && k[i-1][j] < k[i][j];
        }
    }

    return ok;
}

vector<vector<int>> rotate(vector<vector<int>>& k) {
    vector<vector<int>> k2(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            k2[i][j] = k[j][n-1-i];
        }
    }

    return k2;
}

int main() {
    fastio;

    cin >> n;

    vector<vector<int>> k(n, vector<int>(n));

    for(auto& line : k) {
        for(int& kij : line) cin >> kij;
    }

    int ans = 0;

    while(!check(k)) {
        k = rotate(k);
        ans++;
    }

    cout << ans << '\n';
}