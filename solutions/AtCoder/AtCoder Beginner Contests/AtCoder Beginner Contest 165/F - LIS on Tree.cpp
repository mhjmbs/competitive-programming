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

vector<vector<int>> adjacencies;
vector<int> a, ans, minLast; //minDepth(k) = menor ultimo valor para uma sequencia estritamente crescente de k kras 
vector<bool> vis;
int best = 0;

void solve(int node) {
    vis[node] = true;

    int change_i = -1, before = -1, best_diff = 0;

    if(minLast[best] < a[node]) {
        best_diff--;
        best++;
        before = minLast[best];
        change_i = best;
        minLast[best] = a[node];
    }else {
        auto it = lower_bound(minLast.begin(), minLast.begin()+best, a[node]);
        change_i = it-minLast.begin();
        before = *it;
        *it = a[node];
    }

    ans[node] = best;

    for(int adj : adjacencies[node]) {
        if(!vis[adj]) {
            solve(adj);
        }
    }

    if(change_i != -1) {
        best += best_diff;
        minLast[change_i] = before;
    }
}

int main() {
    fastio;

    int N;
    cin >> N;

    a.resize(N+1, INT_MIN);
    for(int i = 1; i <= N; i++) cin >> a[i];

    adjacencies.resize(N+1);
    for(int i = 0, u, v; i < N-1; i++) {
        cin >> u >> v;
        adjacencies[u].push_back(v);
        adjacencies[v].push_back(u);
    }

    ans.resize(N+1, 0);
    vis.resize(N+1, false);

    minLast.resize(N+1, -1);

    solve(1);

    for(int i = 1; i <= N; i++) {
        cout << ans[i] << '\n';
    }
}