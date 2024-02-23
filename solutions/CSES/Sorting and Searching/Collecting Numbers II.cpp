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

    int n, m;
    cin >> n >> m;

    vector<int> x(n+1), indexOf(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
        indexOf[x[i]] = i;
    }

    set<int> rounds;

    for(int i = 1; i <= n; i++) {
        if(rounds.count(x[i]-1) > 0) {
            rounds.erase(x[i]-1);
        }
        rounds.insert(x[i]);
    }

    int ans = rounds.size();

    while(m--) {
        int a, b;
        cin >> a >> b;

        if(x[a] != n && a < indexOf[x[a]+1] && b >= indexOf[x[a]+1]) ans++;
        if(x[a] != n && a > indexOf[x[a]+1] && b <= indexOf[x[a]+1]) ans--;
        if(x[a] != 1 && a > indexOf[x[a]-1] && b <= indexOf[x[a]-1]) ans++;
        if(x[a] != 1 && a < indexOf[x[a]-1] && b >= indexOf[x[a]-1]) ans--;

        if(x[b] != n && b < indexOf[x[b]+1] && a > indexOf[x[b]+1]) ans++;
        if(x[b] != n && b > indexOf[x[b]+1] && a < indexOf[x[b]+1]) ans--;
        if(x[b] != 1 && b > indexOf[x[b]-1] && a < indexOf[x[b]-1]) ans++;
        if(x[b] != 1 && b < indexOf[x[b]-1] && a > indexOf[x[b]-1]) ans--;

        swap(x[a],x[b]);
        swap(indexOf[x[a]], indexOf[x[b]]);

        cout << ans << '\n';
    }
}