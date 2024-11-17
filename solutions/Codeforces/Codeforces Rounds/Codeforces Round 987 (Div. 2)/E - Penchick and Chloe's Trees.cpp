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

int n;
vector<vector<int>> c;

int dfs(int node) {
    priority_queue<int, vector<int>, greater<int>> prioq;
    for(int ci : c[node]) {
        prioq.push(dfs(ci));
    }

    while(prioq.size() > 2) {
        int c1 = prioq.top();
        prioq.pop();
        int c2 = prioq.top();
        prioq.pop();

        prioq.push(max(c1,c2)+1);
    }

    while(prioq.size() > 1) prioq.pop();

    int h = prioq.empty() ? 1 : prioq.top()+1;

    return h;
}

int main() {
    fastio;

    int t;
    cin >> t;

    while(t--) {
        cin >> n;

        c.assign(n+1, vector<int>());

        for(int i = 2, pi; i <= n; i++) {
            cin >> pi;
            c[pi].push_back(i);
        }

        cout << dfs(1)-1 << '\n';
    }
}