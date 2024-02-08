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

    int n;
    cin >> n;

    vector<vector<int>> c(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }

    bool coherent = true;

    int ans = 0;

    set<pii> cuts;

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j || i == k || j == k) continue;
                if(c[i][j] > c[i][k] + c[k][j]) coherent = false;
                else if(c[i][j] == c[i][k] + c[k][j] && cuts.count({i,j}) == 0) {
                    ans++;
                    cuts.emplace(i,j);
                    cuts.emplace(j,i);
                }
            }
        }
    }

    cout << (coherent ? ans : -1) << '\n';
}