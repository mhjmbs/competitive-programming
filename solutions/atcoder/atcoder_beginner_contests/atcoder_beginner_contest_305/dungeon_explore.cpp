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
vector<bool> vis;

void dfs(int node, int last) {
    vis[node] = true;

    bool check = true;

    while(check) {
        check = false;

        string status;
        cin >> status;

        if(status == "OK" || status == "-1") {
            exit(0);
        }

        int k = stoi(status), next = -1;

        for(int i = 0, adj; i < k; i++) {
            cin >> adj;
            if(!vis[adj]) next = adj;
        }

        if(next != -1) {
            cout << next << endl;
            dfs(next, node);
            check = true;
        }
    }

    cout << last << endl;
}

int main() {

    cin >> n >> m;

    vis.resize(n+1, false);

    dfs(1, 0);
}