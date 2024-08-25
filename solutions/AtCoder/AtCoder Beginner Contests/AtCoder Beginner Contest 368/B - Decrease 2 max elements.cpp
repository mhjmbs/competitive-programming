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

    int n;
    cin >> n;

    priority_queue<int> a;

    for(int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        a.push(ai);
    }

    int ans = 0;

    while(a.size() > 1) {
        int a1 = a.top();
        a.pop();
        int a2 = a.top();
        a.pop();
        a1--, a2--;
        if(a1 > 0) a.push(a1);
        if(a2 > 0) a.push(a2);
        ans++;
    }

    cout << ans << '\n';
}