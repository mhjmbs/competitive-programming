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

    vector<int> trip(1826+1, false);

    for(int i = 0; i < n; i++) {
        int ai, di;
        cin >> ai >> di;

        for(int j = ai; j <= di; j++) {
            trip[j] = 1;
        }
    }

    bool yes = true;

    for(int i = 1, count = 0; i < trip.size(); i++) {
        count += trip[i];
        if(i-180 > 0) count -= trip[i-180];
        yes = yes && count <= 90;
    }

    cout << (yes ? "Yes\n" : "No\n");
}