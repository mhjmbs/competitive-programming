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
vector<int> po(n+1);
vector<string> a;
char target;

int dfs(int i, int l, int r) {
    if(i == n) {
        return max(0, int(2 - count(a[i].begin()+l, a[i].begin()+r+1, target)));
    }

    vector<int> options;

    for(int j = l; j <= r; j++) {
        options.push_back( dfs(i+1, j*3, j*3+2) );
    }

    sort(options.begin(), options.end());
    
    if(i == 0) return options[0];
    return options[0] + options[1];
}

int main() {
    fastio;

    cin >> n;

    a.resize(n+1);
    cin >> a[n];

    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j < a[i+1].size(); j+=3) {
            int ones = count(a[i+1].begin()+j, a[i+1].begin()+j+3, '1');
            if(ones >= 2) a[i].push_back('1');
            else a[i].push_back('0');
        }
    }

    target = (a[0][0] == '1') ? '0' : '1';

    cout << dfs(0,0,0) << '\n';
}